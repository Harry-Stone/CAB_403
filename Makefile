CC = gcc
CFLAGS = -Wall -pedantic # Show all reasonable warnings

TARGETS = Control Ser

all: $(TARGETS)
	echo "Completed Successfully"

clean:
	for f in $(TARGETS); do rm -f $$f; rm -f $$f.o; done

rebuild: clean all

%.o : %.cleangcc -c $_-Wall -Werror

Control: Control.o
	gcc -o Control Control.o

Ser: Ser.o
	gcc -o Ser Ser.o
