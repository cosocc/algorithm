//描述
//C 库函数 char* strstr(const char* haystack, const char* needle) 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
//
//声明
//下面是 strstr() 函数的声明。
//
//char* strstr(const char* haystack, const char* needle)
//参数
//haystack -- 要被检索的 C 字符串。
//needle -- 在 haystack 字符串内要搜索的小字符串。
//返回值
//该函数返回在 haystack 中第一次出现 含 needle 字符串的位置的所有字符，如果未找到则返回 null。


#include <stdio.h>
#include <string.h>

char* strstr1(const char* haystack, const char* needle) {
	// if needle is empty return the full string
	if (!*needle) return (char*)haystack;
	const char* p1;
	const char* p2;
	const char* p1_advance = haystack;
	for (p2 = &needle[1]; *p2; ++p2) {
		p1_advance++; // advance p1_advance M-1 times
	}
	for (p1 = haystack; *p1_advance; p1_advance++) {
		char* p1_old = (char*)p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2) return p1_old;
		p1 = p1_old + 1;
	}
	return NULL;
}

int main(int argc, char** argv)
{
	const char* field_s = "123456576878";
	const char* field_n = "5768";
	char* find_s = strstr1(field_s, field_n);
	printf("%s \n", find_s);

	char* find_s_sys = strstr(field_s, field_n);
	printf("%s \n", find_s_sys);



	return 0;
}