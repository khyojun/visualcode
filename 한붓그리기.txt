#include <stdio.h>
#pragma warning(disable:4996)
int n, m;
int map[1010][1010];
int chk[1010][1010];
int x, y,visit[1010];
int size, tmp,flag;
int hol[1010] = { 1 };
void check()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1 || map[j][i] == 1)
			{
				cnt++;
			}
		}
		if (cnt % 2 == 1)
		{
			hol[size++] = i;
		}
	}
}
void dfs(int now)
{
	visit[tmp] = now;
	if (flag == 1)
	{
		return;
	}
	if (tmp == m)
	{
		flag = 1;
		for (int i = 0; i <= m; i++)
		{
			printf("%d ", visit[i]);
		}
		return;
	}
	else {
		for (int i = 1; i <= n; i++)
		{
			if (map[now][i]>0)
			{
				map[now][i]--;
				map[i][now]--;
				tmp++;
				dfs(i);
				map[now][i]++;
				map[i][now]++;
				tmp--;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int st, ed;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		map[x][y]++;
		map[y][x]++;
	}
	check();
	if(size==0 || size==2)
	{
		dfs(hol[0]);
	}
	else {
		printf("0");
		return 0;
	}
}