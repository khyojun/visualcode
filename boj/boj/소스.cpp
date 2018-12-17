#include <stdio.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
struct Edge {
	int from;
	int to;
	int cost;
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost)
	{

	}
	bool operator < (const Edge &other) const {
		return other.cost < cost;
	}
};
int n, m;    //union-find + Á¤·Ä nlogn
vector <Edge> a;
int par[100010];
int find(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	return par[x] = find(par[x]);
}

void mer(int x, int y)
{
	int x1 = find(x);
	int y1 = find(y);
	if (x1 < y1)
	{
		swap(x1,y1);
	}
	par[x1] = y1;
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
	}	
	priority_queue <Edge> q;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		q.push(Edge(x, y, z));
	}
	int ans = 0;
	while (!q.empty())
	{
		int x = q.top().from;
		int y = q.top().to;
		int z = q.top().cost;
		q.pop();
		if (find(x) == find(y))
		{
			continue;
		}
		mer(x, y);
		ans += z;
	}
	printf("%d", ans);
}


