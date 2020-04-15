#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int menu(){
	int choice;
	printf("	GROCERY STORE DATABASE    \n");
	printf(" ----------------------------------\n");
	printf("|1- Add new item                   \n");
	printf("|2- Delete item                    \n");
	printf("|3- Change the cost of an item     \n");
	printf("|4- Search for item                \n");
	printf("|5- Display inventory details      \n");
	printf("|6- Quit                           \n");
	printf(" ----------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}
int checkId(int *id, int newId, int i){
	for(int j=0; j<i; j++)
		if(id[j]==newId)	
			return j;
	return -1;
}
int checkName(char name[][20], char *newName, int i){
	for (int j=0; j<i; j++)
		if(strcmp(name[j], newName)==0)	return j;
	return -1;
}
void addItem(int *id, char name[][20], float *cost, char *category, int *i){
	printf("What is the ID number of the item to add?\n");
	while(1){
		scanf("%d", &id[*i]);
		if(checkId(id, id[*i], *i)!=-1){
			printf("This ID was existed.\n");
			printf("Please enter again: ");
		}
		else break;
	}
	printf("What is the name of the item to be added?\n");
	while(1){
		fflush(stdin);
		scanf("%s", &name[*i]);
		if(checkName(name, name[*i], *i)!=-1){
			printf("This name was existed.\n");
			printf("Please enter again: ");
		}
		else break;
	}
	printf("What is the cost of the item to be added?\n");
	fflush(stdin);
	scanf("%f", &cost[*i]);
	printf("What is the product category of the item to be added?\n");
	fflush(stdin);
	scanf("%c", &category[*i]);
	printf("%s has been added into the database.\n", name[*i]);
	(*i)++;
}
void deleteItem(int *id, char name[][20], float *cost, char *category, int *i){	
	int deleteID;
	printf("What is the ID number of the product to delete?\n");
	scanf("%d", &deleteID);
	int index=checkId(id, deleteID, *i);
	if(index!=-1){
		printf("%s have been deleted from the database.\n", name[index]);
		for(; index<*i; index++){
			id[index]=id[index+1];
			strcpy(name[index], name[index+1]);
			cost[index]=cost[index+1];
			category[index]=category[index+1];
		}
		(*i)--;
		
	}
	else	printf("Sorry, there is no item in the database with that ID number.\n");
}
void changeCost (int *id, char name[][20], float *cost, char *category, int i){
	float newCost;
	int findID;
	printf("What is the ID number of the item in question?\n");
	scanf("%d", &findID);
	int index=checkId(id, findID, i);
	if(index==-1)
		printf("Not found.\n");
	else{
		printf("What is the new price for %s?\n", name[index]);
		do{
			fflush(stdin);
			scanf("%f", &newCost);
			if(newCost<0)
				printf("Price has to be bigger or equal 0.\nPlease enter again: ");				
		}while(newCost<0);
		cost[index]=newCost;
		printf("%s now costs %.2f\n", name[index], cost[index]);
	}	
}
void search (int *id, char name[][20], float *cost, char *category, int i){
	char findName[20];
	printf("Which item would you like to search for?\n");
	fflush(stdin);
	scanf("%s", &findName);
	int index = checkName(name, findName, i);
	if(index==-1)
		printf("Sorry we do not have %s in the store.\n", findName);
	else{
		printf("Here is the product information:\n");
		printf("%d  %s  %.2f  %c\n", id[index], name[index], cost[index], category[index]);	
	}
}
void display (int *id, char name[][20], float *cost, char *category, int i){
	printf("%-5s%-20s%-10s%-10s\n", "ID", "Product", "Price", "Category");
	for(int j=0; j<i; j++)
		printf("%-5d%-20s%-10.2f%-10c\n", id[j], name[j], cost[j], category[j]);
}
void save (int *id, char name[][20], float *cost, char *category, int i){
	char answer[3];
	char fileName1[20];
	printf("Would you like to save the new changes database? (yes/no)\n");
	scanf("%s", &answer);
	if(strcmp(answer, "yes")!=0)
		return;
	printf("What file would you like to save the new database?\n");
	fflush(stdin);
	gets(fileName1);
	FILE *fp1 = fopen (fileName1, "w");
	fprintf(fp1, "%-5s%-20s%-10s%-10s\n", "ID", "Product", "Price", "Category");
	for(int j=0; j<i; j++)
		fprintf(fp1, "%-5d%-20s%-10.2f%-10c\n", id[j], name[j], cost[j], category[j]);
	printf("The file has been saved. Thanks for shopping!\n");
}
					
int main(){
	char fileName[20];
	int id[MAX];
	char name[MAX][20];
	float cost[MAX];
	char category[MAX]; 
	int i=0, choice;
	
	printf("Welcome to the grocery store:\n");
	printf("Please input the file you'd like to load into stock.\n");
	while(true){
		gets(fileName);
		FILE* fp = fopen(fileName, "r");
		if(fp == NULL){
			printf("File %s is not existed\n", fileName); 
			printf("Enter again: ");
		}
		else{
			while(fscanf(fp, "%d", &id[i]) != EOF){
				fscanf(fp, "%d ", &id[i]);
				fflush(stdin);
				fscanf(fp,"%s", &name[i]);
				fscanf(fp,"%f ", &cost[i]);
				fscanf(fp,"%c\n", &category[i]);
				i++;
			}
			fclose(fp);
			break;
		}
	}
	printf("%s has been properly loaded into the database.\n", fileName);
	do{
		fflush(stdin);
		choice = menu();
		switch(choice){
			case 1:
				addItem(id, name, cost, category, &i);
				break;
			case 2:
				deleteItem(id, name, cost, category, &i);
				break;
			case 3:
				changeCost(id, name, cost, category, i);
				break;
			case 4:
				search (id, name, cost, category, i);
				break;
			case 5:
				display (id, name, cost, category, i);
				break;
			default:
				save (id, name, cost, category, i);
		}
	}while(choice>0 && choice<6);
	return 0;
}
