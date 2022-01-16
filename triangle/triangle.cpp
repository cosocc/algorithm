//打印杨辉三角
#include <queue>
/**
* @brief 打印杨辉三角系数.
*
* 分行打印二项式 (a+b)^n 展开式的系数。在输出上一行
* 系数的同时，将其下一行的系数预先计算好，放入队列中。
* 在各行系数之间插入一个 0。
*
* @param[in] n (a+b)^n
* @return 无
*/
void yanghui_triangle(const int n) 
{
	std::queue<int> q;
	/* 预先放入第一行的 1 */
	q.push(1);
	for (int i = 0; i <= n; i++)
	{ /* 逐行处理 */
		int s = 0;
		q.push(s); /* 在各行间插入一个 0*/
		/* 处理第 i 行的 i+2 个系数（包括一个 0）*/
		for (int j = 0; j < i + 2; j++) 
		{
			int t;
			int tmp;
			t = q.front(); /* 读取一个系数，放入 t*/
			q.pop();
			tmp = s + t; /* 计算下一行系数，并进队列 */
			q.push(tmp);
			s = t; /* 打印一个系数，第 i+2 个是 0*/
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