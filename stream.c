#include "stream.h"
#include "xor.h"

ssize_t fdStreamEncode(int fdIn, int fdOut, char* key, ssize_t keySize)
{
    char buffer[BUFFERSIZE_STACK];
    ssize_t keyOffset = 0;
    ssize_t errorCode = 0;
    while (1)
    {
        ssize_t readBufferSize = read(fdIn, buffer, (ssize_t)BUFFERSIZE_STACK);
        // EOF/Error
        if ( readBufferSize <= 0 )
            break;

        keyOffset = xorEncode(buffer, readBufferSize, key, keySize, keyOffset);

        ssize_t writeBufferSize = write(fdOut, buffer, readBufferSize);
        if (writeBufferSize != readBufferSize)
        {
            errorCode = 1;
            break;
        }
    }

    return errorCode;
}
