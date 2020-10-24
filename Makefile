CC = gcc
CFLAGS = -Wall -pedantic # Show all reasonable warnings

TARGETS = Control ser

all: $(TARGETS)
	echo "Completed Successfully"

clean:
	for f in $(TARGETS); do rm -f $$f; rm -f $$f.o; done

rebuild: clean all

%.o : %.cleangcc -c $_-Wall -Werror

Control: Control.o
	gcc -o Control Control.o

ser: ser.o
	gcc -o ser ser.o
