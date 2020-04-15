#include<stdio.h>
int sumBetween(int a, int b) //nhap vao 2 so nguyen, roi in ra tong cac so nguyen giua chung.
{
	int t;
	if(a>b)
	{
		t=a; a=b; b=t;// a must be less than b
	}
	int S=0;
	for (t=a;t<=b; t++) S+=t;
	return S;
}

void printfAscii(char c1, char c2)
 {
 	char c;
if(c1>c2)
{
	c=c1;c1=c2;c2=c;
}
for(c=c1;c<=c2;c++)
printf("%c,%3d,%3oq,%3Xh",c,c,c,c);

 }
int main()
 {
 	int choice;
 	printf("enter choice");
					scanf("%d ",&choice);
	 do{
 		switch(choice)
 		{
 			case 1:{
					int n1, n2;
					printf("enter 2 integers:");
					scanf("%d %d*c",&n1,&n2);
					printf("Sum=%d \n", sumBetween(n1,n2));
	 				return 0;
					}
			 break;
 			case 2: { 
			 char c1,c2;
 					printf("enter 2 characters contigously:");
					scanf("%c %c",&c1,&c2);
					printfAscii(c1,c2);
			 }
			 break;
 			default: printf("bye!\n");
		 }
	 } while (choice >0&& choice <3);
	 return 0;
 }


