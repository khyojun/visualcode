#include<stdio.h>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
int arr[11];
int arr1[11];
int arr2[11];
int res[10000000];
int n,cnt,i,max1,min1,top;
bool comp(int a, int b) {
	return a > b;
}
void ol(int arr[],int x)
{
	sort(arr1, arr1 + x);
	min1 = 0;
	for (int i = 1; i < x; i++)
	{
		min1 += arr[i];
		arr[i] = 0;
		min1 *= 10;
	}
	min1 /= 10;
}
void ne(int arr[], int x)
{
	sort(arr2, arr2 + x,comp);
	max1 = 0;
	for (int i = 0; i < x-1; i++)
	{
		max1 += arr[i];
		arr[i] = 0;
		max1 *= 10;
	}
	max1 /= 10;
}
int main()
{
	freopen("input.txt", "w", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	res[top++] = n;
	for (i = 0; ; i++)
	{
		if (n != 0) {
			arr[i] = n % 10;
			arr1[i] = n % 10;
			arr2[i] = n % 10;
			n /= 10;
		}
		else if (n == 0)
			break;
	}
	while (1)
	{
		ol(arr1,i+1);
		ne(arr2,i+1);
		if (max1 - min1 == res[top - 1])
			break;
		res[top++] = max1 - min1;
		n = max1 - min1;
		for (i = 0; ; i++)
		{
			if (n != 0) {
				arr[i] = n % 10;
				arr1[i] = n % 10;
				arr2[i] = n % 10;
				n /= 10;
			}
			else if (n == 0)
				break;
		}
	}
	printf("%d\n", top);
	for (int i = 0; i < top; i++)
	{
		printf("%d\n", res[i]);
	}
}



