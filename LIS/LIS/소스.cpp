#include <stdio.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
vector <int> a;
int n;
int idx;   // idx 배열의 주소
int arr[1010101];// 입력배열
int sol[1010101];// 검사배열

void bina(int x)
{
	int left, right, mid = 0;
	left = 0;
	right = idx-1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sol[mid] >= x)
		{
			right = mid - 1;
		}
		else if (sol[mid] < x)
		{
			left = mid + 1;
		}
	}
	//같은 값 처리
	sol[left] = x;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (sol[idx-1] < arr[i])
		{
			sol[idx]=arr[i];
			idx++;
			continue;
		}
		bina(arr[i]);
	}
	printf("%d", idx);
}