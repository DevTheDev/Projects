//Number Names

#include "NumberNames.h"

int main()
{
	//isplayGeneral(65206);
	//sieveGeneral(206, 100);
	//sieveGeneral(6, 10);
	//sieveGeneral(5206, 1000);
	//sieveGeneral(206,10);
	//sieveGeneral(6,10);
	mod_storage[3] = 6002;
	num_storage[3] = sieveGeneral(mod_storage[3], powE(3));
	//printf("%i", mod_storage[2]);
	num_storage[2] = sieveGeneral(mod_storage[2], powE(2));
	num_storage[1] = sieveGeneral(mod_storage[1], powE(1));
	//num_storage[0] = sieveGeneral(mod_storage[0], powE(0));
	for(int i = 0; i < 7; i++)
	{
		printf("Storage Test: %i, %i\n", mod_storage[i], num_storage[i]);
	}
	/*printf("Name: %s", numbers[sieveGeneral(5206,1000)]);
	printf("%s", numbers[sieveGeneral(206,100)]);
	printf("%s", numbers[sieveGeneral(06, 10)]);
	printf("%s", numbers[sieveGeneral(6,1)]);*/
	//printf("\nQuick Test: %i", getListE1(11));

}
