CC = gcc
CFLAGS = -Wall -pedantic # Show all reasonable warnings
LDFLAGS =

all: overseer client
	echo "Completed Successfully"

fib: fibmain.o fib.o

fibmain.o: fibmain.c

fib.o: fib.c

clean:
	rm -f fib *.o

.PHONY: all clean
