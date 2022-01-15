//����
//C �⺯�� char* strstr(const char* haystack, const char* needle) ���ַ��� haystack �в��ҵ�һ�γ����ַ��� needle ��λ�ã���������ֹ�� '\0'��
//
//����
//������ strstr() ������������
//
//char* strstr(const char* haystack, const char* needle)
//����
//haystack -- Ҫ�������� C �ַ�����
//needle -- �� haystack �ַ�����Ҫ������С�ַ�����
//����ֵ
//�ú��������� haystack �е�һ�γ��� �� needle �ַ�����λ�õ������ַ������δ�ҵ��򷵻� null��


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