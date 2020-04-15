#include<stdio.h>
#include<conio.h>
int main(){
int i ,key;
int num;
do{
	do{
		printf("Please enter a number (1 - 9):");
		scanf("%d",&num);
	}while(num < 1 && num > 9);
	printf("Multiplication table for %d number:",num);
	for(i = 1; i <= 10; i++){
		printf("%d x %d = %d\n",num,i,num*i);
	}
	printf("Press enter to continue, Esc to exit.\n");
	key = getch();	
}while(key != 27);
return 0;
}

