#include <stdio.h>
#pragma warning(disable:4996)
int result[1000][21] = { 0 }, sel[20], cnt = 0;
void f(int x, int dap, int End, int w)
{
	int i, j, k;
	for (i = x; i >= 1; i--)
	{
		if (dap + i < End)
		{
			sel[w] = i;
			f(i, dap + i, End, w + 1);
		}
		else if (dap + i == End)
		{
			sel[w] = i;
			for (j = 0; j <= w; j++)
			{
				result[cnt][j] = sel[j];
			}
			cnt++;
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j, l, n;
	scanf("%d", &n);
	f(n - 1, 0, n, 0);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
	{
		for (j = 0, l = 0; result[i][j]>0; j++)
		{
			l += result[i][j];
			if (l < n) printf("%d+", result[i][j]);
			else printf("%d\n", result[i][j]);
		}
	}
}

