#include<stdio.h>
#include<string.h>
#define MAX 100
#include <stdlib.h>
void menu();
int getChoice();
void info(FILE *f);
void takingSum(int n);
void displayPerfect(int limit);
void takingSumP(int n);
void enterMArray(int a[], int n);
void enterRArray(int a[], int n);
void display(int a[], int n);
int findX(int a[], int n, int X);
void sortArray(int a[], int n);
void XoaPhanTu(int a[], int &n, int pos);
void menu(){
	printf("-----------Menu------------\n");
	printf("1. Student Information.\n");
	printf("2. Calculate Sum\n");
	printf("3. Print out perfect number from 1 to limit\n");
	printf("4. Using pointer to calcuate Sum\n");
	printf("5. Enter a manual array\n");
	printf("6. Enter a random array from 20 to 40\n");
	printf("7. Display an array\n");
	printf("8. Find X value in Array, return its index\n");
	printf("9. Sort an array and display them\n");
	printf("10. Remove X value in an array\n");
	printf("11. Exits\n");
}
int getChoice(){
	int choice;
	printf("What do you choice ? ");
	scanf("%d",&choice);
	return choice;
}
void takingSum(int n){
	double sum=0,gt=1;
	for(int i=1;i<=n;i++){
		gt*=i;
		sum +=gt;
	}
	printf("Calculate the sum: %lf \n",sum);
}
void info(FILE *f){
	char name[MAX], lop[MAX], university[MAX], field[MAX];
	printf("Enter your name:\n"); fflush(stdin);
	gets(name);
	fprintf(f, "Your Name: = %s\n", name); 
	printf("Enter your class:\n");fflush(stdin);
	scanf("%s",lop);
	fprintf(f, "Your Class: = %s\n", lop);
	printf("Enter your university:\n");fflush(stdin);
	scanf("%[^\n]",university);
	fprintf(f, "Your University: = %s\n", university);
	printf("Enter your field:\n");fflush(stdin);
	scanf("%[^\n]",field);
	fprintf(f, "Your Field: = %s\n", field);
}
void displayPerfect(int limit){
 	for(int i=1;i<limit;i++){
 		if((i%2==0)&&(i%7==0)){
 			printf("%d \n",i);
		 }
	}
}
void takingSumP(int n){
	double sum=0;
	for(int i=1;i<=n;i++){
		sum+=(double)1/i;
	}
	printf("Sum of function: %lf\n",sum);
}
void enterMArray(int a[], int n){
	for(int i=0;i<n;i++){
		printf("Enter array:a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void enterRArray(int a[], int n){
	int i;
	for(i=20;i<=n;i++){
		int ramdom=i+rand()%n;
		printf("a[%d]=%d\n",i,ramdom);
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
    // Mang rong, khong the xoa.
    if(n <= 0){
        return;
    }
    // Neu pos <= 0 => Xoa dau
    if(pos < 0){
        pos = 0;
    }
    // Neu pos >= n => Xoa cuoi
    else if(pos >= n){
        pos = n-1;
    }
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
				FILE *f;
				f = fopen("C:/Users/ASUS/Desktop/exam.txt","w+");
				if(f==NULL){
					printf("NULL");
					exit(1);//thu vien stdlib.h
				}
				info(f);
				fclose(f); break;
			case 2:
				int n;
				printf("Enter the n:");
				scanf("%d",&n);
				takingSum(n);
				break;
			case 3:
				displayPerfect(100);
				break;
			case 4:
				takingSumP(5);
				break;
			case 5:
				enterMArray(a,n);
				break;
			case 6:
				int b[40];
				enterRArray(b,40);
				break;
			case 7:
				display(a,n);
				break;
			case 8:
				int X;
				printf("what do you number find?");
				scanf("%d",&X);
				if(findX(a,n,X)==1){
					printf("Have this number in array\n");
				}else{
					printf("Dont have this number in array\n");
				}	
				break;
			case 9:
				sortArray(a,n);
				display(a,n);
				break;
			case 10:	
				printf("what do you want remove?\n");
				scanf("%d",&pos);
				XoaPhanTu(a,n,pos);
				printf("Array after remove: ");
				display(a,n);
				break;
			default: printf("Bye. Exit now\n");
		}
	}while((choice>0)&&(choice<11));
return 0;
}

