//Collatz Conjecture

#include <stdio.h>

int Collatz(int n)
{
	int count = 0;
	while(n != 1)
	{
		if(n < 1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if(n % 2 == 0)
		{
			printf("Count: %i N is even. %i\n", count, n);
			n /= 2;
			count++;
		}
		else
		{
			printf("Count: %i N is odd. %i\n", count, n);
			n *= 3;
			n += 1;
			count++;
		}
	}
	return count;
}
int main()
{
	printf("Collatz at 5: %i", Collatz(20));
}
