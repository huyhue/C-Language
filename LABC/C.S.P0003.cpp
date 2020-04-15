#include<stdio.h>
#define MAX 100
void output(int arr[], int n){
	for(int i = 0;i<n;i++){
		printf("%5d",arr[i]);
	}
}
void newValue(int arr[],int *n,int value){
    arr[*n] = value;
    (*n) = (*n) + 1;
}
int sort(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i ;j--)
		if(a[j]<a[j-1]){
			int t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;	
		}
	}
}
int main(){
	int n;
	int arr[MAX];
	printf("The program must have interface as below:\n");
	printf("\n");
	printf("Please enter size of array: ");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		printf("Enter element[%d]:",i);
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	output(arr,n);
	int v;
	printf("\nPlease enter new value:");
	scanf("%d",&v);
	printf("New array:\n");
	newValue(arr,&n,v);
	sort(arr,n);
	output(arr,n);
return 0;
}

