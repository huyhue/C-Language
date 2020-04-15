#include<stdio.h>
int main()
{
int a,b,n,stt=1 ;
char x;
printf("Enter an expression(+ - * /):");
scanf("%d%c%d",&a,&x,&b);
switch(x){
	case '+': n=a+b; break;
	case '-': n=a-b; break;
	case '*': n=a*b; break;
	case '/':
		if (b==0){
			printf("Divide by 0/n");
			stt=0;
		}
		else (n=a/b);
		break;
		default: {
			printf("op is not supported");
			stt=0;
		}
}
if (stt!=0)  printf("Result: %d",n);
getchar();
getchar();
return 0;
 }
