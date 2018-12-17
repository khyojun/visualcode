#include <stdio.h>
#include <string.h>
#pragma warning(disable :4996)
char arr[1010];
char mo[5] = { 'A', 'E', 'I', 'O', 'U' };
char res[100];
int size,cnt=0;
int flag=1;
void f(char a, int len, int size)
{
	if (len > 5 || flag==0)
	{
		cnt--;
		return;
	}
	res[size++] = a;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != res[i])
		{
			flag = 1;
			break;
		}
		else {
			flag = 0;
		}
	}
	if (flag == 0)
	{
		printf("%d", cnt);
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		cnt++;
		f(mo[i], len + 1, size);
		if (flag == 0)
		{
			return;
		}
		res[size] = 0;
	}
}
int main()
{
	scanf("%s", arr);
	for(int i=0; i<5; i++)
	{
		cnt++;
		f(mo[i],size+1, size);
		flag = 1;
	}
}