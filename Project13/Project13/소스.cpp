#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost){
	}
};
int n,start,m;
vector <Edge> a[1010];
int dist[1010];
bool chk[1010];
int main()
{
	scanf("%d", &n); //정사면체는 6개 밖에 없음
	scanf("%d", &m);
	scanf("%d", &start);
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(Edge(y, z));// z가 코스트 y가 도착지
	}
	priority_queue <pair<int,int>> q;
	for (int i = 0; i < n; i++)
	{
		dist[i] = 10101010;
	}
	dist[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		auto p = q.top();
		int x = p.second;
		q.pop();
		if (chk[x])
		{
			continue;
		}
		chk[x] = true;
		for (int i = 0; i < a[x].size(); i++)
		{
			int tmp = a[x][i].to;
			if (dist[tmp] > dist[x] + a[x][i].cost)
			{
				dist[tmp] = dist[x] + a[x][i].cost;
				q.push(make_pair(-dist[tmp], tmp));
			}
		}
	}
	int fin;
	scanf("%d", &fin);
	printf("%d", dist[fin]);
}