CFLAGS = -Wall -pedantic # Show all reasonable warnings

TARGET1 = Server
TARGET2 = Control

TARGETS = Server Control

# all: $(TARGET1)
# 	gcc -o $(TARGET1) $(TARGET1).o $(CFLAGS)
# 	gcc -o $(TARGET2) $(TARGET2).o $(CFLAGS)
all: $(TARGET1) $(TARGET2)

$(TARGET1): $(TARGET1).c 
	gcc $(TARGET1).c -o $(TARGET1) $(CFLAGS)

$(TARGET2): $(TARGET2).c 
	gcc $(TARGET2).c -o $(TARGET2) $(CFLAGS)

clean:
	@for f in $(TARGETS); do rm -f $$f; rm -f $$f.o; done