#include <stdio.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
vector <int> a;
int n;
int idx;   // idx �迭�� �ּ�
int arr[1010101];// �Է¹迭
int sol[1010101];// �˻�迭

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
	//���� �� ó��
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