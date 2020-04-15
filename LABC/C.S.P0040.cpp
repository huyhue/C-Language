#include<stdio.h>
#include<math.h>
void menu(){
	printf("1- Quadratic equation\n");
	printf("2- Bank deposit problem\n");
	printf("3- Quit\n");
	printf("\n");
}
void equation(float a, float b, float c){
	printf ("Enter a:\n");
	scanf ("%f", &a);
	printf ("Enter b:\n");
	scanf ("%f", &b);
	printf ("Enter c:\n");
	scanf ("%f", &c);
	
	float delta = b*b - 4*a*c;
	float x1 = (-b + sqrt(delta))/(2*a);
	float x2 = (-b - sqrt(delta))/(2*a);
	
	if (a == 0){
		printf ("This is a first degree equation!\n");
		if(b == 0 && c!= 0)	
			printf ("This equation has no solution.\n");
		else if(b == 0 && c == 0)
			printf ("This equation has countless solution.\n");
		else 
			printf ("The solution of this equation is %.2f\n", -c/b);
	}
	else{
		if(delta < 0)
			printf ("This equation has no solution.\n");
		else if(delta == 0)
			printf ("This equation has 1 solution is x= %.2f\n", -b/(2*a));
		else 
			printf ("This equation has 2 solutions that are x1 = %.2f, x2 = %.2f\n", x1, x2);
	}
}
	void bank(float deposit, float rate, float month){
		do{
			printf("Enter Deposits \n");
			scanf("%f",&deposit);
			printf("Enter Deposit interest rates\n");
			scanf("%f",&rate);
			printf("Enter No of deposit months\n");
			scanf("%f",&month);
			if(deposit < 0 && rate < 0&& rate >0.1 && month <0 ){
				printf("Enter wrong, try again!\n");
			}
		}while(deposit < 0 && rate < 0 && rate >0.1 && month <0 );
		float total = deposit + deposit*rate*month;
		printf("The total amount received: %.2f\n",total);
	}
int main(){
	int choice;
	float a, b, c, deposit, rate, month;
	printf("MENU\n");
	printf("-----------------------------");
	printf("\n");
	do{
		menu();
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				equation(a,b,c);
				break;
			case 2:
				bank(deposit, rate, month);
				break;
			default:
				break;
		}
	}while(choice >0 && choice < 3);
return 0;
}

