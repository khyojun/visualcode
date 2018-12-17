#include <stdio.h>
#pragma warning(disable:4996)
int n;
int arr[1010];
int sorti[1010];
void mergesor(int left, int right, int mid)
{
	int l = left;
	int r = mid+1;
	int size = left;
	while (l <= mid && r <= right)
	{
		if (arr[l] <= arr[r])
		{
			sorti[size++] = arr[l++];
		}
		else {
			sorti[size++] = arr[r++];
		}
	}
	if (l <= mid)
	{
		for (int i = l; i <= mid; i++)
		{
			sorti[size++] = arr[i];
		}
	}
	if (r <= right)
	{
		for (int i = r; i <= right; i++)
		{
			sorti[size++] = arr[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sorti[i];
	}




}




void mer(int left, int right)
{
	if (left <= right)
	{
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
	mer(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}