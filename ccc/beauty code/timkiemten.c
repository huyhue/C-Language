#include <stdio.h>
#include <conio.h>
#include <string.h>
char* lTrim(char s[]){
   int i=0;
   while (s[i]==' ') i++;
   if(i>0) strcpy(&s[0],&s[i]);
   return s;
}
char* rTrim(char s[]){
   int i=strlen(s)-1;
   while(s[i]==' ') i--;
   s[i+1]='\0';
   return s;
}
char* trim(char s[]){
   rTrim(lTrim(s));
   char *ptr=strstr(s,"  ");
   while(ptr!=NULL){
      strcpy(ptr,ptr+1);
      ptr=strstr(s,"  ");
   }
   return s;
}
char* nameStr(char s[]){
   trim(s);
   strlwr(s);
   int L=strlen(s);
   int i;
   for (i=0;i<L;i++)
      if(i==0 || (i>0 && s[i-1]==' ')) s[i]=toupper (s[i]);
   return s;
}
void nhap(char names[][31], int n){
    int i;
    for (i=0; i<n;i++){
        printf("Nhap ten thu %d/%d: ",i+1,n);
        fflush(stdin);
        scanf("%30[^\n]",names[i]);
        nameStr(names[i]);
    }
}
void xuat (char names[][31], int n){
    int i;
    for (i=0; i<n; i++) puts(names[i]);
}
void sapxep(char names[][31],int n){
    int i,j;
    char t[31];
    for (i=0;i<n-1;i++){
        for(j=n-1;j>i;j--)
            if (strcmp(names[j], names[j-1])<0)
            strcpy(t,names[j]);
	    	strcpy(names[j],names[j-1]);
	    	strcpy(names[j-1],t);
    }
}
int timkiem(char ten[], char names[][31], int n, int vitri[]){
    int i,dem=0;
    for (i=0;i<n;i++){
        if(strcmp(ten,names[i])==0){
            vitri[dem]=i+1;
            dem++;
        }
    }
    return dem;
}
int soLanXuatHien(char ten[], char names[][31], int n){
    int i,count =0;
    for (i=0;i<n;i++){
        if(strcmp(ten,names[i])==0){
            count++;
        }
    }
    return count;
}
void nhapten(char ten[]){
    printf("Nhap vao ten can tim kiem: ");
    fflush(stdin);
    gets(ten);
    nameStr(ten);
}
int main(){
    char names[5][31];
    char ten[31];
    int vitri[5];
    int n=5,dem,i;
    nhap(names,n);
    xuat(names,n);
    //sapxep(names,n);
    //printf("DS sau khi sap xep:\n");
    //xuat(names,n);
    nhapten(ten);
    printf("the times of appear: %d",soLanXuatHien(ten, names,n));
    dem=timkiem(ten,names,n,vitri);
    if (dem==0) printf("Khong co ten trong mang\n");
    else {
        printf("Co %d ten trong mang",dem);
        printf("\nVi tri xuat hien trong mang: ");
		printf("%d ",vitri[i]);
    }
    getch();
}
