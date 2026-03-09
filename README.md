# mycat

Simple reimplementation of the Linux cat command using POSIX syscalls.

## Features
- open()
- read()
- write()

## Build
built makefile with debug flag, use make to build

If you don't want debug informatin in file, use:
gcc mycat.c -o mycat

## Usage

./mycat file.txt