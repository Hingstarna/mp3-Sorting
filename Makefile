CC = gcc #Set c compiler to gcc
FILES = Sorting.c Song.c LinkedList.c #what files to compile
OUTPUT = Sorting #name of compiled program
ARGS = -std=c99 -Wall -ggdb #flags for gcc
build: buildall
	./Sorting

buildall: Sorting.o
	$(CC) $(ARGS) -o $(OUTPUT) $(FILES)

Sorting.o: Song.c
	$(CC) $(ARGS) -o $(OUTPUT) Sorting.c

song.o: Song.c
	$(cc) $(ARGS) song.c

clean:
	rm *.o
