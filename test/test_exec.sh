#!/bin/bash

while read line ; do
    echo "command: ${line}"
    echo "command: ${line}" >> test/log_diff.txt
    echo "--------------------"
    echo -e "${line} \n" | bash > test/log/stdout_bash.txt #2> test/log/stderr_bash.txt
    echo "----"
    echo -e "${line} \n" | ./minishell > test/log/stdout_minishell.txt #2> test/log/stderr_minishell.txt
    diff --unified=0 test/log/stdout_bash.txt test/log/stdout_minishell.txt >> test/log_diff.txt
    # diff --unified=0 test/log/stderr_bash.txt test/log/stderr_minishell.txt >> test/log_diff.txt
    echo "----------------------------------------"
    echo "----------------------------------------" >> test/log_diff.txt

done < test/test_commands.txt
