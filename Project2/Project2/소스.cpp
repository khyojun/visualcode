#include <stdio.h>
#pragma warning(disable:4996)
int n, m,tail,head,min=2e9,minx=-10,x,y,cnt;
int arr[1004][1004];
int price[1007];
int st, fi, pr,finish,start;
bool chk[1006];
void bfs(int x)
{
	if (chk[x])
	{
		return;
	}
	else{
	chk[x] = true;
		for (int i = 1; i <= n; i++)
		{
			if (price[i] > arr[x][i] + price[x])
			{
				price[i] = arr[x][i] + price[x];
			}
		}
	}
}





int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			arr[i][j] = 2e9;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &pr);
		if (arr[x][y] > pr) arr[x][y] = pr;
	}
	scanf("%d %d", &start, &finish);
	for (int i = 1; i <= n; i++)
	{
		if (i == start)
		{
			price[i] = 0;
			continue;
		}
		price[i] = 2e9;
	}

	while (1)
	{
		cnt = 0;
		min = 2e9 - 1;
		for (int i = 1; i <= n; i++)
		{
			if (min >= price[i] && chk[i]==false)
			{
				min = price[i];
				minx = i;
			}
		}
		if (min == 2e9 - 1) break;
		bfs(minx);
	}
	printf("%d", price[finish]);
	return 0;
}
