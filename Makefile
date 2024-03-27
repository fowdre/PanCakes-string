ifeq ($(shell uname),Linux)
    ECHO := echo -e
else ifeq ($(OS),Windows_NT)
    ECHO := echo.
else
    ECHO := echo
endif

MKDIR	=	mkdir -p

DEFAULT 	=	"\033[0m"
BOLD_T  	=	"\033[1m"
DIM_T   	=	"\033[2m"
UNDLN_T 	=	"\033[4m"
RED_C   	=	"\033[31m"
GREEN_C 	=	"\033[32m"
LIGHT_RED	=	"\033[91m"
LIGHT_GREEN	=	"\033[92m"
LIGHT_CYAN	=	"\033[96m"
define success_message
	@$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) \
		"$(1)\n"$(DEFAULT) || $(ECHO) $(BOLD_T)$(RED_C)"[✘] \
		"$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(1)\n"$(DEFAULT)
endef

BUILD_DIR		=	build/
OBJECTS_DIR		=	$(BUILD_DIR)obj/
RES_DIR			=	$(BUILD_DIR)res/
COVERAGE_DIR	=	$(BUILD_DIR)coverage/
PROJECT_DIR		=	project/
SRC_DIR			=	$(PROJECT_DIR)src/

SRC_RAW		= 	main.c
SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_RAW))

OBJ 		= 	$(patsubst $(SRC_DIR)%.c, $(OBJECTS_DIR)%.o, $(SRC))

OBJ-CRIT	=	$(SRC-CRIT:.c=.o)

NAME		=	a.out

INCLUDES	=	-I./$(PROJECT_DIR)include

CFLAGS  	+=	-Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wshadow	  \
				-Wlogical-op -Wredundant-decls -I./include -fno-builtin -g3

TEST_REQUIRED	=	$(SRC_DIR)Adder.c
TEST_SRC		=	test/TestAdder.c $(TEST_REQUIRED)

UNITY_SRC		=	unity/unity.c
UNITY_INCLUDES	=	-I./unity

COVERAGE_EXCLUDE_DIRS	=	unity
COVERAGE_COMPILE_FLAGS	=	-fprofile-arcs -ftest-coverage
GCOVR_FLAGS				=	--exclude unity	\
							-j	\
							--html-theme github.dark-green	\
							--html-details $(COVERAGE_DIR)html/output.html

all: tests_run
	@:

tests_run: $(BUILD_DIR) $(RES_DIR)
	@gcc $(CFLAGS) $(COVERAGE_COMPILE_FLAGS) $(UNITY_INCLUDES) $(INCLUDES) $(UNITY_SRC) $(TEST_SRC) -o $(COVERAGE_DIR)test_exec
	@./$(COVERAGE_DIR)test_exec > $(RES_DIR)trace.txt || true

	@$(ECHO) "\nIGNORED: `grep -s IGNORE: $(RES_DIR)trace.txt | wc -l`"
	@$(ECHO) `grep -s IGNORE $(RES_DIR)trace.txt`
	@$(ECHO) "\nPASSED: `grep -s PASS: $(RES_DIR)trace.txt | wc -l`"
	@$(ECHO) `grep -s PASS $(RES_DIR)trace.txt`
	@$(ECHO) "\nFAILED: `grep -s FAIL: $(RES_DIR)trace.txt | wc -l`"
	@$(ECHO) `grep -s FAIL $(RES_DIR)trace.txt`

coverage: $(COVERAGE_DIR) tests_run
	@echo "test"
	@mkdir -p $(COVERAGE_DIR)html
	@gcovr $(GCOVR_FLAGS)

main: $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS)
	$(call success_message, $(NAME))

debug:
	@gcc $(SRC) -o $(NAME) $(CFLAGS) -g
	$(call success_message, $(NAME))

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && $(ECHO) $(GREEN_C)[OK]  	\
		$(BOLD_T) $< $(DEFAULT) || $(ECHO) $(RED_C)[KO]$(BOLD_T) $< $(DEFAULT)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

$(OBJECTS_DIR):
	$(MKDIR) $(OBJECTS_DIR)

$(RES_DIR):
	$(MKDIR) $(RES_DIR)

$(COVERAGE_DIR):
	$(MKDIR) $(COVERAGE_DIR)

clean:
	@$(RM) -rf $(BUILD_DIR)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(RED_C)		\
		"DELETED: "$(DEFAULT) $(LIGHT_RED)"$(BUILD_DIR)"$(DEFAULT)

re:	clean all

.PRECIOUS: $(OBJ)

.PHONY: all tests_run coverage debug clean fclean re
