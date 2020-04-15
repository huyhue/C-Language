#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id;
	char *firstName;
	char *lastName;
	int age;
	
}Person;
static int id=100;
void getUserInput(FILE *fout){
	//thao tac ghi thong tin ra file
	Person p;
	/*p.firstName = malloc(sizeof(char)*50);
	p.lastName  = malloc(sizeof(char)*50);*/
	int choice=0;
	while(1){ //lap vo han
	p.id=id++;
		puts("enter your first name, last name, age:");
		scanf("%s %s %d",p.firstName,p.lastName,&p.age);
		fprintf(fout,"%5d %10s %10s %5d \n",p.id,p.firstName,p.lastName,p.age);
		puts("continue? press 1; exit ? press 0: ???");
		scanf("%d",&choice);
		if(choice==0){   //thoat lap
			break;
		}
		
	}
}
/*void readFile(FILE *fin){
	Person p;
	p.firstName=malloc(sizeof(char)*50);
	p.lastName=malloc(sizeof(char)*50);
	puts("User info: \n");
	while(!feof(fin)){
		fscanf(fin,"%5d %10s %10s %5d \n",&p.id,p.firstName,p.lastName,&p.age);
		printf("%5d %10s %10s %5d \n",p.id,p.firstName,p.lastName,p.age);
	} puts("-------DONE--
	----");
}*/
int main(){
	FILE *fin;
	FILE *fout;
	fout=fopen("C:/Users/ASUS/Desktop/123","w");
	if(fout != NULL){
		getUserInput(fout);//thao tac ghi file
		fclose(fout);
		
	}
	/*fin=fopen("C:\\Users\\ASUS\\Desktop\\huy","w");
	if(fin!=NULL){
		readFile(fin);
		fclose(fin);
	}*/
return 0;
}

