#include<stdio.h>
#include<conio.h>
void main() {
int n;
printf("nhap so thap phan:");
scanf("%d",&n);
char a[50];
chuyenDoi(n;a);
}
int chuyenDoi(int n, char a[50])
{int coso=2;
int dem=0,i;
while(n>0)
{a[dem]=n%coso;
n=n/coso;
dem++;
}

for(i=dem-1;i>=0;i--){
	printf("so nhi phan la: %d", a[i])
} }


