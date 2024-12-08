CC = gcc
CFALGS = -c -Wall

all: example

example: choose.o prog1.o input.o output.o
	$(CC) choose.o prog1.o input.o output.o -o example

choose.o: choose.c
	$(CC) $(CFALGS) choose.c

prog1.o: prog1.c
	$(CC) $(CFALGS) prog1.c

input.o: input.c
	$(CC) $(CFALGS) input.c

output.o: output.c
	$(CC) $(CFALGS) output.c

clean:
	rm -rf *.o example

.PHONY: all clean