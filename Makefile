ifeq ($(shell uname),Linux)
    ECHO := echo -e
else ifeq ($(OS),Windows_NT)
    ECHO := echo.
else
    ECHO := echo
endif
ANSI_ESC_START	=	\x1b[
MKDIR	=	mkdir -p

DEFAULT 	=	"$(ANSI_ESC_START)0m"
BOLD_T  	=	"$(ANSI_ESC_START)1m"
DIM_T   	=	"$(ANSI_ESC_START)2m"
UNDLN_T 	=	"$(ANSI_ESC_START)4m"
RED_C   	=	"$(ANSI_ESC_START)31m"
GREEN_C 	=	"$(ANSI_ESC_START)32m"
LIGHT_RED	=	"$(ANSI_ESC_START)91m"
LIGHT_GREEN	=	"$(ANSI_ESC_START)92m"
LIGHT_CYAN	=	"$(ANSI_ESC_START)96m"
ONESHOT_1	=	"$(ANSI_ESC_START)38;2;119;0;173m"	 # rgb(119, 0, 173)
ONESHOT_2	=	"$(ANSI_ESC_START)38;2;230;175;21m" # rgb(230, 175, 21)

SUCCESS_C 	=	$(ONESHOT_2)
FAILURE_C 	=	$(ONESHOT_1)

define success_message
	@$(ECHO) $(BOLD_T)$(SUCCESS_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) \
		"$(1)\n"$(DEFAULT) || $(ECHO) $(BOLD_T)$(FAILURE_C)"[✘] \
		"$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(1)\n"$(DEFAULT)
endef

BUILD_DIR		=	build/
OBJECTS_DIR		=	$(BUILD_DIR)obj/
RES_DIR			=	$(BUILD_DIR)result/
COVERAGE_DIR	=	$(BUILD_DIR)coverage/
PROJECT_DIR		=	project/
SRC_DIR			=	$(PROJECT_DIR)src/

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_RAW))
SRC_RAW		= 	\
				main.c	\
				pkstr_internals.c	\
				pkstr_new.c	\
				pkstr_destroy.c	\
				pkstr_comparison.c	\
				pkstr_search.c	\
				pkstr_simple1.c	\
				pkstr_simple2.c	\
				pkstr_advanced1.c	\
				pkstr_byte1.c	\
				pkstr_byte2.c

OBJ 		= 	$(patsubst $(SRC_DIR)%.c, $(OBJECTS_DIR)%.o, $(SRC))

OBJ-CRIT	=	$(SRC-CRIT:.c=.o)

NAME		=	a.out

INCLUDES	=	-I./$(PROJECT_DIR)include

CFLAGS  	+=	-Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wshadow	  \
				-Wlogical-op -Wredundant-decls -g3

TEST_INCLUDES	=	-I./test/include
TEST_REQUIRED	=	\
					test/utils/test_utils.c	\
					test/utils/test_entrypoint.c	\
					$(SRC_DIR)pkstr_internals.c	\
					$(SRC_DIR)pkstr_new.c	\
					$(SRC_DIR)pkstr_destroy.c	\
					$(SRC_DIR)pkstr_comparison.c	\
					$(SRC_DIR)pkstr_search.c	\
					$(SRC_DIR)pkstr_simple1.c	\
					$(SRC_DIR)pkstr_simple2.c	\
					$(SRC_DIR)pkstr_advanced1.c

TEST_SRC		=	\
					test/Test_pkstr_new.c	\
					test/Test_pkstr_destroy.c	\
					test/Test_pkstr_comparison.c	\
					test/Test_pkstr_search.c	\
					test/Test_pkstr_simple.c	\
					test/Test_pkstr_advanced.c

UNITY_SRC		=	unity/unity.c
UNITY_INCLUDES	=	-I./unity

COVERAGE_EXCLUDE_DIRS	=	unity
COVERAGE_EXCLUDE_FILES	=	$(SRC_DIR)pkstr_internals.c
COVERAGE_COMPILE_FLAGS	=	-fprofile-arcs -ftest-coverage
GCOVR_FLAGS				=	\
							-j	\
							--filter project/	\
							--exclude $(COVERAGE_EXCLUDE_DIRS)	\
							--exclude $(COVERAGE_EXCLUDE_FILES)
