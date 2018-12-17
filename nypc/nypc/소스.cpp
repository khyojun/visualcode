#include <stdio.h>
#pragma warning(disable:4996)
int n,m;
int main()
{
	scanf("%d %d", &n, &m);
	while (1)
	{
		if (n == 1 && m == 0)
		{
			printf("POSSIBLE");
			break;
		}
		else if (m == 0)
		{
			printf("IMPOSSIBLE");
			break;
		}
		else if (m == 1 && n >= 1)
		{
			printf("POSSIBLE");
			break;
		}
		else if (n == m)
		{
			printf("IMPOSSIBLE");
			break;
		}
		else if (n == 0)
		{
			printf("IMPOSSIBLE");
			break;
		}
		if (n > m)
		{
			n %= m;
		}
		else {
			m %= n;
		}
	}
}
