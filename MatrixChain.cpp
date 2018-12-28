#include<iostream>
using namespace std;
void MatrixChain(int *p, int n, int m[50][50], int s[50][50])
{
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;          //自身相乘次数为0
	for (int r = 2; r <= n; r++)
	for (int i = 1; i <= n; i++)
	{
		int j = i + r - 1;;
		m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];//m[i][i]=0,可以省略，初始值
		s[i][j] = i;
		for (int k = i + 1; k<j; k++)
		{
			int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
			if (t<m[i][j])
			{
				m[i][j] = t;
				s[i][j] = k;
			}
		}
	}
}
int main()
{
	int p[7] = { 30, 35, 15, 5, 10, 20, 25 };
	int m[50][50];
	int s[50][50];
	MatrixChain(p, 6, m, s);
	//for (int i = 1; i < 6; i++)
	cout << m[1][6] <<endl;
	return 0;

}