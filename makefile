CC = gcc
SOURCES = zenedit.c terminal.c input.c output.c
zenedit: $(SOURCES) common_headers.h
	$(CC) -o zenedit $(SOURCES) -Wall -Wextra -pedantic -std=c99
clean:
	rm zenedit
