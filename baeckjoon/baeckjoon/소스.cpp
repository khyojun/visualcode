#include <stdio.h>
#pragma warning(disable:4996)
#include <vector>
#include <algorithm>
using namespace std;
int n, m, L;
vector <int> a;
int main()
{
	scanf("%d %d %d", &n, &m, &L);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	int siz = a.size();
	int cnt = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (y > L)
		{
			continue;
		}
		int high = x + L - y;
		int low = x + y - L;
		int l = 0;
		int r = a.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (low <= a[mid] && a[mid] <= high)
			{
				cnt++;
				break;
			}
			else if (a[mid] <= low)
			{
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	}
	printf("%d", cnt);
}