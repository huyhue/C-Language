#include<stdio.h>
#include<string.h>
#include<conio.h>
void del(char str[]){
	while(str[0] == ' ') strcpy(&str[0], &str[1]);
	for(int i = 0; i < strlen(str)-1; i++){
		if(str[i] == ' '&& str[i+1] == ' '){
			strcpy(&str[i], &str[i+1]);
			i--;
		}
	}
	while(str[strlen(str) - 1] == ' ') strcpy(&str[0], &str[1]);
}
int main(){
	int key;
	char str[50];
	do{
		printf("\nPlease enter a string:");
		fflush(stdin);
		gets(str);
		del(str);
		printf("\nThe string after removing: %s",str);
		printf("\n Press enter to continue, Esc to exit");
		key = getch();
	}while(key != 27);
	
return 0;
}

