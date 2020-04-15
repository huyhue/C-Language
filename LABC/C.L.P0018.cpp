#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int menu(){
	int choice;
	printf("FILE MANAGEMENT\n"); 
	printf("1- Read file\n"); 
	printf("2- Copy file\n"); 
	printf("3- Merge two files\n");
	printf("4- List files in a directory\n"); 
	printf("5- Delete file\n");
	printf("6- Exit\n");
	printf("Choice feature: ");
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}
void readFile(){
	char filename[20];
	char content[1000];
	char c;
	printf("Enter the name of file you wish to see: "); 
	while(true){
		gets(filename);
		FILE *fp = fopen (filename, "r");
		if(fp == NULL){
			printf("File %s is not existed\n", filename); 
			printf("Enter again: ");
		}
		else{
			while ((c=fgetc(fp))!=EOF) putchar(c);
			fclose(fp);
			break;
		}
	}	
}
void copyFile(){
	char c;
	char filename1[30];
	char filename2[30];
	char content[500];
	int length = 0;
	printf("Enter name of file to copy: "); 
	while(true){
		gets(filename1);
		FILE *fp1 = fopen(filename1, "r"); 
		if(fp1 == NULL){
			printf("File %s is not existed\n", filename1); 
			printf("Enter again: ");
		}
		else{
			while ((c=fgetc(fp1))!=EOF)	strncat(content, &c,1);
			fclose(fp1);
			break;
		}
	}
	printf("Enter name of target file: "); 
	gets(filename2); 
	FILE *fp2 = fopen (filename2, "a"); 
	fwrite(content, sizeof(char), 200, fp2);
	fclose(fp2);
	printf("File copied successfully!!\n");
}
void mergeFile(){
	char filename1[20];
	char filename2[20];
	char filename3[20];
	char c;
	
	printf("Enter name of first file: "); 
	gets(filename1);
	printf("Enter name of second file: ");
	gets(filename2); 	
	printf("Enter name of file which will store contents of two files: ");
	gets(filename3);
	
	FILE *fp1 = fopen(filename1, "r"); 
	FILE *fp2 = fopen(filename2, "r"); 
	
	if(fp1==NULL||fp2==NULL){
		printf("File is not existed\n");
		exit(0);
	}
	
	FILE *fp3 = fopen(filename3, "a+");
	
	while((c=fgetc(fp1))!=EOF)	fputc(c,fp3);
	while((c=fgetc(fp2))!=EOF)	fputc(c,fp3);
	
	printf("Two files were merged into %s file successfully!\n", filename3);
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void list(){
	struct dirent *de;
	DIR *dr = opendir ("."); 
	if(dr==NULL){
		printf("Could not open current directory");
		return; 
	}
	while ((de = readdir(dr)) !=NULL)
	printf("%s\n", de->d_name);
	closedir(dr); 
}
void deleteFile(){
	char fileName[20]; 
	printf("Enter the name of file you wish to delete: ");
	gets(fileName);
	
	if(remove(fileName)==0)
		printf("%s file deleted successfully.\n",fileName);
	else{
		printf("Unable to delete the file.\n");
		perror("Following error occurred");
	}
}
int main(){
	int choice;
	do{
		choice=menu();
		switch(choice){
			case 1: readFile();
					break;
			case 2: copyFile();
					break;
			case 3: mergeFile(); 
					break;
			case 4: list();
					break;
			case 5: deleteFile();
					break;
			default: printf("Exit.\n");
		}
	}
	while(choice>0 && choice<6);	
	return 0;
}
