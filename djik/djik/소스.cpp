#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {

	}

	bool operator < (const Edge&other) const {
		return other.cost < cost;
	}
};
int n,m;
vector <Edge> a[101010];
int dist[101010];
bool chk[101010];
int inf = 1000000;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(Edge(y, z));
		a[y].push_back(Edge(x, z));
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i] = inf;
	}
	int start;
	scanf("%d", &start);
	dist[start] = 0;
	priority_queue <pair<int,int>> q;
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		auto p = q.top(); // first 정점 second 가중치
		q.pop();
		int tmp = p.first;
		if (chk)
		{
			continue;
		}       
		chk[tmp] = true;
		for (int i = 0; i < a[tmp].size(); i++)
		{
			int go = a[tmp][i].to;
			if (dist[go] > a[tmp][i].cost + dist[tmp])
			{
				dist[go] = a[tmp][i].cost + dist[tmp];
				q.push(make_pair(go, dist[go]));
			}
		}

	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] >= inf)
		{
			printf("INF\n");
		}
		else {
			printf("%d ", dist[i]);
		}
	}
}