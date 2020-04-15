#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
char str[20];
int i,n,key;
do{
	//input string
	printf("\nInput a string: ");
	gets(str);
	
	//reverse string in here
	n = strlen(str);
	for(i = n-1; i >= 0; i--){
		if(str[i] == ' '){
			str[i] = '\0';
			printf("%s ", &str[i] + 1);
		}    
	}
	printf("%s",str);
	key = getch();	
}while(key != 27);
return 0;
}

