CC = gcc #Set c compiler to gcc
FILES = Sorting.c song.c
OUTPUT = Sorting
ARGS = -std=c99 -Wall -ggdb
build: ${FILES}
	$(CC) $(ARGS) -o $(OUTPUT) $(FILES)
