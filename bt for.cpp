/*#include<stdio.h>//in ra man hinh cac so chan le nho hon n
int main(){
	int n;
printf("nhap vao so tu nhien n:");
	scanf("%d",&n);
		printf("\nso do la so chan cua  %d:",n);
	for( int i=0;i<=n;i++)
	{if(i%2 ==0) printf("%5d",i);
	}
	printf("\nso do la so le cua %d:",n);
	for(int i=0;i<=n;i++)
	{if(i%2 !=0) printf("%5d",i);
	}
	return 0;
}
 /*#include<stdio.h>//nhap n roi tinh tong so tu nhien be hon n, sum so le, so chan be hon n
/*int main()
{int n,i;
printf("nhap vao cac so tu nhien n:");scanf("%d",&n);
int s, s1, s2;
s=s1=s2=0;
for( i=1;i<=n;i++){
	s+=i;
	if(i%2==0) s1+=i;
	if(i%2!=0) s2+=i;
}
printf("S= %d\n",s);
printf("S1= %d\n",s1);
printf("S2= %d\n",s2);
return 0;}
*/
/*#include<stdio.h>//S=1+1/2+1/3+..+1/n
int main(){
	int n;
	printf("nhap vao cac so tu nhien n:");scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++) sum+=1./i;
	printf("tong la sum: %0.2lf",sum);
	return 0;*/
/*#include<stdio.h>//nhap so nguyen duong n va tinh s=1+1*2+1*2*3+...+1*2*...*n
	int main(){
		int n;
	printf("nhap vao cac so tu nhien n:");scanf("%d",&n);
	unsigned long long sum=0, giaiThua=1;
	for(int i=1;i<=n;i++) {giaiThua*=i;
sum+=giaiThua;	
	}
	printf("ket qua la sum: %lld",sum);
	return 0;
		
	}*/
/*#include <stdio.h>//tinh tong cac so tu nhien khong lon hon n va chia het cho 7
int main(){
	int n,i;
	int sum=0;
	printf("nhap vao cac so tu nhien n:"); scanf("%d",&n);
	for(i=1;i<=n;++i) 
	if(i%7==0)
	sum+=i;
	printf("tong cua bai toan la: %d", sum);
	return 0;
}*/
	#include<stdio.h>//tinh tong n+(n-2)+(n-4)+...+0
int main(){
	int n,i;
printf("nhap vao so tu nhien n:");
	scanf("%d",&n);
	int s=0;
		for(i=n;i>0;i-=2) s+=i;
		printf("tong cua bieu thuc la:%d",s);
		return 0;}
/*	#include<stdio.h>//tinh tong 
	#include<math.h>
int main(){
	int n,i;
printf("nhap vao so tu nhien n:");
	scanf("%d",&n);
	int s;
		for(i=1;i>n;i+=1) s+= 1.0/pow(i,i-1);
		printf("tong cua bieu thuc la:%d",s);
		return 0;}*/
	
	


