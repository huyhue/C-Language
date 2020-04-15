#include<stdio.h>
#define MAX 500
#include<conio.h>
void readFile(FILE * fPtr)
{
    char ch;
    do{
        ch = fgetc(fPtr);
        putchar(ch);
    }while(ch != EOF);
}
void enter(FILE * f,char *content, char *filename){
		printf("Enter content: ");
		gets(content);
		fputs(content, f);
		/* Reopen file in read mode to print file contents */
	    f = freopen(filename, "r", f);
	    readFile(f);
}
int main(){
	char filename[20];
	char content[100];
	char c;
	printf("============ Text management ============\n");
	printf("Enter file name to save content: ");
	gets(filename);
	FILE *f = fopen(filename,"a+");
	while(1){
		if(f == NULL){
			printf("File erroring\n");
			printf("Please enter new filename again\n");
		}else{
			enter(f,content,filename);
			break;
		}
	}

	fclose(f);
return 0;
}

