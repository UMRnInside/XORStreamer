#include <stdio.h>
#include <string.h>
#include "xor.h"

char* ofaq="abcdefghijklmnopqrstuvwxyz@A";
char* key="23333";

int main()
{
    char faq[1000];
    strcpy(faq, ofaq);

    printf("Testing...\n%s\n", faq);
    xorEncode(faq, strlen(faq), key, strlen(key), 0);
    printf("%s\n", faq);
    return 0;
}

