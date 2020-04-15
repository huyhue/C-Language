#include<stdio.h>
#include<conio.h>
int main(){
	int n, num[100];
	int s = 0;
	char c;
	do{
		printf("Dynamic memory allocation\n");
		printf("Number of element s = ");
		scanf("%d",&n);
		for(int i = 0; i < n;  i++){
			printf("Enter an integer: ");
			scanf("%d",&num[i]);
			s += num[i];
		}
		printf("Sum = %d\n",s);
		printf("Press any key to continue.\n");
		c = getch();
		if(c == 27){
			break;
		}
	}while(true);
return 0;
}

