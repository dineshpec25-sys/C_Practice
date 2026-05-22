CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = $(wildcard src/*/*.c)

TARGETS = $(patsubst src/%.c,build/%,$(SRC))

all: $(TARGETS)

build/%: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

run:
	@echo "Usage: make run FILE=folder/program"

	@if [ -n "$(FILE)" ]; then ./build/$(FILE); fi

clean:
	rm -rf build