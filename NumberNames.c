//Number Names

#include "NumberNames.h"

int main()
{
	displayGeneral(5206);
	for(int i = 0; i < 7; i++)
	{
		printf("Mod Storage Test: %i\n", mod_storage[i]);
	}
	/*printf("Name: %s", numbers[sieveGeneral(5206,1000)]);
	printf("%s", numbers[sieveGeneral(206,100)]);
	printf("%s", numbers[sieveGeneral(06, 10)]);
	printf("%s", numbers[sieveGeneral(6,1)]);*/
	printf("\nQuick Test: %i", getListE1(11));

}
