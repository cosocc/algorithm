//����
//ʵ�� atoi����һ���ַ���ת��Ϊ����������ԭ�����£�
//int atoi(const char* str);
//ע�⼸������������
//1. ���������룬������Ч���� - 3924x8fc������ + 413��,
//2. ��Ч��ʽ���� ++c��, ��++1��
//3. ������ݣ���2147483648��

#include <stdio.h>
#include < string.h >
#include <climits>
#include < conio.h >
#include <stdlib.h>


int atoi1(const char* str)
{
	int num = 0;
	int sign = 1;
	const int len = strlen(str);
	int i = 0;
	while (str[i] == ' ' && i < len) i++;
	if (str[i] == '+') i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	for (; i < len; i++) 
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) 
		{
			return sign == -1 ? INT_MIN : INT_MAX;
		}
		num = num * 10 + str[i] - '0';
	}
	return num * sign;
}


int main(int argc, char** argv)
{
	const char* field_s = "-125487";
	int field_i = atoi1(field_s);
	printf("%d \n", field_i);

	int field_ii = atoi(field_s);
	printf("%d \n", field_ii);



	int a = _getch();
	return 0;
}