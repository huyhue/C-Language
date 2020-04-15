#include<stdio.h>
#include<string.h>
#define MAX 100
#include <stdlib.h>
void menu();
int getChoice();
void enterMArray(int a[], int n);
void display(int a[], int n);
int findX(int a[], int n, int X);
void sortArray(int a[], int n);
void XoaPhanTu(int a[], int &n, int pos);
void menu(){
	printf("-----------Menu------------\n");
	printf("1. Enter a manual array\n");
	printf("2. Display an array\n");
	printf("3. Find X value in Array, return its index\n");
	printf("4. Sort an array and display them\n");
	printf("5. Remove X value in an array\n");
	printf("6. Exits\n");
}
int getChoice(){
	int choice;
	printf("What do you choice ? ");
	scanf("%d",&choice);
	return choice;
}

void enterMArray(int a[], int n){
	for(int i=0;i<n;i++){
		printf("Enter array:a[%d]=",i);
		scanf("%d",&a[i]);
	}
}

void display(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
int findX(int a[], int n, int X){
	for(int i=0;i<n;i++){
		if(X==a[i]) printf("It have index is %d\n",i);
			return 1;
	}
	return 0;
}
void sortArray(int a[], int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
}
void XoaPhanTu(int a[], int &n, int pos){
    // Dich chuyen mang
    for(int i = pos; i < n - 1; i++){
        a[i] = a[i+1];
    }
    // Giam so luong phan tu sau khi xoa.
    --n;
}

int main(){
	int choice;
	menu();
	int a[MAX];
	int n = 5;
	int pos;
	do{
		choice=getChoice();
		switch(choice){
			case 1:
				enterMArray(a,n);
				break;
			case 2:
				display(a,n);
				break;
			case 3:
				int X;
				printf("what do you number find?");
				scanf("%d",&X);
				if(findX(a,n,X)==1){
					printf("Have this number in array\n");
				}else{
					printf("Dont have this number in array\n");
				}	
				break;
			case 4:
				sortArray(a,n);
				display(a,n);
				break;
			case 5:	
				printf("what position you want remove?\n");
				scanf("%d",&pos);
				XoaPhanTu(a,n,pos);
				printf("Array after remove: ");
				display(a,n);
				break;
			default: printf("Bye. Exit now\n");
		}
	}while((choice>0)&&(choice<6));
return 0;
}

