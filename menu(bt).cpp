#include<stdio.h>
#include<math.h>
int  prime( int n ) {
     int m = sqrt(n); /* m: square root of n */
      int i;  /* variable having value from 2 to m  */ 
     if (n<2) return 0; /* Condition 1 is not satisfied */
     for ( i=2; i<=m; i++) /* checking the second condition */
         if (n%i==0) return 0 ; /* n is divided by i ' n is not a prime */
     return 1; /* n is a prime */ 
}
int Fibo(int n) 
{    if(n==1||n==2)  return 1;
return Fibo(n-1)+Fibo(n-2);
}
int  gcd( int a, int b)
int b=a+100;
{  while ( a != b )
       if a>b then a -=b;
       else b -= a;
   return a;
}

int main(){
int choice;
	 int n;
	 printf("nhap vao choice va n:");
    scanf("%d %d",&choice,&n);
	 do   /* Print out the menu and get user choice*/
      {    printf("1- in ra so nguyen to thu n:\n");
            printf("2- in ra phan tu thu n cua day fibo \n");
           printf("3-in ra UCLN cua n va n+100\n");
           printf("Select an operation:");
           scanf("%d",&choice);
           switch(choice) 
               {  case 1: int dem=0, i=2;
               	while(dem<=n){
               		if(prime(i))  dem++; i++;
				   }
				   printf("so nguyen to thu %d la %d ",n,i-1);
               	
                               
                               break;
                  case 2: printf("so fibo thu %d la %d",n,fibo(n));
                               break;
                case 3: printf("the greatest common divisor: %d ",d);
                               break;
                 }
        }
     while ( choice >0 & choice<4); 

return 0;
}

