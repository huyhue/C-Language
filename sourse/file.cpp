#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int menu(){
	int choice;
	printf(" ----------------------------------\n");
	printf("|1- Add                  \n");
	printf("|2- Look                  \n");
	printf("|3- Display     \n");
	printf("|4- Exit     \n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

int checkName(char name[][20], char *newName, int i){
	for (int j=0; j<i; j++)
		if(strcmp(name[j], newName)==0)	return j;
	return -1;
}
//void save (char *code, char name[][20],char *date,float *point, int j){
//	FILE *fp1 = fopen ("Student.txt", "a");
//		fprintf(fp1, "%s\n%s\n%s\n%f\n", code[j], name[j], date[j], point[j]);
//	printf("The file has been saved. Thanks for using!\n");
//}
void save(char *code, char name[][20],char *date,float *point, int i){
	char fileName1[20];
	printf("What file would you like to save the new database?\n");
	fflush(stdin);
	gets(fileName1);
	FILE *fp1 = fopen (fileName1, "w");
	
	for(int j=0; j<i; j++)
		fprintf(fp1, "%s\n%s\n%s\n%f\n",code[j], name[j], date[j], point[j]);
	printf("The file has been saved. Thanks for shopping!\n");
}
void enter(char *code, char name[][20],char *date,float *point, int *i){
	printf("code:\n");fflush(stdin);
	scanf("%s", &code[*i]);
	printf("name:\n");	fflush(stdin);
	scanf("%s", &name[*i]);
	printf("date:\n");fflush(stdin);
	scanf("%s", &date[*i]);
	printf("point\n");fflush(stdin);
	scanf("%f", &point[*i]);
	printf("%s has been added into the database.\n", name[*i]);
	(*i)++;
	save(code,name,date,point,*i);
}
void look (char *code, char name[][20],char *date,float *point, int i){
	char findName[20];
	printf("Which name would you like to search for?\n");
	fflush(stdin);
	scanf("%s", &findName);
	int index = checkName(name, findName, i);
	if(index==-1)
		printf("Sorry we do not have %s in the store.\n", findName);
	else{
		printf("Here is the product information:\n");
		printf("%s\n%s\n%s\n%f\n",  code[i], name[i], date[i], point[i] );	
	}
	
}
void display (char *code, char name[][20],char *date,float *point, int i){
	
	for(int j=0; j<i; j++)
			printf("%s\n%s\n%s\n%f\n",code[j], name[j], date[j], point[j]);
}

					
int main(){
	char code[MAX];
	char name[MAX][20];
	float point[MAX];
	char date[MAX]; 
	int i = 0, choice;
	while(true){
	
		FILE* fp = fopen("Student.txt", "r");
		if(fp == NULL){
			printf("File is not existed\n"); 
		}
		else{
			while(fscanf(fp, "%s", &code[i]) != EOF){
				fflush(stdin);
				fscanf(fp, "%s\n", &code[i]);fflush(stdin);
				fscanf(fp,"%s\n", &name[i]);fflush(stdin);
				fscanf(fp,"%s\n", &date[i]);fflush(stdin);
				fscanf(fp,"%point\n", &point[i]);
				i++;
			}
			fclose(fp);
			break;
		}
	}

	do{
		fflush(stdin);
		choice = menu();
		switch(choice){
			case 1:
				enter(code, name, date, point, &i);
				break;
			case 2:
				look(code, name, date, point, i);
				break;
			case 3:
				display(code, name, date, point, i);
				break;
			default:
				break;
		}
	}while(choice>0 && choice<4);
	return 0;
}
