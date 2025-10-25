# get_next_line

Small C utility that reads a file descriptor line by line.
- Returns an allocated string for each call.
- Includes the trailing newline when it's present.
- Returns NULL on EOF or error.

## How it works
- Reads in small chunks (BUFFER_SIZE) into a temporary buffer.
- Accumulates unread data in a static “stash”.
- When a newline is found, it returns everything up to (and including) it.
- Keeps the rest in the stash for the next call.
- Bonus: uses a multi-fd stash array, so multiple FDs can be read sumiltaneously.

## How to run
- To test the code use the commented main in get_next_line.c/get_next_line_bonus.c with 
Mandatory:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c \
   -o gnl_demo
```
Bonus (multi-fd):
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c \
   -o gnl_demo_bonus
```
-BUFFER_SIZE define is user changable via -D to compare the output
