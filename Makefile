CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LIBS = -lncurses

all: scroll

scroll: main.c display.c input.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

run: scroll
	./scroll

clean:
	rm -f *.o scroll
