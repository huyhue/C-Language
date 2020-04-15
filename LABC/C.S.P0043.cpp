#include<stdio.h>
#define MAX 100
void output(int arr[MAX],int n);
void menu(){
	printf("1- Add a value\n");
	printf("2- Search a value\n");
	printf("3- Remove the first existence of a value\n");
	printf("4- Remove all existences of a value\n");
	printf("5- Print out the array\n");
	printf("6- Sort the array in ascending order (positions of elements are preserved)\n");
	printf("7- Sort the array in descending order (positions of elements are preserved)\n");
	printf("Others- Quit\n");
}
void input(int arr[MAX],int *n){
	printf("Input an integer arr[%d] = ",*n);
	int m;
	scanf("%d",&m);
	arr[*n] = m;
	(*n) = (*n) + 1;
	output(arr, *n);
}
void output(int arr[MAX],int n){
	for(int i = 0; i < n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int find(int value,int *arr, int n){
	for(int i = 0; i < n;i++){
		if(arr[i] == value){
			return i;
		}
	}
	return 0;
}
void search(int value,int *arr, int n){
	int pos = find(value,arr,n);
	if(pos == 0){
		printf("%d isnot find in array.\n",value);
	}else{
		printf("%d is find in array.\n",value);
	}
	
}
void removeFirst(int del,int *arr,int *n){
		int pos;
		for(int i = 0; i < *n; i++){
		if(arr[i] == del){
			pos = i;
			(*n)--;
			for(int i=pos;i<*n;i++){
				arr[i]=arr[i+1];
			}
		}
	}
	output(arr,*n);
}
void removeAll(int dele,int *arr,int *n){
	for(int i = 0;i < *n; i++){
		if(arr[i] == dele){
			for(int j=i+1;j<*n;j++){
				arr[j-1]=arr[j];
				(*n)--;
			}
		}		
	}
	output(arr,*n);
}
void sortAscend(int *arr, int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1 ;j > i; j--){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	printf("After sorting ascend:\n");
	output(arr,n);
}
void sortDescend(int *arr, int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1 ;j > i; j--){
			if(arr[j] > arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	printf("After sorting descend:\n");
	output(arr,n);
}
int main(){
	int arr[MAX], value, del, dele;
	int n = 0;
	int m;
	int choice;
	menu();	
	do{
		printf("What do you choice ???\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				input(arr, &n);
				break;
			case 2:
				printf("Input an integer to search:");
				scanf("%d",&value);
				search(value, arr, n);
				break;
			case 3:
				printf("Input an integer to remove the first ocurrence:");
				scanf("%d",&del);
				removeFirst(del,arr,&n);
				break;
			case 4:
				printf("Input an integer to remove all the ocurrence:");
				scanf("%d",&dele);
				removeAll(dele,arr,&n);
				break;
			case 5:
				printf("Display all the array's an.\n");
				output(arr,n);
				break;
			case 6:
				sortAscend(arr,n);
				break;
			case 7:
				sortDescend(arr,n);
				break;
			default:
				break;
		}
	}while(choice > 0 && choice < 8);
return 0;
}

