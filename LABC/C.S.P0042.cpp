#include<stdio.h>
#define MAX 100
int main(){
	int arr[MAX];
	int i = 0;
	printf("Enter the elements of the array\n");
	do{
		scanf("%d",&arr[i]);
		if(arr[i] != 0){
			i++;
		}
	}while(arr[i] != 0);
	
	printf("\nArray elements:\n");
	for(int j = 0;j < i; j++){
		printf("%d ",arr[j]);
	}
	
	printf("\n");
	printf("\nArray maxinum value:\n");
	int max = 0;
	for(int j = 0; j < i; j++){
		if(arr[j] > max) max = arr[j];
	}
	printf("The max is %d\n",max);
	
	
	printf("\nArray even values:\n");
	for(int j = 0; j < i; j++){
		if(arr[j] % 2 == 0) 
		printf("%d ",arr[j]);
	}
	
return 0;
}

