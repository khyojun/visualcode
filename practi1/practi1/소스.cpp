//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//#pragma warning(disable:4996)
//int dx[5] = { 0,-1, 0, 1 };
//int dy[5] = { -1, 0, 1, 0 };
//int n, m,maxi;
//int map[550][550];
//bool chk[550][550];
//bool chek(int x, int y)
//{
//	return x<1 || y<1 || x>n || y>m;
//}
//
//void dfs(int x, int y, int sum, int cnt)
//{
//
//	if (chk[x][y])
//	{
//		return;
//	}
//	if (cnt == 4)
//	{
//		maxi = max(maxi, sum);
//		return;
//	}
//	chk[x][y] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int next_x = x + dx[i];
//		int next_y = y + dy[i];
//		if(!chek(next_x, next_y))
//		{
//			dfs(next_x, next_y, sum + map[next_x][next_y], cnt + 1);
//		}
//	}
//	chk[x][y] = false;
//
//}
//void exc(int x, int y)
//{
//	int tmp = 0;
//	if (!chek(x, y - 1) && !chek(x + 1, y - 1) && !chek(x - 1, y - 1))
//	{
//		tmp = map[x][y] + map[x][y - 1] + map[x + 1][y - 1] + map[x - 1][y - 1];
//		maxi = max(tmp, maxi);
//	}
//	if (!chek(x, y + 1) && !chek(x + 1, y + 1) && !chek(x - 1, y + 1))
//	{
//		tmp = map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x - 1][y + 1];
//		maxi = max(tmp, maxi);
//	}
//	if (!chek(x-1, y - 1) && !chek(x - 1 , y) && !chek(x - 1, y + 1))
//	{
//		tmp = map[x][y] + map[x-1][y - 1] + map[x - 1][y + 1] + map[x - 1][y];
//		maxi = max(tmp, maxi);
//	}
//	if (!chek(x+1, y - 1) && !chek(x + 1, y + 1) && !chek(x + 1, y))
//	{
//		tmp = map[x][y] + map[x+1][y - 1] + map[x + 1][y + 1] + map[x + 1][y];
//		maxi = max(tmp, maxi);
//	}
//}
//
//
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			scanf("%d", &map[i][j]);
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			dfs(i, j,map[i][j], 1);
//			exc(i, j);
//		}
//	}
//	printf("%d", maxi);
//}
#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int n,maxi;
int profit[1010];
int day[1010];
void dfs(int now, int sum)
{
	if (now == n+1)
	{
		maxi = max(maxi, sum);
		return;
	}
	if (now > n + 1)
	{
		return;
	}// �ణ ȣ��ǰ� ������ �ƴϸ� ȣ������ �ʰ� ������ ���ƾߵǴ��� �ð��� ���̸� �˾ƺ��ߵ� ������ �����̶�� �߰����� �ð��� ȣ��Ȱ� Ž���ϴ� �ð��� �ֱ� ����
	dfs(now + day[now], sum + profit[now]);   // �ѹ� ���ǹ� ������ �Ǵ��� �ȵǴ��� �ѹ� ���߰���
	dfs(now + 1, sum);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &day[i], &profit[i]); // �̰� �ѹ� ���߿� �Űܺ��߰���
	}
	dfs(1, 0);
	printf("%d", maxi);
}

