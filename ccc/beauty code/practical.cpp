#include <stdio.h>
#include<string.h>
#define MAXN 20

void add(char codes[][5], char names[][21], float mark[], int *n);
void printName(char ten[], char codes[][5], char names[][21],float mark[], int n);
void removeCode(char cod[], char codes[][5], char names[][21], float mark[], int *n);
void sortList(char codes[][5], char names[][21], float mark[], int n);
void high(char codes[][5], char names[][21], float mark[], int n);  
void range(float mark[], int n);
void menu();
int getchoice();
//------------------------Main function-------------------------------------
int main() {
	char codes[MAXN][5], names[MAXN][21];
	float  mark[MAXN];
	char ten[21], cod[5];
	int choice,n=0;
	
	menu();
	do {
	 	choice=getchoice();
        switch (choice) {
        	case 1:	printf("---  Add some new students  --- \n");
        			add(codes,names,mark, &n);
					break;
    		case 2:	printf("---  Search and print out students using a name inputted --- \n");
    				printf("What name do you want to print? "); fflush(stdin); scanf("%20[^\n]",ten);
    				printName(ten, codes, names, mark, n);
    				break;
    		case 3:	printf("--- Print out students in a range ---\n");
    				range(mark,n);
    				break;
    		case 4: printf("--- Print out students with the highest mark. --- \n"); 
					high(codes,names,mark,n);
    				break;
    		case 5:printf(" Remove a student based on a code inputted");
    				printf("What code do you want to delete? "); fflush(stdin); scanf("%4[^\n]",cod);
    				removeCode(cod, codes, names, mark, &n);
    				break;
    			
    		case 6:printf("Print out the list based on name in ascending order then mark in descending order");
    				sortList(codes, names, mark, n);
    				break;
    		default: printf("Bye... \n");
        }              
    } while ((choice>=1) && (choice<=6));
	return 0;
	
}
//---------------------- Implement functions---------------------------------------
void printList(char codes[][5], char names[][21], float mark[], int n){  
	for( int i=0;i<n;i++) 
		printf("%d.%9s%21s%10f \n",i,codes[i],names[i],mark[i]);
}
void add(char codes[][5], char names[][21], float mark[], int *n){
	int ok; 
	do{ // *Note: press keySPACE for codes[i] to exit
		printf("%d-------- Input a code: ",*n); fflush(stdin);	scanf("%8[^\n]",codes[*n]); //gets(code);
		ok=(codes[*n][0]!=32);  //ok=(codes[0]!=' '); 
		if (ok) {
			printf("name: "); 		fflush(stdin);	scanf("%20[^\n]",names[*n]);
			printf("mark: ");		fflush(stdin);	scanf("%f",&mark[*n]);

			(*n)++;
		}
	}while (ok);
	printf("After adding: \n");	 
	printList(codes, names, mark, *n);
}
void printName(char ten[], char codes[][5], char names[][21],float mark[], int n){
	int count=0;
	for (int i=0;i<n;i++)
		if (strcmp(names[i],ten)==0) {
			printf("%d.%9s%21s%10f \n",i,codes[i],names[i],mark[i]);
			count++;
		}
	if (count>0) printf("have %d student\n",count);
	else printf("sorry, not found...!\n");			
}

int findCode(char cod[], char codes[][5],  int n){ //Find the position of a known code   
 	for (int i=0; i<n;i++)
		if (strcmp(codes[i],cod)==0)	return i;
	return -1;
}
void removeCode(char cod[], char codes[][5], char names[][21], float mark[], int *n){
	int pos=findCode(cod,codes,*n);
	if (pos>=0){
		printf("found on %d    value is: %s \n",pos,codes[pos]);
		for (int i=pos;i<(*n-1);i++){
			strcpy(codes[i],codes[i+1]);
			strcpy(names[i],names[i+1]);
			mark[i]=mark[i+1];	
		}
		(*n)--;
		printf("After deleting: \n");	
		printList(codes, names, mark, *n);	
	}
	else	printf("Not found in the list...! \n");	
}
void swapFloat(float *a, float *b){
	float t;
	t=*a; *a=*b; *b=t;
}
void swapString(char a[], char b[]){
	char t[21];
	strcpy(t,a); strcpy(a,b); strcpy(b,t);
}
void sortList(char codes[][5], char names[][21], float mark[][10], int n){   
	for (int i=0; i<n-1; i++)
      	for (int j=n-1; j>i; j-- ){   
        	if (strcmp(names[j],names[j-1])>0&&strcmp(mark[j],mark[j-1])<0){    
					swapString(codes[j], codes[j-1]);
                    swapString(names[j], names[j-1]);
                    swapFloat(&mark[j], &mark[j-1]);
            } 
       }
    printf("After sorting: \n");	 
	printList(codes, names, mark, n);
	
	
}  
void range(float mark[], int n){
	float maxVal, minVal;
	printf("Enter minVal and maxVal:\n");
	scanf("%f %f",&minVal, &maxVal);
	printf("\nvalue in a range from %f to %f:  ",minVal,maxVal);
	 for (int i=1; i<=n; i++)
    {
        if ((mark[i]<=maxVal)&&(mark[i]>=minVal))
		printf("%f ",mark[i]);
    }
	}
void high(char codes[][5], char names[][21], float mark[], int n){
		float max=mark[0];
		 for (int i=1; i<=n; i++){
		 	if(mark[i]>max) max=mark[i];
		 }
		 printf("Print out students with the highest mark %f", max);
}
void menu() {	
	//system("cls");  // clear screen
    printf("-------------- MENU --------------\n");
   printf("1.Add some new students  \n");
    printf("2.Search and print out students using a name inputted.   \n");
    printf("3.Print out students in a range\n"); 
    printf("4.Print out students with the highest mark \n"); 
    printf("5.Remove a student based on a code inputted\n"); 
    printf("6.Print out the list based on name in ascending order then mark in descending order \n");  
}
int getchoice() {	
	int choice;
   	printf(">>> What is your option?: ");  scanf("%d",&choice);
    return choice;
}
//---------------------------- End ---------------------------------
//------------------------------------------------------------------ 
