#include<iostream>
#include<string.h>
using namespace std;
/*给定两个序列X，Y，当另一个序列Z既是X的子序列也是Y的子序列时，称Z为X,Y的公共子序列。
求一个最长的公共子序列。*/


/*输入两个序列，X，Y，作为输入，输出两个数组c和b，c[i][j]存储Xi和Yj的最长公共子序列的长度，b[i][j]记录c[i][j]的值是由哪一个子问题的解得到的，这在构造最长公共子序列时要用到*/
void LCSLength(int m, int n, char *x,char *y, int **c, int **b)
{
	int i, j;
	for (i = 1; i <= m; i++) c[i][0] = 0;
	for (j = 1; j <= n; j++) c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i-1] == y[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
}

//输出最长公共子序列
void LCS_P(int i, int j, char *x, int **b)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1)
	{
		LCS_P(i - 1, j - 1, x, b);
		cout << x[i-1];
	}
	else if (b[i][j] == 2)
		LCS_P(i - 1, j, x, b);
	else
		LCS_P(i, j - 1, x, b);
}
int main()
{
	char x[] = {"CDABDFJabcde"};
	char y[] = { "BCDFJABcde" };
	int m, n;
	m = strlen(x);
	n = strlen(y);
	int **c = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
		c[i] = new int[n + 1];
	int **b = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
		b[i] = new int[n + 1];
	LCSLength(m, n, x, y, c, b);
	LCS_P(m, n, x, b);
	for (int i = 0; i < m + 1; i++)
		delete[] c[i];
	delete[] c;
	for (int i = 0; i < m + 1; i++)
		delete[] b[i];
	delete[] b;


	
	return 0;

}