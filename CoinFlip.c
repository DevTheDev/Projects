//Coin Flip

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip()
{
	//printf("Ra: %i\n", rand());
	int r = rand() % 2;
	//printf("R: %i\n", r);
	if(r == 2)
	{
		return 0;
	}
	else
	{
		return r;
	}
}

int main()
{
	srand(time(NULL));
	int consec_heads;
	int i, f;
	for(i = 0; consec_heads != 3; i++)
	{
		if(flip() == 1)
		{
			printf("Heads.\n");
			consec_heads++;
		}
		else
		{
			printf("Tails.\n");
			consec_heads = 0;
		}
	}
	printf("Total flips to get 3: %i", i);
}
