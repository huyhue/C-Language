#include<stdio.h>//nhapvao so bat ky, kiem tra xem so do phai la so nguyen to khong
int main(){
	//c�i d?t bi?n x luu gi� tr? c?a m?t con s? n�o d�, v� d? nhu ? d�y, t�i l?y x = 13;
int x;
 
//c�i d?t bi?n flag v?i gi� tr? l� 0
int h = 0;
 
//v�ng l?p n�y d? ki?m tra x c� ph?i l� s? nguy�n t? kh�ng
int i = 2;
printf("nhap vao so bat ky:");
scanf("%d",&x);
while ( i < x )
{
	if ((x % i) == 0)
	{
		//khi x chia h?t cho m?t s? b?t k? th� x kh�ng ph?i l� s? nguy�n t?
		h = 1;
	}
	i = i + 1;
}
 
//d?a tr�n gi� tr? c?a bi?n flag m� ta quy?t d?nh x l� s? nguy�n t? hay kh�ng
if (h == 0)
{
	printf("x la so nguyen to");
}
else
{
	printf("x khong phai so nguyen to");
}

}


