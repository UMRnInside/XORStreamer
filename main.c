#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define DEFAULT_KEY "23333333"

#include "stream.h"

int fdIn = 0;
int fdOut = 1;

int verboseFlag = 0;

int main(int argc, char** argv)
{
    char* key = DEFAULT_KEY; 
    ssize_t bufferSize = 4096;
    char outputFileName[FILENAME_MAX];

    int c;
    while (1)
    {
        static struct option longOptions[] = {
            {"verbose", no_argument, &verboseFlag, 1},
            {"output-file", required_argument, 0, 'o'},
            {"buffer-size", required_argument, 0, 'b'},
            {0,0,0,0}
        };

        int optionIndex = 0;
        c = getopt_long(argc, argv, "b:o:", longOptions, &optionIndex);

        // The end of options
        if (c == -1) break;

        switch (c)
        {
            case 'o':
                strcpy(outputFileName, optarg);
                break;
            case 'b':
                bufferSize = strtod(optarg, NULL);
                if (bufferSize <= 0)
                {
                    // Something must be wrong.
                    fprintf(stderr, "error: invalid buffer size : '%s', strtod() returned %d.\n", optarg, bufferSize);
                    return 1;
                }
                break;
            case '?':
                // An error message is printed by getopt
            default:
                return 1;
        }
    }


    char* buffer = (char*)malloc(sizeof(char) * bufferSize);

    ssize_t errorCode = fdStreamEncode(fdIn, fdOut, key, strlen(key), buffer, bufferSize);
    free(buffer);
    return (int)errorCode;
}
