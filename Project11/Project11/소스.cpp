#include <stdio.h>
#pragma warning(disable:4996)
int n;
char arr[100];
int cnt1, cnt2;
int main()
{
	scanf("%d", &n);
	scanf("%s", arr);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 'A')
		{
			cnt1++;
		}
		else {
			cnt2++;
		}
	}
	if (cnt1 > cnt2)
	{
		printf("A");
	}
	else if (cnt1 < cnt2)
	{
		printf("B");
	}
	else if (cnt1 == cnt2)
	{
		printf("Tie");
	}
}