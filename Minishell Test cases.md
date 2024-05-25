# Built-ins

- [x] echo
- [x] pwd
- [ ] cd
- [ ] export
- [ ] unset
- [ ] env
- [x] exit

## Signals

- [x] ctrl + \
- [x] ctrl + d
- [x] ctrl + c

## Redirections

- [ ] >
- [ ] >>
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
- On "ctrl + \" the program segment faults with several leaks
  ![[Pasted image 20240525061727.png]]
- After a blocking command
  ctrl + D = signifies EOF
  ctrl + \\ = sends a quit signal to the program and makes a core dump
  ctrl + C = immediately terminates the program
- After removing $PATH and executing relative path commands a memory leak is caused
- ***TO CHECK*** Set the $PATH to a multiple directory value (directory1:directory2) and ensure that directories are checked in order from left to right.
- Operation not permitted error?
## Missing

- implement $? + $?
