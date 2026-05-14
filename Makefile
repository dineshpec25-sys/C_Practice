CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = build/corrupted_data_stream
SOURCE = src/strings/corrupted_data_stream.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir -p build
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)