#include <stdio.h>
#pragma warning(disable:4996)
int arr[1010];
int n;
int sortarr[1010];
int iarr[1010];
int jarr[1010];
void mergesor(int s, int e, int mid)
{
	int first = s;
	int second = mid + 1;
	int size = s;
	while (first <= mid && second <= e)
	{
		if (arr[first] <= arr[second])
		{
			sortarr[size++] = arr[first++];
		}
		else {
			sortarr[size++] = arr[second++];
		}
	}
	if (first <= mid)
	{
		for (int i = first; i <= mid; i++)
		{
			sortarr[size++] = arr[i];
		}
	}
	if (second <= e)
	{
		for (int i = second; i <= e; i++)
		{
			sortarr[size++] = arr[i];
		}
	}
	for (int i = s; i <= e; i++)
	{
		arr[i] = sortarr[i];
	}
}

void mer(int left, int right)
{
	if(left<right){
	int mid = (left + right) / 2;
	mer(left, mid);
	mer(mid + 1, right);
	mergesor(left, right, mid);
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	mer(0, n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}


}
