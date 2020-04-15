#include<stdio.h>
#include<string.h>

/*int main(){//khia bao chuoi
char names[50];
printf("hi, what your names? \n My name is:");
gets(names);
printf("hi %s, welcome to c language \n",names);
char myLove[]="Nguyen Thi Lap Lanh";puts(myLove);
return 0;


return 0;
}*/
/*int main(){//nhap chuoi va dem ky tu
	char s[50];
	printf("enter a string:");
	gets(s);
	int i, count=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]==' ') count++;
	}
	printf("number word in string is: %d\n", count+1);
	return 0;
}*/
int main(){
	char s[50];
	printf("enter a string: "); gets(s);
	//delete all space at start of string
	while(s[0]==' ') strcpy(&s[0],&s[1]);
	//delete all space at end of string
	while(s[strlen(s)-1]=' ') s[strlen(s)-1]='\0';
	//delete all space between two word
	int i;
	for(i=0; i< strlen(s); i++){
		if(s[i]==' '&& s[i+1]==' '){
			strcpy(&s[i],&s[i+1]);
			i--;}}
		printf("s=%s \n", s);
		
		
	return 0;
}

