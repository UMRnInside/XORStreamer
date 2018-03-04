#ifndef _XOR_H_
#define _XOR_H_

// ssize_t
#include <stdio.h>
#include <stddef.h>

/*
 * ssize_t xorEncode() allow large keySize
 * It will return proper keyOffset value used in the next call
 * e.g.:
 * int keySize=10, bufferSize=8, keyOffset=0;
 * keyOffset = xorEncode(buffer, bufferSize, key, keySize, keyOffset); // Return 8
 * keyOffset = xorEncode(buffer, bufferSize, key, keySize, keyOffset); // Return 5
 * ...
 */
ssize_t xorEncode(char* buffer, ssize_t bufferSize, char* key, ssize_t keySize, ssize_t keyOffset);

#endif /* _XOR_H_ */
