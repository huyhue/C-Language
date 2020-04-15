#include<stdio.h>
double gh(int n)
	{
	double T=1;
	for (int i=1;i<=n;i++) T*=(double)i;
	return T;
	}
int main()
{
int n,k;
do
{
printf("nhap n ");
scanf("%d",&n);
printf("nhap k ");
scanf("%d",&k);
} while((n<=0)&&(k<=0)&&(k>n));
printf("Resultf: %.0f",gh(n)/(gh(k)*gh(n-k)));
return 0;
}

