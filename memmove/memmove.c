#include <stdio.h>
#include <memory.h>
#include <string.h>
void* memmove1(void* dest, const void* src, unsigned int n)
{
    char* p1 = dest;
    const char* p2 = src;

    if (p2 < p1) {
        p2 += n;
        p1 += n;
        while (n-- != 0)
            *--p1 = *--p2;
    }
    else {
        while (n-- != 0)
            *p1++ = *p2++;
    }
    return p1;
}

char str1[7] = "aabbcc";
int main(int argc, char** argv)
{

    printf("The string: %s\n", str1);
    memcpy(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);

    strcpy_s(str1, sizeof(str1), "aabbcc");   // reset string

    printf("The string: %s\n", str1);
    memmove1(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);

    return 0;
}