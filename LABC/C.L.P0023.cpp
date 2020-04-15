#include<stdio.h>
#include<string.h>
int main(){
	char name1[30];
	char name2[30];
	printf("Enter a string 1: "); fflush(stdin);
	scanf("%[^\n]",name1);
	printf("Enter a string 2: "); fflush(stdin);
	scanf("%[^\n]",name2);
	printf("\n==========================\n");
	printf("mystrcat(%s,%s)\n",name1,name2);
	printf("Result is: %s\n",strcat(name1, name2));
	printf("\n---------------------------\n");
	printf("mystrcmp(%s ,%s)\n",name1,name2);
	printf("Result is: %d\n",strcmp(name1, name2));
	printf("\n---------------------------\n");
	printf("mystrcpy(%s ,%s)\n",name1,name2);
	printf("Result is: %s\n",strcpy(name1, name2));
	printf("\n---------------------------\n");
	char str[20]="tong gia huy";
	char str1[20]={};
	printf("mystrncpy(%s ,%s)\n",str1,str);
	printf("Result is: %s\n",strncpy(str1, str, 3));
	printf("\n---------------------------\n");
	char s[20]="tong gia huy";
	printf("mystrnset(%s ,%s,3)\n",s,"*");
	printf("Result is: %s\n",strnset(s,'*',3));
	printf("\n---------------------------\n");
	char st[20]="tong gia huy";
	printf("mystrstr(%s ,%s)\n",st,"gia");
	printf("Result is: %s\n",strstr(st, "gia"));
	printf("\n---------------------------\n");
	char s1[20]="tong .gia huy";
	printf("mystrchr(%s ,%s)\n",st,".");
	printf("Result is: %s\n",strchr(s1,'.'));
return 0;
}

