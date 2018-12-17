#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost)
	{
	}
};
vector <Edge> a[100010];
bool chk[100010];
int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(Edge(y, z));
		a[y].push_back(Edge(x, z));
	}
	priority_queue <pair<int, int>> q;
	for (int i = 0; i < a[1].size(); i++)
	{
		q.push(make_pair(-a[1][i].cost, a[1][i].to));
	}
	int ans = 0;
	chk[1] = true;
	while (!q.empty())
	{
		int x = q.top().second;
		int y = -q.top().first;
		q.pop();
		if (chk[x])
		{
			continue;
		}
		chk[x] = true;
		ans += y;
		for (int i = 0; i < a[x].size(); i++)
		{
			if (chk[a[x][i].to])
			{
				continue;
			}
			q.push(make_pair(-a[x][i].cost, a[x][i].to));
		}
	}
	printf("%d", ans);
}