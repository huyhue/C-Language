#include<stdio.h>  
#include<conio.h>  
int main()  
{  
int a[50],n,i;  
 printf("Nhap mot so thap phan: ");  
scanf("%d",&n);  
for(i=0;n>0;i++)  
{  
a[i]=n%2;  
n=n/2;  
}  
printf("\nso nhi phan cua so vua nhap la = ");  
for(i=i-1;i>=0;i--)  
{  printf("%d",a[i]); }  
 }  
