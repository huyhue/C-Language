#include<conio.h> 
#include<stdio.h>  
#include<string.h>
#include<ctype.h>

// Chuong trinh C voi string //
// *************************//

// Ham xu ly khoang trang ben trai
char *lTrim (char s[]){
	int i=0;
	while (s[i]==' ')
	i++;
	if (i>0)
	strcpy(&s[0],&s[i]);
	return s;
}

// Ham xu ly khoang trang ben phai
char *rTrim (char s[]){
	int i=strlen(s)-1;
	while (s[i]==' ')
	i--;
	s[i+1]='\0';
	return s;
}

// Ham xu ly khoang trang o giua
char *Trim (char s[]){
	rTrim(lTrim(s));
	char *ptr=strstr(s,"  ");
	while (ptr!=NULL)
	{
		strcpy(ptr,ptr+1);
		ptr=strstr(s,"  ");
	}
	return s;
}

// Ham xu ly ten: VD: _______NghiEm______THanH XuAn__ => Nghiem_Thanh_Xuan "-" la khoang trang (space)
char *nameStr (char s[]){
	Trim(s);
	strlwr(s);
	int L=strlen(s);
	int i;
	for(i=0; i<L; i++)
	if(i==0||(i>0&&s[i-1]==' '))
	s[i]=toupper(s[i]);
	return s;
}

// Ham dem tu trong string
int count(char *s)
{
	int n=strlen(s),i;
	int count=0;
	if(s[0]!=' ')
		count=1;
	for( i=0;i<n-1;i++)
	{
		if(s[i]==' ' && s[i+1]!=' ')
			count++;
	}
	return count;
}

int main()
{
	char s[21];
	int result;
	printf("Enter String s: \n ");
	gets(s);
	printf("\n");
	
	/*lTrim(s);
	printf("After lTrim \n");
	puts(s);
	printf("\n");
	
	rTrim(s);
	printf("After rTrim \n");
	puts(s);
	printf("\n");
	
	Trim(s);
	printf("After extra blank are remove \n ");
	puts(s);
	printf("\n");*/
	
	nameStr(s);
	printf("After convert it to a name: \n ");
	puts(s);
	printf("\n");
	
	result=count(s);
	printf("String have %d words",result);
	printf("\n");
	
	getchar();
	
}
