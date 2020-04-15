/* --------------Array of Strings --------------
Develop a C-program that allows user:
	1. Add some name (press SPACE key to escape)  
   	2. Find a name   
    3. Delete a name   
    4. Insert a name  
   	5. Modify a name  
    6. Sort the list in ascending order   
-------------------------------------------------*/
#include <stdio.h>
#include<string.h>
#define MAXN 20
void input(char s[][31], int *n);
void output(char s[][31], int n);
void find(char name[],char s[][31], int n);
void del(char name[],char s[][31], int *n);
void insert(char name[],char s[][31], int *n);
void modify(char name[],char s[][31], int n);
void sort(char s[][31], int n);
void menu();
int getchoice();
//------------------------Main function-------------------------------------
int main(){
	int choice,n=0;
	char s[MAXN][31], name[31];
	menu();
	do {
	 	choice=getchoice();
        switch (choice) {
        	case 1:	printf("----- Add some item ----- \n");
        			input(s, &n); 
					break;
    		case 2:	printf("----- Find an item based on a value inputted ----- \n");
    				printf("What name do you want to find? "); fflush(stdin); scanf("%30[^\n]",name);
    				find(name,s,n);
    				break;
    		case 3:	printf("----- Delete an item based on a value inputted -----\n"); 
    				printf("What name do you want to delete? "); fflush(stdin); scanf("%30[^\n]",name);
    				del(name,s,&n);
    				break;
    		case 4: printf("----- Insert an item based on a value inputted -----\n"); // Note: The list in ascending order 
					printf("What name do you want to insert? "); fflush(stdin); scanf("%30[^\n]",name);
					insert(name,s,&n);
    				break;
    		case 5: printf("----- Modify an item based on a value inputted -----\n"); 
    				printf("What name do you want to modify? "); fflush(stdin); scanf("%30[^\n]",name);
					modify(name,s,n);
    				break;
    		case 6: printf("----- Sort the list in ascending order based on values----- \n"); 
					sort(s, n);
    				break;
    		default: printf("Bye... \n");
        }              
    } while ((choice>=1) && (choice<=6));	
}
//---------------------- Implement functions---------------------------------------
void output(char s[][31], int n){
	for( int i=0;i<n;i++) 
		printf("%d.%s \n", i, s[i]);
}
void input(char s[][31], int *n){//da tham
	int ok; char name[31];
	do{
		printf("input a name:"); fflush(stdin);	scanf("%30[^\n]",name); //gets(name);
		ok=(name[0]!=32);  //ok=(name[0]!=' '); // *Note: press keySPACE for codes[i] to exit
		if (ok) {
			strcpy(s[*n],name);//chen ten vao mang
			(*n)++;
		}
			
	}while (ok);
	printf("After adding: \n");	output(s, *n);	
}

int findPos(char name[],char s[][31],int n){
	for (int i=0; i<n;i++)
		if (strcmp(s[i],name)==0)	
			return i;
	return -1;
}
void find(char name[],char s[][31], int n){
	int pos=findPos(name,s,n);
	if (pos>=0) 	printf("found on %d    value is: %s \n",pos,s[pos]);
	else			printf("sorry,not found...! \n");	
}
void del(char name[],char s[][31], int *n){
	int pos=findPos(name,s,*n);
	if (pos>=0){
		printf("found on %d    value is: %s \n",pos,s[pos]);    
		for (int i=pos;i<(*n-1);i++)
			strcpy(s[i],s[i+1]);
		(*n)--;
		printf("After deleting: \n");	output(s, *n);	
	}
	else	printf("Not found in the list...! \n");	
}
void insert(char name[],char s[][31], int *n){  // The list in ascending order //chen vo vi tri tiep theo
	int i=*n-1;
	if (i<MAXN-1){
		while (strcmp(s[i],name)>0) {
			strcpy(s[i+1],s[i]);//dich chuyen 1 khoang trong
			i--;		
		}
		strcpy(s[i+1],name); //gan gia tri vao khoang trong
		(*n)++;
		
		printf("After inserting: \n");  output(s, *n);
	}
	else	printf("sorry, the list is full...! \n");	
}
void modify(char name[],char s[][31], int n){
	char value[31];
	int pos=findPos(name,s,n);
	printf("input a new value:"); fflush(stdin);	scanf("%30[^\n]",value); 
	strcpy(s[pos],value);
	printf("After modifying: \n");  output(s, n);
}
void swap(char a[], char b[]){
	char t[31];
	strcpy(t,a); strcpy(a,b); strcpy(b,t);
}
void sort(char s[][31], int n){
	for (int i=0; i<n-1; i++)
    	for (int j=i+1; j<n; j++ )
    		if (strcmp(s[i],s[j])>0)   swap(s[i],s[j]);
    printf("After sorting: \n");  output(s, n);
}
void menu() {	
	//system("cls");  // clear screen
    printf("---------- MENU ----------\n");
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
