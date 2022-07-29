
CFLAGS += -g -Wall -fsanitize=address

all: build

build: test

test: main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f test

.PHONY: all build clean test
