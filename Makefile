CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/io.c src/parser.c src/executor.c
OUT = myshell

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)