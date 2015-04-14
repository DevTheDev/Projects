//Number Names

#include "NumberNames.h"

int main()
{
	int uinpt = 1;
	while(uinpt != 0)
	{
		printf("Enter a number between 0 and 10^7: ");
		scanf("%i", &uinpt);
		if(uinpt != 0)
		{
			printf("That's ");
			displayGeneral(uinpt);
			putchar('\n');
		}
		else
		{
			printf("Ending Loop. Thank you.\n");
		}
		clearStorage();
	}
}
