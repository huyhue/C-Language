/*#include<stdio.h>
int main(){
	int i=1;
for(i=1; i<=10; i++)
{printf("%d",i);}
		
		return 0;
	}*/
	#include <stdio.h>
/*int main(){//thuc hien tong cong tu 1 den 9
	int sum=0, i=1;
	do{ sum+=i;
	i++;
	} while(i<10);
	printf("sum= %d\n",sum);
	return 0;
}*/
#include <stdio.h>
int main()
{int value ;
do{printf("nhap vao mot gia tri >0: \n");
scanf("%d",&value);
}while(value <=0);
printf("gia tri thoa man= %d\n", value);
return 0;
}
