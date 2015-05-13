//Fibonacci to closest number or terms

#include <stdio.h>

void getTerms(int n)
{
	int prev2 = 0;
	int prev1 = 1;
	int temp;
	printf("0, 1");
	for(int i = 0; i < n; i++)
	{
		printf(", %i", prev1 + prev2);
		temp = prev1;
		prev1 = prev1 + prev2;
		prev2 = temp;
	}
}

int getClosestSet(int n)
{
	int prev2 = 0;
	int prev1 = 1;
	int temp;
	printf("0, 1");
	for(int i = 0; prev1 + prev2 <= n; i++)
	{
		printf(", %i", prev1 + prev2);
		temp = prev1;
		prev1 = prev1 + prev2;
		prev2 = temp;
	}
}

int main()//Could add a better user input thing, see numbernames.
{
	getTerms(20);
	putchar(10);
	getClosestSet(21);
}
