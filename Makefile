CC=$(CROSS_COMPILE)gcc
CFLAGS=-O3

all: xor.o stream.o main.o
	$(CC) $(CFLAGS) xor.o stream.o main.o -o XORStreamer

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm *.o XORStreamer
