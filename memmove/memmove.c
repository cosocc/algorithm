#include <stdio.h>
#include <memory.h>
#include <string.h>
void* memmove1(void* dest, const void* src, size_t n)
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
        while (n--)
            *p1++ = *p2++;
    }
    return p1;
}
char str1[7] = "aabbcc";
int main(int argc, char** argv)
{
    //memcpy 原型     void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
    //memmove原型     void *memmove(void* s1, const void* s2, size_t n);
    //区别一:在于memcpy 关键字 restrict(限定范围的意思)
    //说明:前提假定  s1 和 s2 有重叠   使用memcpy ,有可能成功和失败,将会出现不可预测的结果
    //     使用memmove 则不需要考虑这一层关系
    //区别二:从效率上考虑 memcpy 优于 memmove 在实际C99标准中  memmove 使用了临时指针

    printf("The string: %s\n", str1);
    memcpy(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);

    strcpy_s(str1, sizeof(str1), "aabbcc");   // reset string

    printf("The string: %s\n", str1);
    memmove1(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);
    return 0;
}