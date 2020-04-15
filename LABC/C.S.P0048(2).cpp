#include<stdio.h>
#include<string.h>
int main(){
	//declare variable
	FILE *fsave;
	char buffer[100];
	char w[100], fn[100];
	
	printf("=========== Text management =========\n");
	printf("Enter file name to save content: ");
	gets(fn);
	
	printf("Enter content: ");
	gets(w);
	
	int len = strlen(w);
	fflush(stdin);
	
	fsave = fopen(fn,"a");
	fwrite(w,1,len,fsave);
	fclose(fsave);
	
	fflush(stdin);
	printf("File content:\n");
	fsave = fopen(fn,"r");
	fread(buffer,1,200,fsave);
	printf("%s\n",buffer);
	fclose(fsave);
}

