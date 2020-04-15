#include <stdio.h>
int main()
{ int n,t;
printf("nhap vao so dien n=",n);
scanf("%d", &n);
if(n<=100)t=n*950;
else if(n<=150)t=100*950+(n-100)*1250;
else if(n<=200)t=100*950+50*1250+(n-150)*1350;
else t=100*950+50*1250+50*1350+(n-200)*1555;
	printf("number of prices is t= %d\n",t);
	return 0;
	
}

