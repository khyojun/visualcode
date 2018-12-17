#include <stdio.h>
#include <algorithm>
using namespace std;
int par[10101010];
int n, m;
int find(int x)
{
	if (par[x] == x)
	{
		return par[x];
	}
	return par[x] = find(par[x]);
}
void merg(int x, int y)
{
	int x1 = find(x);
	int yy = find(y);
	if (x1 > yy)
	{
		swap(x1, yy);
	}
	par[yy] = x1;

}
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		merg(x, y);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (find(i) == find(1))
		{
			cnt++;
		}
	}
	printf("%d", cnt-1);
}