GCOVR_HTML_FLAGS		=	\
							--html-details $(COVERAGE_DIR)html/output.html	\
							--html-theme github.dark-green	\
							--html-title "pan<C>akes<🥞> string Code Coverage Report"
GCOVR_XML_FLAGS			=	\
							--cobertura --output $(COVERAGE_DIR)xml/coverage.xml

all: tests_run
	@:

tests_run: $(BUILD_DIR) $(RES_DIR)
	@gcc $(CFLAGS) $(UNITY_INCLUDES) $(TEST_INCLUDES) $(INCLUDES) $(UNITY_SRC) $(TEST_SRC) $(TEST_REQUIRED) -o $(RES_DIR)test_exec
	@./$(RES_DIR)test_exec > $(RES_DIR)trace.txt || true

# @$(ECHO) "\nIGNORED: `grep -s IGNORE $(RES_DIR)trace.txt | wc -l`"
# @$(ECHO) `grep -s IGNORE $(RES_DIR)trace.txt`
	@$(ECHO) "\nPASSED: `grep -s PASS $(RES_DIR)trace.txt | wc -l`"
	@$(ECHO) `grep -s PASS $(RES_DIR)trace.txt`
	@$(ECHO) "\nFAILED: `grep -s FAIL: $(RES_DIR)trace.txt | wc -l`"
	@$(ECHO) `grep -s FAIL $(RES_DIR)trace.txt`

coverage_html:
	@$(RM) -rf $(COVERAGE_DIR)
	@$(MKDIR) $(COVERAGE_DIR)
	@gcc $(CFLAGS) $(COVERAGE_COMPILE_FLAGS) $(UNITY_INCLUDES) $(TEST_INCLUDES) $(INCLUDES) $(UNITY_SRC) $(TEST_SRC) $(TEST_REQUIRED) -o $(COVERAGE_DIR)test_exec
	@./$(COVERAGE_DIR)test_exec > $(COVERAGE_DIR)trace.txt || true
	@mkdir -p $(COVERAGE_DIR)html
	@gcovr -r . $(GCOVR_FLAGS) $(GCOVR_HTML_FLAGS)

coverage_xml:
	@$(RM) -rf $(COVERAGE_DIR)
	@$(MKDIR) $(COVERAGE_DIR)
	@gcc $(CFLAGS) $(COVERAGE_COMPILE_FLAGS) $(UNITY_INCLUDES) $(TEST_INCLUDES) $(INCLUDES) $(UNITY_SRC) $(TEST_SRC) $(TEST_REQUIRED) -o $(COVERAGE_DIR)test_exec
	@./$(COVERAGE_DIR)test_exec > $(COVERAGE_DIR)trace.txt || true
	@mkdir -p $(COVERAGE_DIR)xml
	@gcovr -r . $(GCOVR_FLAGS) $(GCOVR_XML_FLAGS)

main: $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS)
	$(call success_message, $(NAME))

debug:
	@gcc $(SRC) -o $(NAME) $(CFLAGS) -g
	$(call success_message, $(NAME))

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $< && $(ECHO) $(SUCCESS_C)[OK]  	\
		$(BOLD_T) $< $(DEFAULT) || $(ECHO) $(FAILURE_C)[KO]$(BOLD_T) $< $(DEFAULT)

$(BUILD_DIR):
	@$(MKDIR) $(BUILD_DIR)

$(OBJECTS_DIR):
	@$(MKDIR) $(OBJECTS_DIR)

$(RES_DIR):
	@$(MKDIR) $(RES_DIR)

$(COVERAGE_DIR):
	@$(MKDIR) $(COVERAGE_DIR)

clean:
	@$(RM) -rf $(BUILD_DIR)
	@$(ECHO) $(FAILURE_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(FAILURE_C)		\
		"DELETED: "$(DEFAULT) $(LIGHT_RED)"$(BUILD_DIR) directory"$(DEFAULT)
	@$(RM) -rf vgcore.*
	@$(ECHO) $(FAILURE_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(FAILURE_C)		\
		"DELETED: "$(DEFAULT) $(LIGHT_RED)"vgcore files"$(DEFAULT)

re:
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory main

.PHONY: all tests_run coverage debug clean fclean re
