#include <stdio.h>
#include <math.h>

int pown(int e, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return e * pown(e,--n);
	}
}

#define int_size 4294967295

int bintodec(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else if(n < 1 || n > int_size)//OR probably not needed yet
	{
		printf("Bad input to n.\n, size of int is only: %i, you entered %i\n", sizeof(int), n);
		return 0;
	}
	float pv0 = floor(log10f(n));
	int pv = (int) pv0;
	if(pv == 0 && n % 2 == 1)
	{
		return 1;
	}
	else if(pv == 0 && n % 2 == 0)
	{
		return 0;
	}
	else
	{
		return pown(2, pv) + bintodec((n - pown(10, pv)));
	}
}

int dectobin(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else if(n < 1 || n > 1024)//Becomes 10^10 after n = 1024, workaround later
	{
		printf("Bad input to n\n");
		return 0;
	}
	float pv0 = floor(log10f(n)/log10f(2));
	int pv = (int) pv0;
	if(pv == 0 && n % 2 == 1)
	{
		return 1;
	}
	else if(pv == 0 && n % 2 == 0)
	{
		return 0;
	}
	else
	{
		return pown(10, pv) + dectobin((n - pown(2, pv)));
	}
}

int main()
{
	char uinpt[12];
	while(uinpt[0] != 'e' || uinpt[0] != 'E')
	{
		printf("Binary or Decimal: ");
		uinpt[12] = "";
		scanf("%s", &uinpt);
		int numinpt;
		if(uinpt[0] == 'b' || uinpt[0] == 'B')
		{
			printf("Enter a binary number:");
			scanf("%i", &numinpt);
			printf("Dec: %i\n", bintodec(numinpt));
		}
		else if(uinpt[0] == 'd' || uinpt[0] == 'D')
		{
			printf("Enter a decimal number:");
			scanf("%i", &numinpt);
			printf("Bin: %i\n", dectobin(numinpt));
		}
		else if(uinpt[0] == 'e' || uinpt[0] == 'E')
		{
			printf("Exiting loop.\n");
			break;
		}
		else
		{
			printf("Failed.\n");
			return 1;
		}
	}
}
