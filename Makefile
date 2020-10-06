CC = gcc
CFLAGS = -Wall -pedantic # Show all reasonable warnings

all: job_sched
	echo "Completed Successfully"

job_sched: client.o overseer.o

client.o: client.c

overseer.o: overseer.c

clean:
	rm -f job_sched *.o

.PHONY: all clean
