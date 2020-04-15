#include<stdio.h>//nhapvao so bat ky, kiem tra xem so do phai la so nguyen to khong
int main(){
	//cài d?t bi?n x luu giá tr? c?a m?t con s? nào dó, ví d? nhu ? dây, tôi l?y x = 13;
int x;
 
//cài d?t bi?n flag v?i giá tr? là 0
int h = 0;
 
//vòng l?p này d? ki?m tra x có ph?i là s? nguyên t? không
int i = 2;
printf("nhap vao so bat ky:");
scanf("%d",&x);
while ( i < x )
{
	if ((x % i) == 0)
	{
		//khi x chia h?t cho m?t s? b?t k? thì x không ph?i là s? nguyên t?
		h = 1;
	}
	i = i + 1;
}
 
//d?a trên giá tr? c?a bi?n flag mà ta quy?t d?nh x là s? nguyên t? hay không
if (h == 0)
{
	printf("x la so nguyen to");
}
else
{
	printf("x khong phai so nguyen to");
}

}


