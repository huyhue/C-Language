#include <stdio.h> // Needed to use IO functions
void sumEvenOdd()
{
int sumOdd = 0; // For accumulating odd numbers, init to 0
 int sumEven = 0; // For accumulating even numbers, init to 0
 int upperbound; // Sum from 1 to this upperbound
 int absDiff; // The absolute difference between the two sums
 // Prompt user for an upperbound
 printf("Enter the upperbound: ");
 scanf("%d", &upperbound); // Use %d to read an int
 // Use a while-loop to repeatedly add 1, 2, 3,..., to the upperbound
 int number = 1;
 while (number <= upperbound) {
							 if (number % 2 == 0) { // Even number
							 sumEven += number; // Add number into sumEven
							 } else { // Odd number
							 sumOdd += number; // Add number into sumOdd
							 }
							 ++number; // increment number by 1
							 }
 // Compute the absolute difference between the two sums
 if (sumOdd > sumEven) {
 absDiff = sumOdd - sumEven;
 } else {
 absDiff = sumEven - sumOdd;
 }
 // Print the results
 printf("The sum of odd numbers is %d.\n", sumOdd);
 printf("The sum of even numbers is %d.\n", sumEven);
 printf("The absolute difference is %d.\n", absDiff);
}
void func3(double fa, double *ce)
{
	*ce=(fa-32)*5/9;
}


int main(){
int choice;
double celsius, fahrenheit;
	 printf("nhap vao choice:");
    scanf("%d",&choice);
	 do   /* Print out the menu and get user choice*/
      {    printf("1- tong chan le\n");
           printf("2- tong chan le con tro \n");
           printf("3-cel fa\n");
           printf("4-fa cel\n");
           printf("5-fa cel con tro\n");
           printf("Select an operation:");
           scanf("%d",&choice);
           switch(choice) 
               {  case 1: {
 							sumEvenOdd();}
                        break;
                  case 2:{
                  	printf("Enter the temperature in celsius: ");
					 scanf("%lf", &celsius);
					 fahrenheit = celsius * 9 / 5 + 32;
					 // 9/5*celsius + 32 gives wrong answer! Why?
					 printf("%.2lf degree C is %.2lf degree F\n", celsius, fahrenheit);
										
						}
                        break;
                case 3: {
                	printf("Enter the temperature in fahrenheit: ");
						 scanf("%lf", &fahrenheit);
						 celsius = (fahrenheit - 32) * 5 / 9;
						 // 5/9*(fahrenheit - 32) gives wrong answer! Why?
						 printf("%.2lf degree F is %.2lf degree C\n", fahrenheit, celsius);
						}
                        break;
                 }
        }
     while ( choice >0 & choice<4); 
return 0;
}
