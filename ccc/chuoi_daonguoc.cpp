#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
   char xau[50];
   printf("Nhap vao mot chuoi: ");
   gets(xau);
   int a=strlen(xau)-1;
   for(int i=a;i>=0;i--)
   {
      if(xau[i]==32/* || i==0*/)
      {
         //if(i==0)
         {
            printf(" ");
         }
         for(int j=i;j<=a;j++)
         {
            printf("%c",xau[j]);
         }
         a=i-1;
      } 
   }
   getch();
}
