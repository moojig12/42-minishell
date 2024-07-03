# Built-ins

- [x] echo
- [x] pwd
- [x] cd
- [x] export
- [x] unset
- [x] env
- [x] exit

## Signals

- [x] ctrl + \
- [x] ctrl + d
- [x] ctrl + c

## Redirections

- [x] >
- [x] >>
- [ ] <
- [ ] <<
- [ ] Mixture
## Pipes

- [ ] Regular single pipe
- [ ] Pipe to Pipe
- [ ] Pipe mixed with Redirections
## Case specific

- Tons of memory leak found when inputting an unknown command without args.
- When replace_env fails to work it seems there is a memory leak
- After a blocking command
  ctrl + \\ = sends a quit signal to the program and makes a core dump
  ctrl + C = immediately terminates the program
- After removing $PATH and executing
relative path commands a memory leak is caused
- **TO CHECK** Set the $PATH to a multiple directory value (directory1:directory2) and ensure that directories are checked in order from left to right.
- Operation not permitted error?
- ls | > test.txt Doesn't work due to syntax error
- Various leaks found upon exiting
## Missing

- implement $? + $?
- implement cd -
