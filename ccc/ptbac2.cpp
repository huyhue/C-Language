#include <stdio.h>
#include<math.h>
void giaiPTBac2(float a, float b, float c) {
    float d;
	if(a==0)
    {
        if(b==0)
            {
                if(c==0)
                    printf("Phuong trinh co vo so nghiem!");
                else
                    printf("Phuong trinh vo nghiem!");
            }
        else
            printf("Phuong trinh co nghiem duy nhat la: %f",-c/b);
    }
    else
    {
        d=b*b-4*a*c;
        if (d<0)
            printf("Phuong trinh vo nghiem!!!");
        else if (d==0)
            printf("Phuong trinh co nghiem kep la: %f",-b/(2*a));
        else
            printf("Phuong trinh co 2 nghiem phan biet la: %f,%f",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));    
    }    
}
int main()
{
    float a,b,c;
    printf("Nhap vao 3 so a, b, c: ");
    scanf("%f%f%f",&a,&b,&c);
   giaiPTBac2(a, b, c);
    return 1;
  
}
