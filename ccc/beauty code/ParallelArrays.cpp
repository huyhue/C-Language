/* --------------Slot 23 - ParallelArrays - Problem 2 --------------
Data about an item: Code(char 8), name (char 20), price(double), category (char 12)
Develop a C-program that allows user:
	1. Adding some new item (press SPACE key to exit)
	2. Print out items which belong to a known category.
	3. Remove an item based on a code inputted
	4. Print the list in ascending order based on categories then names
---------------------------------------------------------------------*/
#include <stdio.h>
#include<string.h>
#define MAXN 20

void addItems(char codes[][9], char names[][21], int prices[], char categories[][13], int *n); //Add some new items, inputted data are local variables 
void printCategory(char cat[], char codes[][9], char names[][21], int prices[], char categories[][13], int n); //Print out items of a known category 
void removeCode(char cod[], char codes[][9], char names[][21], int prices[], char categories[][13], int *n); //Remove the item based on a code inputted 
void sortList(char codes[][9], char names[][21], int prices[], char categories[][13], int n); //Sort the list based on categories then names                  
void menu();
int getchoice();
//------------------------Main function-------------------------------------
int main(){
	char codes[MAXN][9], names[MAXN][21], categories[MAXN][13];
	int  prices[MAXN];
	char cat[13], cod[9];
	int choice,n=0;
	
	menu();
	do {
	 	choice=getchoice();
        switch (choice) {
        	case 1:	printf("--- Adding some new items  --- \n");
        			addItems(codes, names, prices, categories, &n);
					break;
    		case 2:	printf("--- Print out items which belong to a known category --- \n");
    				printf("What category do you want to print? "); fflush(stdin); scanf("%12[^\n]",cat);
    				printCategory(cat, codes, names, prices, categories, n);
    				break;
    		case 3:	printf("--- Remove an item based on a code inputted ---\n"); 
    				printf("What code do you want to delete? "); fflush(stdin); scanf("%8[^\n]",cod);
    				removeCode(cod, codes, names, prices, categories, &n);
    				break;
    		case 4: printf("--- Print the list in ascending order based on categories then names --- \n"); 
					sortList(codes, names, prices, categories, n);
    				break;
    		default: printf("Bye... \n");
        }              
    } while ((choice>=1) && (choice<=4));	
}
//---------------------- Implement functions---------------------------------------
void printList(char codes[][9], char names[][21], int prices[], char categories[][13], int n){  
	for( int i=0;i<n;i++) 
		printf("%d.%9s%21s%10d%13s \n",i,codes[i],names[i],prices[i],categories[i]);
}
void addItems(char codes[][9], char names[][21], int prices[], char categories[][13], int *n){
	int ok; 
	do{ // *Note: press keySPACE for codes[i] to exit
		printf("%d-------- Input a code: ",*n); fflush(stdin);	scanf("%8[^\n]",codes[*n]); //gets(code);
		ok=(codes[*n][0]!=32);  //ok=(codes[0]!=' '); 
		if (ok) {
			printf("name: "); 		fflush(stdin);	scanf("%20[^\n]",names[*n]);
			printf("price: ");		fflush(stdin);	scanf("%d",&prices[*n]);
			printf("categorie: "); 	fflush(stdin);	scanf("%12[^\n]",categories[*n]);
			(*n)++;
		}
	}while (ok);
	printf("After adding: \n");	 
	printList(codes, names, prices, categories, *n);
}
void printCategory(char cat[], char codes[][9], char names[][21], int prices[], char categories[][13], int n){
	int count=0;
	for (int i=0;i<n;i++)
		if (strcmp(categories[i],cat)==0) {
			printf("%d.%9s%21s%10d%13s \n",i,codes[i],names[i],prices[i],categories[i]);
			count++;
		}
	if (count>0) printf("have %d items\n",count);
	else printf("sorry, not found...!\n");			
}

int findCode(char cod[], char codes[][9],  int n){ //Find the position of a known code   
 	for (int i=0; i<n;i++)
		if (strcmp(codes[i],cod)==0)	return i;
	return -1;
}
void removeCode(char cod[], char codes[][9], char names[][21], int prices[], char categories[][13], int *n){
	int pos=findCode(cod,codes,*n);
	if (pos>=0){
		printf("found on %d    value is: %s \n",pos,codes[pos]);
		for (int i=pos;i<(*n-1);i++){
			strcpy(codes[i],codes[i+1]);
			strcpy(names[i],names[i+1]);
			prices[i]=prices[i+1];
			strcpy(categories[i],categories[i+1]);	
		}
		(*n)--;
		printf("After deleting: \n");	
		printList(codes, names, prices, categories, *n);	
	}
	else	printf("Not found in the list...! \n");	
}
void swapInt(int *a, int *b){
	int t;
	t=*a; *a=*b; *b=t;
}
void swapString(char a[], char b[]){
	char t[31];
	strcpy(t,a); strcpy(a,b); strcpy(b,t);
}
void sortList(char codes[][9], char names[][21], int prices[], char categories[][13], int n){   
	for (int i=0; i<n-1; i++)
      	for (int j=n-1; j>i; j-- ){   
		  	int dCat = strcmp( categories[j], categories[j-1]); //category difference 
        	int dName= strcmp( names[j], names[j-1]); 			//name difference 
        	if (dCat<0 || (dCat==0 && dName <0)){    
					swapString(codes[j], codes[j-1]);
                    swapString(names[j], names[j-1]);
                    swapInt(&prices[j], &prices[j-1]);
                    swapString(categories[j], categories[j-1]);
            } 
       }
    printf("After sorting: \n");	 
	printList(codes, names, prices, categories, n);
}  
void menu() {	
	//system("cls");  // clear screen
    printf("-------------- MENU --------------\n");
   printf("1. Add some item  \n");
    printf("2. Find an item   \n");
    printf("3. Delete an item \n"); 
    printf("4. Insert an item \n"); 
    printf("5. Modify an item \n"); 
    printf("6. Sort the list in ascending order \n");  
}
int getchoice() {	
	int choice;
   	printf(">>> What is your option?: ");  scanf("%d",&choice);
    return choice;
}
//---------------------------- End ---------------------------------
//------------------------------------------------------------------
