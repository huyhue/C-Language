//giai va bien luan phuong trinh bac nhat ax+b=0
#include<stdio.h>
int main()
{ 
float a, b;
scanf("%f%f",&a, &b);
if(a==0 && b== 0) printf("phuong trinh vo so nghiem.");
else if(a == 0 && b != 0) printf("phuong trinh vo nghiem.");
else printf("phuong trinh co nghiem x= %0.2f", -b/a);
return 0;

}

