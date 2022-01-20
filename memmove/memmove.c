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
    //memcpy ԭ��     void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
    //memmoveԭ��     void *memmove(void* s1, const void* s2, size_t n);
    //����һ:����memcpy �ؼ��� restrict(�޶���Χ����˼)
    //˵��:ǰ��ٶ�  s1 �� s2 ���ص�   ʹ��memcpy ,�п��ܳɹ���ʧ��,������ֲ���Ԥ��Ľ��
    //     ʹ��memmove ����Ҫ������һ���ϵ
    //�����:��Ч���Ͽ��� memcpy ���� memmove ��ʵ��C99��׼��  memmove ʹ������ʱָ��

    printf("The string: %s\n", str1);
    memcpy(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);

    strcpy_s(str1, sizeof(str1), "aabbcc");   // reset string

    printf("The string: %s\n", str1);
    memmove1(str1 + 2, str1, 4);
    printf("New string: %s\n", str1);
    return 0;
}