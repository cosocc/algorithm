#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* @brief 计算部分匹配表，即 next 数组.
*
* @param[in] pattern 模式串
* @param[out] next next 数组
* @return 无
*/
void compute_prefix(const char* pattern, int next[]) {
	int i;
	int j = -1;
	const int m = (int)strlen(pattern);
	next[0] = j;
	for (i = 1; i < m; i++) {
		while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
		if (pattern[i] == pattern[j + 1]) j++;
		next[i] = j;
	}
}
/*
* @brief KMP 算法.
*
* * @param[in] text 文本
* @param[in] pattern 模式串
* @return 成功则返回第一次匹配的位置，失败则返回-1
*/
int kmp(const char* text, const char* pattern)
{
	int i;
	int j = -1;
	const int n = (int)strlen(text);
	const int m = (int)strlen(pattern);
	if (n == 0 && m == 0) return 0; /* "","" */
	if (m == 0) return 0; /* "a","" */
	int* next = (int*)malloc(sizeof(int) * m);
	if (next==NULL)	return -1;	
	compute_prefix(pattern, next);
	for (i = 0; i < n; i++) 
	{
		while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
		if (text[i] == pattern[j + 1]) j++;
		if (j == m - 1) 
		{
			free(next);
			return i - j;
		}
	}
	free(next);
	return -1;
}

int main(int argc, char* argv[]) {
	char text[] = "ABC ABCDAB ABCDABCDABDE";
	char pattern[] = "ABCDAB";
	char* ch = text;
	int i = kmp(text, pattern);
	if (i >= 0) printf("matched @: %s\n", ch + i);
	return 0;
}