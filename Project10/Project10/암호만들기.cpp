#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int L, C;
char alpha[1010];
int sor[1010];
char mo[5] = { 'a' , 'e', 'i', 'o', 'u' };
char pass[1010];
bool chek(char arr1[])
{
	int mo1 = 0;
	int ja = 0;
	for (int i = 0; i < strlen(mo); i++)
	{
		for (int j = 0; j < strlen(arr1); j++)
		{
			if (arr1[j] == mo[i])
			{
				mo1++;
			}
		}
	}
	ja = strlen(arr1) - mo1;
	return (ja >= 2 && mo1 >= 1);
}
void f(int len, char arr[],char pasw[],int index, int size, int flag)
{
	if(flag==1)
	{
		pasw[size] = arr[index];
	}
	if (strlen(pasw) == len)
	{
		if (chek(pasw))
		{
			for (int i = 0; i < strlen(pasw); i++)
			{
				printf("%c", pasw[i]);
			}
			printf("\n");
		}
		return;
	}
	if (index >= strlen(arr))
	{
		return;
	}
	f(L, alpha, pasw, index+1, size+1,1);
	pasw[size+1] = 0;
	f(L, alpha, pasw, index + 1, size,0);
}
int main()
{
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
	{
		scanf(" %c", &alpha[i]);
		sor[i] = alpha[i] - 'a' + 1;
	}
	sort(sor, sor + C);
	for (int i = 0; i < C; i++)
	{
		alpha[i]=sor[i] + 'a' - 1;
	}
	for (int i = 0; i < C; i++) {
		f(L, alpha, pass, i, 0, 1);
		pass[0]=0;
		f(L, alpha, pass, i, 0, 0);
	}
}