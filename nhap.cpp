/*#include<stdio.h>
#include<stdlib.h>
int main(){
double *p1, *p2;//khai bao hai con tro
p1 = (double*) malloc ( sizeof(double));// cap phat 2 con tro moi em 8byte 
p2 = (double*) malloc ( sizeof(double));
printf("p1, address: %u, value: %u\n", &p1, p1);
printf("p2, address: %u, value: %u\n", &p2, p2);
printf("Input 2 numbers:");
scanf( "%lf%lf", p1, p2);
printf("Sum: %lf\n", *p1 + *p2);
printf("Difference: %lf\n", *p1 - *p2);
printf("Product: %lf\n", *p1 * (*p2));
printf("Quotient: %lf\n", *p1 / *p2);
return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
void swap(char *pc1, char *pc2)
{
	int t= *pc1;
	*pc1=*pc2;
	*pc2=t;
}
int main()
{
	char *pc1, *pc2;
	pc1 = (char*) malloc ( sizeof(char));// cap phat 2 con tro moi em 8byte 
	pc2 = (char*) malloc ( sizeof(char));
	printf("nhap vao 2 ky tu:");
	scanf("%c %c", pc1,pc2);
	if(*pc1 >*pc2) {
		swap(pc1, pc2);
	}
	char c;
	for(c= *pc1; c<=*pc2;c++)
{
	printf("%c, %4d, %4o,%4X\n",c,c,c,c);
	}	
	return 0;
}
