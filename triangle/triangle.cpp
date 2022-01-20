//��ӡ�������
#include <queue>
/**
* @brief ��ӡ�������ϵ��.
*
* ���д�ӡ����ʽ (a+b)^n չ��ʽ��ϵ�����������һ��
* ϵ����ͬʱ��������һ�е�ϵ��Ԥ�ȼ���ã���������С�
* �ڸ���ϵ��֮�����һ�� 0��
*
* @param[in] n (a+b)^n
* @return ��
*/
void yanghui_triangle(const int n) 
{
	std::queue<int> q;
	/* Ԥ�ȷ����һ�е� 1 */
	q.push(1);
	for (int i = 0; i <= n; i++)
	{ /* ���д��� */
		int s = 0;
		q.push(s); /* �ڸ��м����һ�� 0*/
		/* ����� i �е� i+2 ��ϵ��������һ�� 0��*/
		for (int j = 0; j < i + 2; j++) 
		{
			int t;
			int tmp;
			t = q.front(); /* ��ȡһ��ϵ�������� t*/
			q.pop();
			tmp = s + t; /* ������һ��ϵ������������ */
			q.push(tmp);
			s = t; /* ��ӡһ��ϵ������ i+2 ���� 0*/
			if (j != i + 1)
			{
				printf("%d  ", s);
			}
		}
		printf("\n");
	}
}

void print_triangle(int a)
{
	int* (*data) = new int* [a];
	for (int i = 0; i < a; ++i)
	{
		data[i] = new int[a];
		for (int j = 0; j < a; ++j)
		{
			data[i][j] = 1;
		}
	}

	for (int i = 1; i < a; i++)
	{
		for (int j = 1; j < i; j++)
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
	}


	for (int i = 0; i < a; i++)
	{
		for (int k = 0; k < 26 - 6 * i / 2; k++)
		{
			printf(" ");
		}

		for (int j = 0; j <= i; j++)
			printf("%6d", data[i][j]);

		printf("\n");
	}

	for (int i = 0; i < a; i++)
		delete[] data[i];
	data = nullptr;
	delete[] data;
}

int main(int argc, char** argv)
{


	yanghui_triangle(9);
	printf("\n \n \n");
	print_triangle(10);
	
	return 0;
}