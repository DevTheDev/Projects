#include <stdio.h>
#include <math.h>
int value_to_print = 0;
int bintodec(int n)
{

}
int pown(int n, int e)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return e * pow2(--n);
	}
}

int dectobin(int n)
{
	static int pv = floor(log(n)/log(2));
	if(n <
	{
		return 1;
	}
	else
	{
		return pown(pv, 10) + pown(--pv, 10);
	}
}
int main()
{
	printf("Binary or Decimal: ");
	char uinpt[12];
	scanf("%s", &uinpt);
	if(uinpt[0] == 'd' || uinpt[0] == 'D')
	{
		bintodec();
	}
	else if(uinpt[0] == 'b' || uinpt[0] == 'B')
	{
		dectobin();
	}
	else
	{
		printf("Failed.\n");
		return 1;
	}
}
