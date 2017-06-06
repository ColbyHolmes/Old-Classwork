/*Colby Holmes
colbyholmes@my.unt.edu
9/13/2014
This program takes the intial velocity and height of a projectile and returns
the max height and air time of it to the user. */

#include <stdio.h>
#include <math.h>

int main()
{
	printf("\n\tCSCE 1030\n\tSection 001\n\tColby Holmes\n\tcah0448\n"
		"\tcolbyholmes@my.unt.edu\n\n");

	/*Defining Variables!
	 iHeight and iVelocity will be user inputs
	 maxH and airT are outputs
	 GRAVITY is the universal constant in ft/s^2*/
	float iHeight, iVelocity, maxH, airT;
	const GRAVITY = -16;
	
	/*This introduces the program and lets the user input the intial 
	variables that the equation needs.*/
	printf("This program calculates the air-time and max height of a "
	       "projectile thrown directly upwards.\n"
	       "Initial Height(ft): ");
	scanf("%f", &iHeight);
	printf("Intial Velocity(ft/s): ");
	scanf("%f", &iVelocity);

	/*This calculates the maximum height of the projectile.*/
	maxH = (-(iVelocity * iVelocity) + 4*(GRAVITY)*(iHeight))
		/(4*GRAVITY);

	/*This calculates the air time of the projectile. The if
	statement confirms that only the correct number is recorded.*/
	if (((-iVelocity + sqrt((iVelocity*iVelocity)
		 -4*(GRAVITY)*(iHeight)))/(2*GRAVITY)) > 0)
	{
		airT = (-iVelocity + sqrt((iVelocity*iVelocity)
			 -4*(GRAVITY)*(iHeight)))/(2*GRAVITY);
	}
	else
	{
		airT = (-iVelocity - sqrt((iVelocity*iVelocity) 
			-4*(GRAVITY)*(iHeight)))/(2*GRAVITY);
	}

	/*This section prints the output for the user.*/
	printf("The maximum height was: %.2f feet\n"
		"The air-time was: %.2f seconds\n",
		maxH, airT);

	return 0;	
}
