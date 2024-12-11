CC = gcc
CFALGS = -c -Wall

all: example

example: prog1.o input.o output.o sort.o
	$(CC) prog1.o input.o output.o sort.o -o example

prog1.o: prog1.c
	$(CC) $(CFALGS) prog1.c

input.o: input.c
	$(CC) $(CFALGS) input.c

output.o: output.c
	$(CC) $(CFALGS) output.c

sort.o: sort.c
	$(CC) $(CFALGS) sort.c

clean:
	rm -rf *.o example

.PHONY: all clean