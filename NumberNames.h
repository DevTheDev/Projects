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
				"Ninety ", "Hundred ", "Thousand ", "Million "};
int mod_storage[7]; //Store remainders for next operation
int num_storage[7]; //Store numbers for printing

/*Functions*/

//Reset all values in the arrays to 0
void clearStorage()
{
    for(int i = 0; i < 7; i++)
    {
        mod_storage[i] = 0;
        num_storage[i] = 0;
    }
}

//Integer Logarithm
int ilog(int n)
{
    return (int) log10f(n);
}

//Power of 10 where the value is
int getPlace(int n)
{
    return floor(ilog(n));
}

//10^n using recursion, no negatives.
int powE(unsigned int n)
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

//Main sifting function, returns the place valued digit (5 from 5000 at 1000), and adds the remainder to mod_storage
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
		return 0;
	}
}

//Print Millions
void printE6(int n)
{
	if(n != 0)
	{
		printf("%s%s", numbers[n], numbers[30]);
	}
}
//Print Hundred thousands without thousands
void printE5(int n)
{
	if(n != 0)
	{
		printf("%s%s", numbers[n], numbers[28]);
	}
}
//Print ten thousands (and thousands if between 11 and 19)
void printE4(int n)
{
    if(n != 0 && n != 1)
    {
        printf("%s", numbers[n+18]);
    }
    else if(n == 1)
    {
        printf("%s", numbers[10 + num_storage[3]]);
    }
}
//Append thousand if there's something in any thousand place, print thousands if not already printed
void printE3(int n)
{
	if(n != 0 && num_storage[4] != 1)
	{
		printf("%s", numbers[n]);
	}
	if(num_storage[5] != 0 || num_storage[4] != 0 || num_storage[3] != 0)
    {
        printf("%s", numbers[29]);
    }
}
//Print Hundreds
void printE2(int n)
{
    if(n != 0)
    {
        printf("%s%s", numbers[n], numbers[28]);
    }
}
//Print tens, print ones if 11-19.
void printE1(int n)
{
    if(n != 0 && n != 1)
    {
        printf("%s", numbers[n+18]);
    }
    else if(n == 1)
    {
        printf("%s", numbers[10 + num_storage[0]]);
        num_storage[0] = 0;
    }
}
//Print ones and newline
void printE0(int n)
{
    if(n != 0)
    {
        printf("%s", numbers[n]);
    }
    printf("\n");
}

//Main displaying function
void displayGeneral(int n)
{
	mod_storage[(int) floor(log10f(n))] = n;//Initialze first mod storage to n

	for(int i = floor(log10f(n)); i > 0; i--)
	{
		num_storage[i] = sieveGeneral(mod_storage[i], powE(i));//Should assign all values to the proper arrays
	}

    num_storage[0] = mod_storage[0];
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
        case 0:
            printE0(num_storage[0]);
			break;
	}


}
#endif
