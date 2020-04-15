/*#include<stdio.h>
int gcd( int value1, int value2)
{
	while(value1 != value2)
	if(value1>value2)  value1-=value2;
	else value2-=value1;
	return value1;
}
int lcm(int value1, int value2)
{
	return (value1*value2)/gcd(value1, value2);
	
}

int main(){
int m, n, L, G;
do 
{
	printf("Input 2 positives interger:");
	scanf("%d%d",&m,&n);
}
while (m<=0||n<=0);

printf("GCD: %d, LCM: %d\n",gcd(m,n), lcm(m,n));
getchar();
getchar();
return 0;
}*/
/*#include<stdio.h>
unsigned long long fibo(int n)
{
	if(n==1||n==2)  	return 1;
	return fibo(n-1)+fibo(n-2);
}
int main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		printf("fibo(%d)= %lld\n",i,fibo(n));
	}
	return 0;
}*/
/*#include<stdio.h>
#include<conio.h>
double fibo(int n)
{
	int f1=1, f2=1, f=1;
	for(int i=3; i<=n; ++i)
	{
		f=f1+f2;
		f1=f2;
		f2=f;
	}
	return f;
}
int main()
{
	int n;
	do{
		printf("n=");
		scanf("%d",&n);
	}
	while(n<1);
	for(int i=1; i<=n; i++)  printf("%0.0lf", fibo(i));
	getch();
}*/
#include<stdio.h>
#include<conio.h>
double fibo(int n)
{
	int 
}
















