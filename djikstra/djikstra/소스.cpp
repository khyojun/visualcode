#include <stdio.h>
#pragma warning(disable:4996)
int n;
void hanoi(int x, char st, char fin)
{
	if (x == 0)
	{
		return;
	}
	int s = st-'A'+6;
	int f = fin - 'A' + 1;
	int x1 = st - 'A' + 1;
	int y = fin - 'A' + 1;
	hanoi(x - 1,  st, s-x1-y+'A'-1);
	printf("%c %c\n", st, fin);
	hanoi(x - 1, s - x1 - y + 'A' - 1, fin);
}




int main()
{
	scanf("%d", &n);
	hanoi(n, 'A', 'C');




}