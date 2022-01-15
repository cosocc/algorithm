#include <stdio.h>
#include <string.h>
const int R = 256; /** ASCII ��ĸ��Ĵ�С��R ���� */
/** ��ϣ��Ĵ�С��ѡ��һ���������������� 16 λ������Χ���������� */
const long Q = 0xfff1;
/*
* @brief ��ϣ����.
*
* @param[in] key ��������ַ���
* @param[int] M �ַ����ĳ���
* @return ����Ϊ M �����ַ����Ĺ�ϣֵ
*/
static long hash(const char key[], const int M) {
	int j;
	long h = 0;
	for (j = 0; j < M; ++j) h = (h * R + key[j]) % Q;
	return h;
}
/*
* @brief �����µ� hash.
** @param[int] h �ö����ַ�������Ӧ�Ĺ�ϣֵ
* @param[in] first ����Ϊ M ���Ӵ��ĵ�һ���ַ�
* @param[in] next ����Ϊ M ���Ӵ�����һ���ַ�
* @param[int] RM R^(M-1) % Q
* @return ��ʼ��λ�� i+1 �� M ���ַ������ַ�������Ӧ�Ĺ�ϣֵ
*/
static long rehash(const long h, const char first, const char next,
	const long RM) {
	long newh = (h + Q - RM * first % Q) % Q;
	newh = (newh * R + next) % Q;
	return newh;
}
/*
* @brief �����ؿ����㷨���ж������ַ����Ƿ����.
*
* @param[in] pattern ģʽ��
* @param[in] substring ԭʼ�ı�����Ϊ M ���Ӵ�
* @return �����ַ�����ͬ������ 1�����򷵻� 0
*/
static int check(const char* pattern, const char substring[]) {
	return 1;
}
/**
* @brief Rabin-Karp �㷨.
*
* @param[in] text �ı�
* @param[in] n �ı��ĳ���
* @param[in] pattern ģʽ��
* @param[in] m ģʽ���ĳ���
* @return �ɹ��򷵻ص�һ��ƥ���λ�ã�ʧ���򷵻�-1
*/
int rabin_karp(const char* text, const char* pattern) {
	int i;
	const int n = strlen(text);
	const int m = strlen(pattern);
	const long pattern_hash = hash(pattern, m);
	long text_hash = hash(text, m);
	int RM = 1;
	for (i = 0; i < m - 1; ++i) RM = (RM * R) % Q;
	for (i = 0; i <= n - m; ++i) {
		if (text_hash == pattern_hash) {
			if (check(pattern, &text[i])) return i;
		}
		text_hash = rehash(text_hash, text[i], text[i + m], RM);
	}
	return -1;
}
int main() {
	const char* text = "HERE IS A SIMPLE EXAMPLE";
	const char* pattern = "EXAMPLE";
	const int pos = rabin_karp(text, pattern);
	printf("%d\n", pos); /* 17 */
	return 0;
}