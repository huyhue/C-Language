#include<stdio.h>
#define MAX 100
#include<string.h>
void addItem(int *id,char name[][20], float *cost,char* category, int *i){
		printf("Enter id:");
	scanf("%d",&id[*i]);
		fflush(stdin);
		printf("Enter name:");
	scanf("%s",&name[*i]);
		printf("Enter cost:");
	scanf("%f",&cost[*i]);
	fflush(stdin);
		printf("Enter category:");
	scanf("%c",&category[*i]);
	(*i)++;
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
	char filename[20];
	int i=0;
	int choice;
	printf("Enter file to word\n");
	gets(filename);
	FILE *f=fopen(filename,"r");
	
	int id[MAX];
	char name[MAX][20];
	float cost[MAX];
	char category[MAX];
	if(f==NULL){
		printf("FILE erroring...\n");
	}else{
		while((fscanf(f,"%s",&id[i])) != EOF){
			fscanf(f,"%d",&id[i]);
			fflush(stdin);
			fscanf(f,"%s",&name[i]);
			fscanf(f,"%f",&cost[i]);fflush(stdin);
			fscanf(f,"%c",&category[i]);
			i++;
		}
	}
	fclose(f);
	do{
		fflush(stdin);
		printf("choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addItem(id, name, cost, category, &i);
				break;
			case 2:
				display (id, name, cost, category, i);
				break;
			default:
				save (id, name, cost, category, i);
		}
	}while(choice>0 && choice<6);
return 0;
}

