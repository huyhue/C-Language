/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
int main(){
srand(time(NULL));
int i;
int arr[MAX];
for(i=0;i<MAX;i++){
	arr[i]=rand();
} 
	for(i=0;i<MAX; i++){
		printf("arr[%d]= %d \n",i,arr[i]);
	}
return 0;
}*/
#include<stdio.h>
#define LENGTH 5
int *nhap(){
	static int arr[LENGTH];	
	int i; 
	for(i=0;i<LENGTH; i++){
		scanf("%d",&arr[i]);
	}
	return arr;
}
void hienThi(const int arr[])
{
	int i;
	for(i=0;i<LENGTH;i++){
		printf("%5d",arr[i]);
	}
	printf("\n");
}
void bubbleSort(int arr[]){
	int i,j;
	for(i=0;i<LENGTH-1;i++){
		for(j=LENGTH-1;j>i;j--){
			if(arr[j]<arr[j-1]){
				int tmp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=tmp;
			}
		}
	}
}
int main()
{
 int *arr;
	arr=nhap();
	printf("\ntruoc sap xep:");
	hienThi(arr);
	printf("\nsau sap xep:");
	bubbleSort(arr);
	hienThi(arr);
	return 0;
}

