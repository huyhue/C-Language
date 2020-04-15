#include<stdio.h>
int main(){
	char filename[20];
	char c;
	printf("File name: ");
	
	
	while(true){
		gets(filename);
		FILE* f=fopen(filename, "r");
		if(f==NULL){
			printf("File erroring, please enter again:\n");
		}else{
			while((c=fgetc(f))!=EOF) putchar(c);
			fclose(f);
			break;
		}
	}
	
return 0;
}

