hello: main.c
	gcc -Wall -Wextra -Werror -o hello main.c && ./hello && rm hello