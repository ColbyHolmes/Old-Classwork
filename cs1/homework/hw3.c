/*Colby Holmes
Mark Thompson
CSCE 1030
Due 10/22/2014
This program is for purchasing office equipment, and uses a menu to choose items then calculates a 
total based on the items purchased.

*Edit: HW4 Edit this program to make it use functions*
*/
/*Include header file*/
#include <stdio.h>
/*Declare constants*/
#define TAX_RATE .0825
#define SHIPPING_COST 25.0
/*Create global variable*/
float subtotal = 0;
/*Function prototype*/
void header();
void menu();
float calcSub(int num, float price);
void subDis();
void calcTax(double tax);
/*Create main function*/
int main()
{
	header();
	
/*Greeting*/
	printf("---------Welcome to the online office supply store!---------");
/*Call menu*/
	menu();

/*Make sure a purchase is made*/	
	if (subtotal > 0)
	{
/*Print Costs*/
		printf("\n\nSubtotal\t:\t$%.2f\n", subtotal);
/*Check for Discount*/
		subDis();

		calcTax(TAX_RATE);

		printf("Shipping\t:\t$%.2f\n", SHIPPING_COST);
		printf("Total\t\t:\t$%.2f\n\nThank you for your purchase!\n", subtotal + (subtotal * TAX_RATE) + SHIPPING_COST);
	}
	else
		printf("\nHope to do business with you in the future!\n");
/*End Program*/
	return 0;
}

/*Menu function*/
void menu()
{
/*Declare variables*/
	int opt = 0, num;

/*Make sure option is valid*/
	do{
		printf("\n\nEnter the number corresponding to the product you wish to purchase:"
		"\n1:\tOffice Chairs\t$59.99 each\n2:\tFile Cabinets\t$29.99 "
		"each\n3:\tDesks\t\t$99.99 each\n4:\tBookcases\t$44.99 each\n5:\tCheckout\nOption: ");
		
		scanf("%d", &opt);
		
		if (opt > 5 || opt < 1)
			printf("Sorry. That is not a valid option.");
	
	}while(opt < 1 || opt > 5);
	
/*Switch for each option
Each asks for a number to purchase
Then adds that amount to the subtotal*/
	switch(opt)
	{
		case 1:
			printf("How many Chairs ($59.99) would you like: ");
			scanf("%d", &num);
			subtotal += calcSub(num, 59.99);
			break;
		case 2:
			printf("How many File Cabinets ($29.99) would you like: ");
			scanf("%d", &num);
			subtotal += calcSub(num, 29.99);
			break;
		case 3:
			printf("How many Desks ($99.99) would you like: ");
			scanf("%d", &num);
			subtotal += calcSub(num, 99.99);
			break;
		case 4:
			printf("How many Bookcases ($44.99) would you like: ");
			scanf("%d", &num);
			subtotal += calcSub(num, 44.99);
	}
/*Reprint menu if the option is not 'Checkout'*/
	if (opt != 5)
		menu();
}	

void header()
{
	printf("\n\tCSCE 1030\n\tHomework 3\n\tColby Holmes\n\tcah0448\n\tcolbyholmes@my.unt.edu\n\n");
}

float calcSub(int num, float price)
{
	printf("\nSubtotal of %d items at $%.2f each: %.2f", num, price, num * price);
	return num * price;
}

void subDis()
{
                if (subtotal > 500)
                {
                        subtotal = subtotal - (subtotal * .1);
                        printf("You're purchase was eligible for a 10 percent discount!\nNew Subtotal\t:\t$%.2f\n", subtotal);
                }
}

void calcTax(double tax)
{
                printf("Sales Tax\t:\t$%.2f\n", subtotal * tax);
}
