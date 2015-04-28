//Cost of Tile

#include <stdio.h>


int main()
{
	float cost, dimx, dimy;
	printf("Enter the cost of the tile per square foot:");
	scanf("%f", &cost);
	printf("Now enter the l x w in feet, use decimals as appropriate: ");
	scanf("%f, %f", &dimx, &dimy);

	printf("Area: %.3f\'\n", dimx * dimy);
	printf("	Cost for that area: $%.2f\n", dimx * dimy * cost);

}
