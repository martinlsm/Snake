CC = gcc
CFLAGS  = -g -Wall -fsanitize=address,undefined

TARGET = run_ai

all: $(TARGET)

$(TARGET): $(TARGET).c snake.o board.o gui.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c snake.o board.o gui.o -lncurses

clean:
	rm -f $(TARGET) *.o

.PHONY: clean all
