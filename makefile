CC = gcc

zenedit: zenedit.c
	$(CC) -o zenedit zenedit.c -Wall -Wextra -pedantic -std=c99

clean:
	rm zenedit
