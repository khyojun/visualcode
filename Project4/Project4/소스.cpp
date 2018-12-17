#include <stdio.h>
#pragma warning(disable:4996)
int n, m;
int white, blue;
int cnt1, cnt2; // cnt1Àº Èò»ö cnt2´Â ÆÄ¶û»ö
int map[132][132];
void solve(int x, int y, int size)
{
	if (size <= 0) {
		return;
	}

	if (size == 1 && map[x][y] == 1)
	{
		cnt2++;
		return;
	}
	else if (size == 1 && map[x][y] == 0)
	{
		cnt1++;
		return;
	}
	int cnt=0;
	for (int i = x; i <= x+size-1; i++)
	{
		for (int j = y; j <= y+size-1; j++)
		{
			if (map[i][j]==1)
			{
				cnt++;
			}
		}
	}
	if (cnt == size * size)
	{
		cnt2++;
		return;
	}
	else if (cnt == 0)
	{
		cnt1++;
		return;
	}
	else {
		solve(x, y, size / 2);
		solve(x, y + size/2, size/2);
		solve(x + size/2, y, size/2);
		solve(x + size/2, y + size/2, size/2);
	}
}






int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	solve(1, 1, n);
	printf("%d\n%d", cnt1, cnt2);
}