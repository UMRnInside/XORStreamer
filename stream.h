#ifndef _STREAM_H_
#define _STREAM_H_

#ifndef BUFFERSIZE_STACK
#define BUFFERSIZE_STACK 2048
#endif

#include <stdio.h>
#include <stddef.h>

#include <unistd.h>
#include <string.h>

ssize_t fdStreamEncode(int fdIn, int fdOut, char* key, ssize_t keySize);

#endif /* _STREAM_H_ */
