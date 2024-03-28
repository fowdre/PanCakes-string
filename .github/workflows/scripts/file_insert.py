import sys


def file_read(file_path: str) -> list:
    with open(file_path, 'r') as f:
        print(f"Opened file \"{file_path}\" for reading 📖")
        return f.readlines()


def file_write(file_path: str, content: list) -> None:
    with open(file_path, 'w') as f:
        print(f"\nOpened file \"{file_path}\" for writing ✏️")
        f.write(''.join(str(line) for line in content))


def run(source_file: str, destination_file: str, start_tag: str, end_tag: str) -> None:
    
    # Open the source file
    src = file_read(source_file)
    # Add a newline character to the last line if it doesn't exist, otherwise
    # the tag will not be on a new line
    if src[-1][-1] != "\n":
        print("Adding missing new line in source file ➕")
        src[-1] += "\n"
    
    # Open the destination file
    dest = file_read(destination_file)
    
    # Find the position of the tag in the destination file
    # Manually adding a newline character to the tag to make sure it is found
    tag_start_line = [i for i, line in enumerate(dest) if line == start_tag + "\n"]
    tag_end_line = [i for i, line in enumerate(dest) if line == end_tag + "\n"]
    
    if len(tag_start_line) == 0 or len(tag_end_line) == 0:
        print("Tags not found")
        exit_failure_emoji()
    
    print(f"\nStart tag found at line {tag_start_line[0]} ✅")
    print(f"End tag found at line {tag_end_line[0]} ✅")
    
    # Delete the content between the tags
    if tag_end_line[0] - tag_start_line[0] != 1:
        print("\nDeleting content between tags 🗑️")
    else:
        print("\nNo content to delete ✅")
    for i in range(tag_end_line[0] - tag_start_line[0] - 1):
        print(f"line {tag_start_line[0]+1+i}\t| \"{dest[tag_start_line[0]+1+i][:-1]}\"")
    del dest[tag_start_line[0]+1:tag_end_line[0]]
    
    # Insert the new content
    print("\nInserting new content 📄")
    for line in src:
        tag_start_line[0] += 1
        print(f"line {tag_start_line[0]}\t| \"{line[:-1]}\"")
        dest.insert(tag_start_line[0], line)
    
    # Write the new content to the destination file
    file_write(sys.argv[2], dest)


def check_args() -> int:
    if (len(sys.argv) != 5):
        print("Usage: python3 file_insert.py <source_file> <destination_file> <start_tag> <end_tag>")
        return 1

    if (sys.argv[1] == sys.argv[2]):
        print("Source and destination files must not be the same")
        return 1

    if (sys.argv[1] == "" or sys.argv[2] == ""):
        print("Source or destination file cannot be empty")
        return 1
    
    return 0


def exit_failure_emoji(emoji: str ="🚨"):
    print(f"Failure {emoji}")
    sys.exit(1)


def main():
    if (check_args() == 1):
        exit_failure_emoji()
    
    run(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])


if __name__ == "__main__":
    main()
