/*#include<stdio.h>
void vechu( char chu, int soluong)
{
	int i;
	for(i=0;i<=soluong;++i)
	printf("%c",chu);

}

int main(){
vechu('h',20);
return 0;
}*/
/*#include<stdio.h>//tinh N!= 1.2.3...n
long giaiThua(int n)
{
	long gt=1;
	 int i;
	 for(i=2;i<=n;i++)
	 {
	 	gt*=i;
	 	} 
		 return gt;
}
int main()
{
	printf("5! =%ld\n",giaiThua(5));
	printf("6!+1 =%ld\n",giaiThua(6)+1);
	return 0;
}*/
/*#include<stdio.h>
int KiemTraChiaHet (int n)
{
	if(n%2==0&&n%5==0)
	{
		return 1;
	}	
	return 0;
}
int main()
{
	int x;
	printf("nhap x=");
	scanf("%d",&x);
	if(KiemTraChiaHet(x)==0)
	{
		printf("day khong phai la so dep\n");
	}
	else {
		printf("day la so dep \n");
	}
	return 0;
}
	*/
	/*#include<stdio.h>
int max2(int a, int b)
{
	return a>b?a:b;
}
int max3(int a, int b, int c)
{
	return  max2(max2(a,b), c);
}
int main()
{
	int a=7,b=13, c=4;
	printf("so lon nhat la %d\n", max3(a,b,c));
	return 0;
}*/
/*#include<stdio.h>
int giaiThua(int n)
{
	{if(n==0) return 1;
	}
	return giaiThua(n-1)*n;
}
int main()
{
	int n=5;
	printf("%d!=%d", n, giaiThua(n));
	return 0;
	
}*/
#include<stdio.h>
#define tong(x,y) x+y
int main()
{
	int a=5, b=8;
	printf("%d+%d=%d",a,b,tong(a,b));
	return 0;
}




