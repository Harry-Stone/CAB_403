CFLAGS = -Wall -pedantic # Show all reasonable warnings

TARGET1 = Ser
TARGET2 = Control

TARGETS = TARGET1 + TARGET2

# all: $(TARGET1)
# 	gcc -o $(TARGET1) $(TARGET1).o $(CFLAGS)
# 	gcc -o $(TARGET2) $(TARGET2).o $(CFLAGS)

$(TARGET1): $(TARGET1).c 
	gcc -o $(TARGET1) $(TARGET1).o $(TARGET1).c $(CFLAGS)

$(TARGET2): $(TARGET2).c 
	gcc -o $(TARGET2) $(TARGET2).o $(TARGET2).c $(CFLAGS)

clean:
	for f in $(TARGETS); do rm -f $$f; rm -f $$f.o; done