#include <stdio.h>//tinh trung binh cong cac so vua nhap, tinh gia tri max, min trong gia tri vua nhap, nhap den 0 thi stop
int main (){
/*	int x, min, max, dem=0 ,s=0 ;
	do{
		scanf("%d",&x);
		if(!dem){
		s+=x;
		min=x; max=x;
	}
		dem+=1;
			if(x<min) min=x;
		if(x>max) max=x;
		}
		while(x!=0);
		printf("s= %d \n",s);
		printf("trung binh cong %f",1.0*s/(dem-1));
		printf("\nmin=%d, max=%d", min, max);
		getchar();
		getchar();
		return 0;
		}*/
		int x, sum,i=0;//chay chua duoc hoi ban nhe
		scanf("%d",&x);
		int min= max=x;
	
		while(x!=0){
			sum+=x;
			if(max<x) max=x;
			if(min>x) min=x; i++;
			scanf("%d",&i);
	}
	printf("average of sum",sum/i);
	printf("sum:%d, min:%d, max:%d",sum,min, max);
	getchar();
	return 0;}
		
