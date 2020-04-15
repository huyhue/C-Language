#include<stdio.h>
#define MAXN =50
void add (char codes[][9],  char names[][21],double salaries[],double allowances[],   int*pn){
	printf("enter names employee:");
	gets(names);
	printf("enter code:");
	scanf("%s",codes);
	printf("enter salaries:");
	scanf("%f",codes);
	printf("enter allowances:");
	scanf("%f",codes);
}
void sort(char codes[][9], char names[][21], double salaries[], 
                 double allowances[], int n)
{   for (i=0; i<n-1; i++)
      for (j=n-1; j>i; j-- )
         if (salaries[j] + allowances[j] <   salaries[j-1] + allowances[j-1])
              {    swap codes[j], codes[j-1];
                    swap names[j], names[j-1];
                    swap salaries[j], salaries[j-1];
                    swap allowances[j], allowances[j-1];
               } 
       }
}  
void printBasedName ( char name[],   char codes[][9],  char names[][21],double salaries[],double allowances[],int n)
int findCode (char code[],   char codes[][9],int n)
void removePos  (int pos,   char codes[][9],char names[][21],double salaries[],double allowances[],int *pn)
void sort (char codes[][9],  char names[][21],double salaries[],double allowances[],int n)
void print (char codes[][9],  char names[][21],double salaries[],double allowances[],int n)



int main(){
	int choice;
	printf("1.Adding a new employee");
	printf("2.Find data about employees using a name inputted");
	printf("3.Remove an employee based on a code inputted");
	printf("4.Print the list in descending order based on salary + allowance");
	printf("enter a choice:");
	scanf("%d",&choice);
	switch(ch){
		case 1:{
			break;
		}
		case 2:{
			
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			
			break;
		}
	}
return 0;
}

