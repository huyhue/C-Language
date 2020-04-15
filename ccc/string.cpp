#include<stdio.h>
#include<string.h>
#include<conio.h>
/*int main(){
char names[7][31]={"dinh tien hoang", "le dai hanh","ly cong an", "le loi","tran nguyen han","le thanh tong","nguyen hue"};
int i;
for(i=0; i<7; i++)
printf("addr: %u, value: %s \n",&names[i], names[i]);
getchar();
return 0;
}*/
/*void print(char list[][31], int n){
	int i; 
	for(i=0; i<n; i++) puts(list[i]);
}
int main(){
char names[7][31]={"dinh tien hoang", "le dai hanh","ly cong an", "le loi","tran nguyen han","le thanh tong","nguyen hue"};
print(names,7);
return 0;}*/

void nhap(char names[][31], int n){//Vi?t chuong trình C s? ch?p nh?n 10 tên, in ra danh sách, s?p x?p danh sách theo th? t? tang d?n, in ra k?t qu?.
	int i;
	for(i=0;i<n;i++){
		printf("nhap ten thu %d/%d:",i+1,n);
		fflush(stdin);
		scanf("%30[^\n]", names[i]);
		strupr(names[i]);
	}
}
void xuat(char names[][31], int n){
	int i;
	for(i=0;i<n;i++) puts(names[i]);
	}
void sapxep(char names[][31], int n){
	int i,j;
	char t[31]; //bien hoan vi
	for(i=0; i<n-1;i++)	
		for(j=n-1; j>i; j--)
			if(strcmp(names[j], names[j-1])<0)	{  //ten sau< ten truoc
				strcpy(t, names[j]);   //t=names[i]
				strcpy(names[j], names[j-1]);
				strcpy(names[j-1], t);
			} 			
}

int main(){
	char names[10][31];
	int n=5;
	nhap(names, n);
	xuat(names, n);
	sapxep(names, n);
	printf("DS sau khi sap xep: \n");
	xuat(names, n);
	getch();
	return 0;
}
/*char* replaceAll(char* source, char* subStr, char* repStr){
	int subL =strlen(subStr);
	int repL =strlen(repStr);
	char temp[100];
	char* ptr= strstr(source, subStr);
	int i;
	while(ptr!=NULL);//while subStr exists
{
	strcpy(ptr, ptr+subL); //shift subStr up
	if(repL>0){
		strcpy(temp, ptr);//prepare space for repStr
		strcpy(ptr+repL, temp);//copy characters in repStr to source
		for(i=0; i< repL;i++) *(ptr+i)=repStr[i];
	}
	ptr=strstr(source, subStr);
}
return source;}
int main(){
	char s[80]="con coc trong hang con coc nhay ra, coc chet";
	char subStr[21]="coc";
	char repStr[21]="bo";
	puts(s);
	replaceAll(s,subStr, repStr);
	puts(s);
	getchar();
	getchar();
	return 0;
}
/*int main(){
	char s1[21];
	char s2[21];
	printf("enter string s1:");
	gets(s1);
	printf("enter string s2:");
	gets(s2);
	printf("lengths of s1: %d, s2: %d\n", strlen(s1), strlen(s2));
	printf("compare s1 with s2: %d\n",strcmp(s1,s2));
	strupr(s1);
	printf("uppercase s1: %s \n",s1);
	strcat(s1,s2);
	printf("after append s2 to s1: %s\n",s1);
	strstr(s1,s2);
	printf("subtring s2 to s1: %s\n",s1);
	char s3[10];
	printf("enter a sub-string of s1:");
	gets(s3);
	char* ptr=strstr(s1,s3); 
	printf("address of s1: %u\n", s1);
	printf("address of s3: %u\n", s3);
	printf("address of substring: %u\n", ptr);
	getchar();
	return 0;
}*/


