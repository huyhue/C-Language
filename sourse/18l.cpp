#include<stdio.h>
void copyFile(){
	char filename[20];
	char filename[20];
	char c;
	char content[500];
	printf("Enter file to copy:");
	while(1){
		gets(filename);
		FILE *f=fopen(filename,"r");
		if(f==NULL){
		printf("File not exist, please enter again\n");
		}else{
			while((c=getc(f))!=EOF){
				strncat(content,&c,1);
				fclose(f);
				break;
			}
		}
	}
	printf("Enter file save: ");
	gets(filename2);
	FILE *f2=fopen(filename,"a");
	fwrite(content,sizeof(char),500,f2);
	fclose(f2);
	printf("Write file successing.\n");
}
void readFile(){
	char filename[20];
	char c;
	printf("Enter file:");

	while(1){
		gets(filename);
		FILE *f=fopen(filename,"r");
		if(f==NULL){
		printf("File not exist, please enter again\n");
		}else{
			while((c=getc(f))!=EOF){
				putchar(c);
				fclose(f);
				break;
			}
		}
	}
}
void mergeFile(){
	char file1[20];
	char file2[20];
	char file3[20];
	char c;
	printf("Enter file 1: ");
	gets(file1);
	printf("Enter file 2: ");
	gets(file2);
	printf("Enter file 3 from 1, 2");
	gets(file3);
	
	FILE *f1=fopen(file1,"r");
	FILE *f2=fopen(file2,"r");
	
	if(f1==NULL || f2==NULL){
		printf("file erroring...");
		exit(0);
	}
	
		FILE *f3=fopen(file3,"a+");
		
		while((c=fgetc(f1))!=EOF)  fputc(c,f3);
		while((c=fgetc(f2))!=EOF)  fputc(c,f3);
		
		printf("successing...");
		fclose(f1);
		fclose(f2);
		fclose(f3);
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
	char filename[20];
	printf("Enter file delete...");
	gets(filename);
	if(remove(filename)==0){
		printf("Delete successing...");
	}
}
int main(){
	int choice;
	do{
		scanf("%d",&choice);
		switch(choice){
			case 1:
				readFile();
				break;
			case 2:
				copyFile();
				break;
			case 3:
				mergeFile();
				break;
			case 4:
				list();
				break;
			case 5:
				deleteFile();
				break;
			default : printf("Exit.\n");
		}
	}while(choice >0&&choice<6);
	
return 0;
}

