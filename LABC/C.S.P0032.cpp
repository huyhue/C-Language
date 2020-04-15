#include<stdio.h>
#include<conio.h>
int main(){
	printf("Sum Digit Program\n");
	int n, num;
	char key;
	int s=0;
	while(true){
		printf("Enter an integer n=");
		scanf("%d",&n);
		while(n != 0){
			num = n % 10;
			s += num;
			n = n/10;
		}
		printf("Sum digit = %d\n",s);
		printf("Press any key to continue.\n");	
		scanf("%s",&key);
		if(key == 27){
			break;
		}
	}
return 0;
}

