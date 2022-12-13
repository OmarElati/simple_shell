# Simple Shell - C programming language

This simple Shell - **Shell** - is a programm that provides an interface for users to get access to the kernel's services. In other words the  **Shell** works as a command interpreter.

This shell is able to run default commands and also some other that have been built in (More info inside the Man Page).

## Usage

The shell takes the commands from the standard input, executes them and gets ready to read another command-line.

As an example you can use the <b>ls</b> command for listing files in the current directory:

```sh
$ ls
AUTHORS    _getline.c     path.c       adv_func.c    hsh            man_1_simple_shell  exec.c
README.md  split.c        base_func.c  more_func.c   more_fun2.c    main.c              simple_shell.h
```

## Manual

We provided a man page in the repository, it can be run like this:

```bash
$man ./man_1_simple_shell
```

and you will se something like this

```sh
SHELL(1)                                                     Shell man page                                                     SHELL(1)
NAME
       hsh - Command line interpreter (shell)
SYNOPSIS
       #include shell.h
       ./hsh -> executes
DESCRIPTION
       hsh is a prorgramm that provides an interface for users to get access to the kernel's services.
INVOCATION
       In order to invoke this shell it is necessary to run the ./hsh command.
```

## Installation

clone the repository into new directory

```bash
$git clone https://github.com/Lazherhedfi/holbertonschool-simple_shell.git
```

compile with the following :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Authors

* Omar Elati <github.com/OmarElati>
* Lazher Hedfi <github.com/Lazherhedfi>
