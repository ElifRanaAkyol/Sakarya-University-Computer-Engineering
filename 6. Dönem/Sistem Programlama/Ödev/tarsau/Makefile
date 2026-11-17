CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/pack.c src/unpack.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = tarsau

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)