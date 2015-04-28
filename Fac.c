//Factorial

#include <stdio.h>

int fac(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * fac(n-1);
	}
}

int facl(int n)
{
	int sol = 1;
	for(int i = 1; i <= n; i++)
	{
		sol *= i;
	}
	return sol;
}
int main()
{
	printf("Enter a number: ");
	int un;
	scanf("%i", &un);
	printf("Recursive: %i\n", fac(un));
	printf("Iterative: %i\n", facl(un));
}
