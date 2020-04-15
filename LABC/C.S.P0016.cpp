#include<stdio.h>
int main(){
	float loan, rate, pay;
	printf("What is the value left on the mortgage?\n");
	scanf("%f", &loan);
	printf("What is the annual interest rate of the loan, in percent ?\n");
	scanf("%f", &rate);
	printf("What is the monthly payment?\n");
	scanf("%f", &pay);
	printf("Month\tPayment \tAmount Owed\n");
	rate = rate / 12 * 0.01;
	
	int i = 1;
	do{
		if(loan < pay){
			pay = loan * rate + loan;
		}
		loan = (loan + loan * rate) - pay;
		
		printf("%d\t%.2f \t%.2f\n",i,pay,loan);
		i++;
	}while(loan>0);
getchar();
}

