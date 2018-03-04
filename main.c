#include <stdio.h>
#include <unistd.h>

#define BUFFERSIZE_STACK 1024
#define DEFAULT_KEY "23333333"

#include "stream.h"

int fdIn = 0;
int fdOut = 1;

int main(int argc, char** argv)
{
    char* key = NULL;
    if (argc >= 2)
        key = argv[1];
    else
        key = DEFAULT_KEY;
    
    ssize_t errorCode = fdStreamEncode(0, 1, key, strlen(key));
    return (int)errorCode;
}
