#include "xor.h"

ssize_t xorEncode(char* buffer, ssize_t bufferSize, char* key, ssize_t keySize, ssize_t keyOffset)
{
    // Not sure how compiler optimizes these code.
    for (ssize_t i=0;i<bufferSize;i++)
    {
        buffer[i] = buffer[i] ^ key[keyOffset];
        keyOffset = (keyOffset+1 == keySize) ? 0 : keyOffset+1;
    }
    return keyOffset;
}
