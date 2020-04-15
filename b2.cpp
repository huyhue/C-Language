#include <stdio.h>
#include <conio.h>
#include <math.h>
   main()  {
   	//viet chuong trinh cong tru nhan chia hai so;
   	float a,b, cong, tru, nhan, chia;
   	printf("nhap vao a: a= ");
   	scanf("%f", &a);
   		printf("nhap vao b: b= ");
   	scanf("%f", &b);
   	printf("hai so vua nhap la: %0.1f,%0.2f", a,b );
   	cong= a+b;
   	tru = a-b;
   	nhan=a*b;
   	chia=a/b;
   	printf("\n ketqua tim duoc la: %0.1f, %0.1f, %0.1f, %0.1f", cong, tru, nhan, chia );
   	}
