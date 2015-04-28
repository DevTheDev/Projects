//Change Return

#include <stdio.h>

struct coin  {
	int value;
	int amount;
} penny, nickel, dime, quarter;


void getChange(int n)
{
	quarter.amount = 0;
	dime.amount = 0;
	nickel.amount = 0;
	penny.amount = 0;

	if(n >= quarter.value)
	{
		quarter.amount = (n - (n % quarter.value))/quarter.value;
	}
	n -= quarter.amount * quarter.value;

	if(n >= dime.value)
	{
		dime.amount = (n - (n % dime.value))/dime.value;
	}
	n -= dime.amount * dime.value;

	if(n >= nickel.value)
	{
		nickel.amount = (n - (n % nickel.value))/nickel.value;
	}
	n -= nickel.amount * nickel.value;

	if(n > penny.value)
	{
		penny.amount = n;
	}
	n -= penny.amount * penny.value;
}

int main()
{
	penny.value = 1;
	nickel.value = 5;
	dime.value = 10;
	quarter.value = 25;

	float cost, amnt_paid;

	printf("Enter the cost of the product, and then the amount you paid for it: ");
	scanf("%f,%f", &cost, &amnt_paid);

	int costn = (int) (cost*100);
	int amnt_paidn = (int) (amnt_paid*100);

	if(cost > amnt_paid)
	{
		printf("Pay more next time, cheapskate.\n");
		return 1;
	}
	else
	{
		//printf("Amnt Paid: %i, %i\n", amnt_paidn, costn);
		getChange(amnt_paidn - costn);
		printf("Quarters: %i\n", quarter.amount);
		printf("Dimes: %i\n", dime.amount);
		printf("Nickels: %i\n", nickel.amount);
		printf("Pennies: %i\n", penny.amount);
	}
}
