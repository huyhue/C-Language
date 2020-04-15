#include <stdio.h>
#include <math.h>

float amount(float d,float r,int n){
    return d * pow((1+r),n);
}
int main(){
    float d,r;
    int n;
  do{
	   	printf("enter deposit: ");
	    scanf("%f",&d);
	   } while(d<0);
	do{
	   	printf("enter yearly rate: ");
	    scanf("%f",&r);
	   } while(0.0>r>1.0);
	do {
	   	printf("enter number of year: ");
	    scanf("%d",&n);
	   }while(n<0);
    for(int i=1;i<=n;i++){
        printf("%d of %f\n",i,amount(d,r,i));
    }
    return 0;
}
