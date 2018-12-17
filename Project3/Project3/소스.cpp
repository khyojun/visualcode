#include <stdio.h>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;
int arr[100010];
int input,n;
int inx=1,idx,value;  //  idx는 지금 inx의 값을 기억하기위한  변수
int main()
{	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
			scanf("%d", &value);	
		if(value !=0){
			arr[inx++] = value;
			idx = inx - 1;
			while (idx > 1 && arr[idx] > arr[idx / 2])
			{
				swap(arr[idx], arr[idx / 2]);
				idx /= 2;
			}
		}
		else {
			if (inx == 1) printf("0\n");
			else {
				printf("%d\n", arr[1]);
				arr[1] = arr[--inx];
				idx = 1;
				while (1)
				{
					if (idx * 2 + 1 <= inx && arr[idx * 2 + 1] > arr[idx * 2] && arr[idx * 2 + 1] > arr[idx])
					{
						swap(arr[idx * 2 + 1], arr[idx]);
						idx = idx*2+1;
					}
					else if (idx * 2 <= inx && arr[idx * 2] > arr[idx])
					{
						swap(arr[idx * 2], arr[idx]);
						idx = idx*2;
					}
					else {
						break;
					}
				}
			}
		}
	}

}