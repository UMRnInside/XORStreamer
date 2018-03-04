CC=$(CROSS_COMPILE)gcc

all: xor stream main
	$(CC) $(CFLAGS) xor.o stream.o main.o -o XORStreamer

xor:
	$(CC) $(CFLAGS) -c xor.c

stream:
	$(CC) $(CFLAGS) -c stream.c

main:
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o XORStreamer
