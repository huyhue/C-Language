#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	printf("Enter a string: ");
	fflush(stdin);
	gets(str);
	strrev(str);
	for(int i = 0; str[i] != '\0'; i++){
		if(islower(str[i])){
			putchar(toupper(str[i]));
		}
		if(isupper(str[i])){
			putchar(tolower(str[i]));
		}
		if(str[i] == ' '){
			printf(" ");
		}
	}	
return 0;
}

