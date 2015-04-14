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
int mod_storage[7]; //Store remainders for next operation
int num_storage[7]; //Store numbers for printing
int pow_tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000};//Probably don't need

//Functions
int ilog(int n)
{
    return (int) log10f(n);
}

int getPlace(int n)
{
    return floor(ilog(n));
}
int sieveGeneral(int n, int pv)
{
	if((pv % 10 == 0 || pv == 1) && (n >= pv))
	{
        if(pv == 1)
        {
            mod_storage[getPlace(n % pv)] = n;
        }
        else
        {
            mod_storage[getPlace(n % pv)] = n % pv;
        }
        return floor(n/pv);
	}
	else
	{
		//printf("ERROR. INVALID INPUT TO sieveGeneral(): n = %i, pv = %i\n", n, pv);
		return 0;
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
		printf("%s%s", numbers[n], numbers[28]);//No thousand
	}
}
void printE4(int n)//Don't want to print "thousand" on this command, but on printE3
{
	if(n == 1 && *numbers[n+1] != 0)
	{
		printf("%s%s", numbers[n], numbers[29]);//I think it's n to getList
	}
	printf("%s", numbers[n+18]);
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
void printE1(int n)
{}
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
	mod_storage[(int) floor(log10f(n))] = n;//Initialze first mod storage to n

	for(int i = floor(log10f(n)); i > 0; i--)
	{
		num_storage[i] = sieveGeneral(mod_storage[i], powE(i));//Should assign all values to the proper arrays
	}

	switch((int) floor(log10f(n)))
	{
		case 6:
			printE6(num_storage[6]);
		case 5:
			printE5(num_storage[5]);
		case 4:
			printE4(num_storage[4]);
		case 3:
			printE3(num_storage[3]);
		case 2:
			printE2(num_storage[2]);
		case 1:
			printE1(num_storage[1]);
			break;
	}


}








#endif
