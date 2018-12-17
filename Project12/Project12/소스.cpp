//#include <stdio.h>
//#pragma warning(disable:4996)
//int n;
//int arr[1010];
//void quicksort(int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int l = left;
//	int r = right;
//	int pivot = (left + right) / 2;
//	while (l <= r)
//	{
//		while(arr[l] < arr[pivot])
//		{
//			l++;
//		}
//		while(arr[r] > arr[pivot])
//		{
//			r--;
//		}
//
//		if (l <= r)
//		{
//			int tmp;
//			tmp = arr[l];
//			arr[l] = arr[r];
//			arr[r] = tmp;
//			l++;
//			r--;
//		}
//	}
//	if (r > left)
//	{
//		quicksort(left, r);
//	}
//	if (l < right)
//	{
//		quicksort(l, right);
//	}
//}
//
//
//
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	quicksort(0, n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
////#include <stdio.h>
////#pragma warning(disable:4996)
////int arr[1010];
////int mid;
////int st, ed;
////
//////quick_sort clear
////void quick(int st, int ed)
////{	
////	if (st >= ed)
////	{
////		return;
////	}
////	int l, r;
////	int mid = (st + ed) / 2;
////	int pivot = arr[mid];
////	l = st;
////	r = ed;
////	while (l<=r)
////	{
////		while (pivot > arr[l])
////		{
////			l++;
////		}
////		while (pivot < arr[r])
////		{
////			r--;
////		}
////		if (l <= r)
////		{
////			int tmp;
////			tmp = arr[r];
////			arr[r] = arr[l];
////			arr[l] = tmp;
////			l++;
////			r--;
////		}
////	}
////	if (st < r)
////	{
////		quick(st, r);
////	}
////	if (l < ed)
////	{
////		quick(l, ed);
////	}
////
////}
////int main()
////{
////	for (int i = 0; i < 10; i++)
////	{
////		scanf("%d", &arr[i]);
////	}
////	quick(0, 9);
////	for (int i = 0; i < 10; i++)
////	{
////		printf("%d ", arr[i]);
////	}
////}
//
////아까처럼 재귀를 돌려버리면 문제점
////
////1. r-1은 뭐 ㄱㅊ
////2. r+1일때 만약 값이 하나밖에 차이나지않는다면 mid와 자꾸 겹쳐버려서 자꾸 무한재귀를 만들어버리게됨 그리하여 예외처리가 발생하게됨
////
////그래서 조건을 만들어서 무한 재귀가 안생기게 처리해줘야됨
////
////핵심은 교차할때 교차한 값들을 기준으로 분할 정복을 해야함



#include <stdio.h>
#pragma warning(disable:4996)
int n;
int arr[1010];
int sorti[1010];
void mergesor(int left, int right, int mid)
{
	int l = left;
	int r = mid + 1;
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
	if (left < right)
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