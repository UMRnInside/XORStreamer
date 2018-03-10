#ifndef _STREAM_H_
#define _STREAM_H_

#include <stdio.h>
#include <stddef.h>

#include <unistd.h>
#include <string.h>

ssize_t fdStreamEncode(int fdIn, int fdOut, char* key, ssize_t keySize, char* buffer, ssize_t bufferSize, int flags);

#endif /* _STREAM_H_ */
