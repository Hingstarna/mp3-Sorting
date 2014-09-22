CC = gcc #Set c compiler to gcc
FILES = Sorting.c Song.c LinkedList.c #what files to compile
OUTPUT = Sorting #name of compiled program
ARGS = -std=c99  -ggdb #flags for gcc
build: buildall clean
	./Sorting

buildall: Sorting.o
	$(CC) $(ARGS) -o $(OUTPUT) $(FILES)

Sorting.o: Song.o
	$(CC) $(ARGS) -c Sorting.c

song.o: Song.c
	$(cc) $(ARGS) -c song.c

clean:
	rm *.o
