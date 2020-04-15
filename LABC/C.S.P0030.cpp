#include<stdio.h>
int main(){
	int n, e;
	int s1=0,s2=0;
	printf("Sum Even Odd program\n");
	printf("Enter a number of element n=");
	scanf("%d",&n);
	printf("Input elements:\n");
	for(int i=1;i<=n;i++){
		printf("\tElement %d=",i);
		scanf("%d",&e);
		if(e%2==0){
			s1+=e;
		}else{
			s2+=e;
		}
	}
	printf("Sum of Even=%d\n",s1);
	printf("Sum of Odd=%d",s2);
return 0;
}

