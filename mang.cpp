/*#include<stdio.h>
int main(){
	int n=5, i, s=0;
	int a[n];
for(i=0;i<n;i++)
{
	printf("nhap a[%d]",i);
	scanf("%d",&a[i]);
}
printf("\n mang da nhap \n");
for(i=0; i<n;i++)
{
	printf("%d \t",a[i]);}
	for(i=0; i<n; i++)
	{
		s+=a[i];	
	}
	printf("\n tong cac so trong mang: %d \n",s);
return 0;
}*/
/*#include<stdio.h>
void nhapMang(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("nhap a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatMang(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
int main()
{
	int n=5;
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	return 0;
}*/
#include<stdio.h>
#define MAX 10
void nhapMang(int a[MAX][MAX],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("nhap a[%d][%d]",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatMang(int a[MAX][MAX],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%-3d",a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n=2, m=3;
	int a[MAX][MAX];
	nhapMang(a,n,m);
	xuatMang(a,n,m);
	return 0;
}


