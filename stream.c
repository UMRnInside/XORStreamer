#include "stream.h"
#include "xor.h"
#include "flags.h"

static ssize_t keyOffset_l = 0;

ssize_t fdStreamEncode(int fdIn, int fdOut, char* key, ssize_t keySize, char* buffer, ssize_t bufferSize, int flags)
{
    if (flags & SENC_CLEAROFFSET) keyOffset_l = 0;
    ssize_t keyOffset = (flags & SENC_FLUENT) ? keyOffset_l : 0;
    ssize_t errorCode = 0;

    while (1)
    {
        ssize_t readBufferSize = read(fdIn, buffer, bufferSize);
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

    keyOffset_l = keyOffset;
    return errorCode;
}

