CC=$(CROSS_COMPILE)gcc

all: xor stream main
	$(CC) xor.o stream.o main.o -o XORStreamer

xor:
	$(CC) -c xor.c

stream:
	$(CC) -c stream.c

main:
	$(CC) -c main.c

clean:
	rm *.o XORStreamer
