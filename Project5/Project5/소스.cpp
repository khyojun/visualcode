#pragma warning (disable:4996)
#include <stdio.h>
#include <algorithm>
#define INF 1000000
using namespace std;
int n;
int max1=INF*-1;
int s, e, w;
int map[101][101];
void solve()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					map[i][j] = 0;
					continue;
				}
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}



}
void maxi()
{
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			else if (map[i][j] <= 2 && map[i][j]>0)
			{
				cnt++;
			}
		}
		max1 = max(max1, cnt);
	}
}



int main()
{
	char c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &c);
			if (c == 'Y')
			{
				map[i][j] = 1;
			}
			else {
				continue;
			}
		}
	}
	solve();
	maxi();
	printf("%d", max1);
}