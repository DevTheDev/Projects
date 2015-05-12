//Reverse String

#include <stdio.h>
#include <String.h>

int main()
{
	char uinpt[128];
	printf("Enter a string:");
	scanf("%[^\n]%*c", &uinpt);//http://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character

	printf("You entered: %s\n", uinpt);
	printf("String Length is: %i\n", strlen(uinpt));
	printf("Reversed is:");
	for(int i = strlen(uinpt)-1; i >= 0; i--)
	{
		putchar(uinpt[i]);
	}
}
