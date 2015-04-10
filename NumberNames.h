//Number Names.h

#include <stdio.h>
#include <math.h>

#ifndef NumberNames

//Lists
char *numbers[] = {"One ", "Two ", "Three ", "Four ", "Five ",
 				"Six ", "Seven ", "Eight ", "Nine ", "Ten ",
				"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ", "Twenty ",
				"Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ",
				"Ninety ", "Hundred ", "Thousand ", "Million"};
//TODO ADD STORAGE FOR NUMBERS
int mod_storage[7];

//Functions
int sieveGeneral(int n, int pv)
{
	if(pv % 10 == 0 || pv == 1)
	{
		if(n >= pv)
		{
			mod_storage[(int)log10f(pv)-1] = n % pv;
			return floor(n/pv);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		printf("ERROR. INVALID INPUT TO sieveGeneral(): n = %i, pv = %i\n", n, pv);
		return 0;
	}
}



//TODO ADD DISPLAY FUNCTION


#endif
