CC = gcc
CFLAGS = -std=c11 -Wall -I src/include
LDFLAGS = -L src/lib
LDLIBS = -lmingw32 -lSDL2main -lSDL2

SRCS = $(wildcard *.c) $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: mpgameboy

mpgameboy: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) mpgameboy.exe
