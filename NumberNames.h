//Number Names.h

#include <stdio.h>
#include <math.h>

#ifndef NumberNames

//Lists
char *numbers[] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ",
 				"Six ", "Seven ", "Eight ", "Nine ", "Ten ",
				"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ", "Twenty ",
				"Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ",
				"Ninety ", "Hundred ", "Thousand ", "Million"};
//TODO ADD STORAGE FOR NUMBERS
int mod_storage[7]; //Store remainders for next operation
int num_storage[7]; //Store numbers for printing
int pow_tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

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

int getListE1(int stored)
{
	switch(stored)
	{
		case 11:
			return 11;
		case 12:
			return 12;
		case 13:
			return 13;
		case 14:
			return 14;
		case 15:
			return 15;
		case 16:
			return 16;
		case 17:
			return 17;
		case 18:
			return 18;
		case 19:
			return 19;
	}
}
int getListE2(int stored)
{
	switch(stored)
	{
		case 1:
			getListE1(stored); //Should actually call getListE1
		case 2:
			return 20;
		case 3:
			return 21;
		case 4:
		 	return 22;
		case 5:
			return 23;
		case 6:
			return 24;
		case 7:
			return 25;
		case 8:
			return 26;
		case 9:
			return 27;
	}
}




//TODO ADD DISPLAY FUNCTION
void printE6(int n)
{
	if(n != 0)
	{
		printf("%s%s", numbers[n], numbers[30]);
	}
}
void printE5(int n)
{
	if(n != 0)
	{
		printf("%s%s%s", numbers[n], numbers[28], numbers[29]);
	}
}
void printE4(int n)//Don't want to print "thousand" on this command, but on printE3
{
	if(n == 1 && *numbers[n+1] != 0)
	{
		printf("%s%s", numbers[getListE1()], numbers[29]);
	}
	printf("%s", numbers[n]);
}
void printE3(int n)
{
	if(n != 0)
	{
		printf("%s", numbers[n]);
	}
	if(*numbers[n-1] != 1)
	{
		printf("%s", numbers[29]);
	}
}
void printE2(int n)
{

}
int powE(unsigned int n)//Because I'm lazy, and don't need a negative one right now
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return 10*powE(--n);
	}
}

void displayGeneral(int n)
{
	mod_storage[(int) floor(log10f(n))] = n;

	for(int i = floor(log10f(n)); i > 0; i--)
	{
		num_storage[i] = sieveGeneral(mod_storage[i], powE(i));//Should assign all values to the proper arrays
	}

	switch((int) floor(log10f(n)))
	{
		case 6:
			printE6(mod_storage[6]);
		case 5:
			printE5(mod_storage[5]);
		case 4:
			printE4(mod_storage[4]);
		case 3:
			printE3(mod_storage[3]);
		case 2:
			printE2(mod_storage[2]);
		case 1:
			printE1(mod_storage[1]);
			break;
	}
}








#endif
