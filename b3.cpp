#include <stdio.h>
#include <conio.h>
#include <math.h>
   main()  {
   	//tinh tong hieu tich thuongcua hai phan so a/b, c/d
   	float a,b,c,d;
   	printf("nhap vao cac so a, b, c, d");
   	scanf(" %f %f %f %f", &a, &b, &c, &d);
   	
   	printf("\n tong la: %0.1f/ %0.1f", a*d+b*c, b*d);
   	printf("\n hieu la: %0.1f/ %0.1f", a*d-b*c, b*d);
   	printf("\n tich la: %0.1f/ %0.1f", a*c, b*d);
   	printf("\n thuong la: %0.1f/ %0.1f", a*d,b*c);
   	}
