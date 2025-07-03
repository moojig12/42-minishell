# Minishell

## Overview

Minishell is a simplified implementation of a Unix shell, created as part of the 42 School curriculum. This project involves building a command-line interpreter that mimics the behavior of bash, focusing on process management, file descriptors, and inter-process communication. The goal is to understand how shells work internally and gain hands-on experience with system calls and process control.

## Features

### Core Shell Functionality

- **Interactive prompt** with command line editing and history
- **Command execution** with PATH resolution for executables
- **Quote handling** for single (`'`) and double (`"`) quotes with proper metacharacter interpretation
- **Environment variable expansion** including `$VAR` and `$?` (exit status)
- **Signal handling** for `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` matching bash behavior

### I/O Redirection

- **Input redirection** (`<`) from files
- **Output redirection** (`>`) to files
- **Append redirection** (`>>`) to files
- **Here documents** (`<<`) with delimiter-based input

### Process Management

- **Pipe implementation** (`|`) connecting command output to next command input
- **Process creation and management** using `fork()`, `execve()`, and `wait()`
- **Proper exit status tracking** and propagation

### Built-in Commands

- `echo` with `-n` option
- `cd` with relative and absolute path support
- `pwd` for current directory display
- `export` for environment variable management
- `unset` for environment variable removal
- `env` for environment variable listing
- `exit` for shell termination

## How to Run

### Prerequisites

- Readline library (`brew install readline` on macOS)

### Compilation

```bash
# Clone the repository
git clone https://github.com/moojig12/42-minishell minishell
cd minishell

# Compile the project
make

# Run the shell
./minishell
```

### Usage Examples

```bash
# Basic commands
$> echo "Hello, World!"
Hello, World!

# Environment variables
$> echo $USER
your_username

# Redirections
$> echo "test" > output.txt
$> cat < output.txt
test

# Pipes
$> ls -l | grep minishell
-rwxr-xr-x  1 user  staff  xxxxx minishell

# Built-ins
$> pwd
/current/directory
$> cd ..
$> export MY_VAR=value
$> env | grep MY_VAR
MY_VAR=value
```

## Testing

The project includes comprehensive testing:

- **Test suite** with 120+ test cases covering various shell features
- **Comparison testing** against bash behavior for validation
- **Manual testing** of edge cases and error conditions
- **Memory leak testing** using valgrind (project includes valgrind preferences)

Test files included:

- `test/test_commands.txt` - Comprehensive command test cases
- `test/test_exec.sh` - Automated test execution script
- `test/log/` - Output comparison logs

### Running Tests

```bash
# Run test suite
./test/test_exec.sh

# Compare outputs with bash
diff test/log/stdout_bash.txt test/log/stdout_minishell.txt
```

## Technical Implementation

### Architecture

- **Lexical analysis** for command parsing and tokenization
- **Grammar checking** for syntax validation
- **Execution engine** with pipe and redirection handling
- **Built-in command system** with modular implementation
- **Environment management** with variable expansion
- **Signal handling** with proper cleanup

### Key Learning Outcomes

- **Process management** and inter-process communication
- **File descriptor manipulation** and I/O redirection
- **Signal handling** and process control
- **Memory management** with proper cleanup and leak prevention
- **System call usage** for low-level operations
- **Parser implementation** for command-line interpretation

## Reference

- [Bash Manual](https://www.gnu.org/software/bash/manual/)
- [Advanced Programming in the UNIX Environment](http://www.apuebook.com/)
