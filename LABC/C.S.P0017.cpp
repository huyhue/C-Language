#include <stdio.h>
#include <math.h>
#define PI 3.14
void menu()
{
	printf ("1 - Calculating Fuel Economy\n");
	printf ("2 - Calculating Distance Travaled\n");
	printf ("3 - Revised Fuel Economy Calculation\n");
}
int option()
{	
	int op;
	printf ("\nChoice feature: ");
	scanf ("%d", &op);
	return op;
}
float func1 (float time, float speed, float gas){
	do{
		printf ("\nHow many minutes did you drive?\n");
		scanf ("%f", &time);
		printf ("What was the average speed of the car during that time?\n");
		scanf("%f", &speed);
		printf ("How many gallons of gas did your car use?\n");
		scanf ("%f", &gas);
	}while (time-int(time)!=0 || time <=0 || speed<=0 || gas<=0);
	time /= 60;
	float result = time * speed / gas;
	return result;
}

float func2 (float radius, float revolutions){
	do{
		printf ("\nWhat is the radius of your tires, in inches?\n");
		scanf ("%f", &radius);
		printf ("How many revolutions did your car's tire make?\n");
		scanf ("%f", &revolutions);
	}
	while (revolutions-int(revolutions)!=0 || revolutions<=0 || radius<=0);
	float result = 2*PI*radius * revolutions;
	result*=(1.578* pow(10, -5));
	return result;
}
float func3 (float radius, float revolutions, float gas){
	do{
		printf ("\nWhat is the radius of your tires, in inches\n");
		scanf ("%f", &radius);
		printf ("How many revolutions did your car's tires make\n");
		scanf ("%f", &revolutions);
		printf ("How many gallons of gas did your car use?\n");
		scanf ("%f", &gas);	
	}
	while (revolutions-int(revolutions)!=0 || revolutions<=0 || radius<=0 || gas<=0);
	float result = 2*PI*radius * revolutions/gas;
	result*=(1.578*pow(10,-5));
	return result;
}
int main()
{
	float time, speed, gas, radius, revolutions;
	menu();
	int choice;
	int count = 0;
	do{
		choice = option();
		switch(choice){
			case 1: printf ("Your car averaged %.2f miles per gallon.\n", func1(time, speed, gas));
					count++;
					break;
			case 2: printf ("Your car traveled %.2f miles.\n", func2(radius, revolutions));
					count++;
					break;
			case 3: printf ("Your car averaged %.2f miles per gallon.\n",func3(radius, revolutions, gas));
					count++;
					break;
			default: break;
		}
	}
	while (choice>0 && choice<4 && count <= 3);
	return 0;
}
	
			
	
