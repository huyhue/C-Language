#include<stdio.h>
#include<string.h>
#define MAXN 100
void menu(){
	printf("-------MENU--------\n");
	printf("1.add some stdent: \n");
	printf("2.search and print out: \n");
	printf("3.range: \n");
	printf("4.highest mark: \n");
	printf("5.remove base on code: \n");
	printf("6.sort: \n");
	
}
int getChoice(){
	int choice;
	printf("what is your choice???  ");
	scanf("%d",&choice);
	return choice;
}
void printList(char codes[][5],char names[][21],float mark[],int n){
	for(int i=0;i<n;i++){
		printf("%d. %9s %21s %10f \n",i,codes[i],names[i],mark[i]);
	}
} 
void add(char codes[][5],char names[][21],float mark[],int *n){
	int ok;
	do{
		printf("%d. Input a code:  ",*n);
		fflush(stdin);
		scanf("%8[^\n]",codes[*n]);
		ok=(codes[*n][0] != 32);
		if(ok){
			printf("name:  ");    fflush(stdin);      scanf("%20[^\n]",names[*n]);
			printf("mark:  ");    fflush(stdin);      scanf("%f",&mark[*n]);
			(*n)++;
		}
	}while(ok);
		printf("after adding: \n"); 
		printList(codes,names,mark,*n);
}
void printName(char ten[], char codes[][5],char names[][21],float mark[],int n){
	int count =0;
	for(int i=0;i<n;i++){
		if(strcmp(names[i],ten)==0)  {
			printf("%d. %9s %21s %10f \n",i,codes[i],names[i],mark[i]);
			count++;
		}
	}
	if(count>0)  printf("have %d studens \n",count);
	else printf("sorry no found \n");
}
void range(char codes[][5],char names[][21],float mark[],int n){
	float max, min;
	printf("Enter min and max: \n");
	scanf("%f %f",&min,&max);
	for(int i=0;i<n;i++){
		if((mark[i]>=min)&&(mark[i]<=max)) 	printf("%10f. %9s %21s \n",mark[i],codes[i],names[i]);
	}
	
}
void high(char codes[][5],char names[][21],float mark[],int n){
	float max=mark[0];
	for(int i=1;i<n;i++){
		if(mark[i]>max)  max=mark[i];
		
	}
	printf("students with highest mark %f have names: %21s and code: %9s",max,names[i],codes[i]);
}
int findCode(char cod[], char codes[][5], int n){
	for(int i=0;i<n;i++){
		if(strcmp(code[i],cod)==0)  return i;
	}
	return -1;
}
void removeCode(char cod[],char codes[][5],char names[][21],float mark[],int *n){
	int pos=findCode(cod,codes,n);
	if(pos>=0) {
		printf("found on %d value is: %s \n",pos,codes[pos]);
	for(int i=pos;i<(*n-1);i++){
		strcpy(codes[i],codes[i+1]);
		strcpy(names[i],names[i+1]);
		mark[i]=mark[i+1];
		(*n)--;	
	}
	printf("after removing: \n");
	printList(codes,names,mark,*n);
	}
	else printf("not found in the list... !");
	
	
	
}
int main(){
	char codes[MAXN][5], names[MAXN][21];
	float mark[MAXN];
	int choice, n=0;
	char ten[21], cod[5];
	menu();
	do{
		choice=getChoice();
		switch(choice){
			case 1:  printf("adding ");
					add(codes, names, mark,&n); break;
			case 2:
					printf("Search and print out \n");
					printf("what do you want to find??? \n"); fflush(stdin);
					scanf("%20[^\n]",ten);
					printName(ten,codes,names,mark,n);
					break;
			case 3:
				printf("range: \n");
				range(codes,names,mark,n);
				break;
			case 4:
				printf("highest mark \n");
				high(codes,names,mark,n);
				break;
		 	case 5:
		 		printf("Remove: \n");
		 		printf("what code do you delete??? \n");   fflush(stdin);
		 		scanf("%4[^\n]",cod);
		 		remove(cod,codes,names,mark,&n);  break;
			
		}
		
		 
	}while((choice>=1)&&(choice<=6));
}
