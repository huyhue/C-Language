#include<stdio.h>
#include<stdlib.h>
int i = 0;
int n[100];
int menu(){
	int choice;
	printf("\n1- Add a value\n");
	printf("2- Search a value\n");
	printf("3- Print out the array\n");
	printf("4- Print out values in a range of inputted min and max values, inclusively\n");
	printf("5- Sort the array in ascending order\n");
	printf("Others- Quit\n");
	printf("What do you choice?  ");
	scanf("%d",&choice);
	return choice; 
}
void Add(){	
	int num;
	printf("\nInput an integer: ");
	scanf("%d",&num);
	n[i] = num;
	printf("Add successing...\n");
	i++;
}
int Find(int num){
	for(int j =0 ;j<i;j++){
		if(n[j]==num){
			return j;
		}else{
			return -1;
		}	
	}

}
void Index(){
	int num;
	printf("\nInput an integer: ");
	scanf("%d",&num);
	if(Find(num)==-1){
		printf("No have an integer\n");
	}else{
		printf("An integer have index: %d\n",Find(num));
	}
}
void Display(){
	printf("\nDisplay all the array's elements.\n");
	for(int j=0;j<i;j++){
		printf("%d ",n[j]);
	}
	printf("\n");
}
void Range(){
	int min, max;
	printf("\nEnter min values: ");
	scanf("%d",&min);
	printf("Enter max values: ");
	scanf("%d",&max);
	for(int j=0;j<i;j++){
		if(n[j]>min && n[j]<max){
			printf("%d ",n[j]);
		}
	}
}
void Sort(){
	for(int j=0;j<i-1;j++){
		for(int k=i-1;k>j;k--){
			if(n[k]<n[k-1]){
				int t=n[k];
				n[k]=n[k-1];
				n[k-1]=t;
			}
		}
	}
	Display();
}
int main(){
	int c;
	do{
		c = menu();
		system("cls");
		switch(c){
			case 1:
				Add();
				break;
			case 2:
				Index();
				break;
			case 3:
				Display();
				break;
			case 4:
				Range();
				break;
			case 5:
				Sort();
				break;
			default:
				exit(1);
		}
	}while(c > 0 && c < 6);
return 0;
}

