#include<stdio.h>
#include<string.h>
#include<conio.h>
int dem(char str[],int i)
   {
   char t = str[i];
   int dem = 0;
   int j;
   for(j = 0; j < strlen(str); j++)
       {
       if(t == str[j])
           dem = dem + 1;
       }
   return dem;
   }
int main(){
	int key, n, i;
	char str[50];
	do{
		printf("Please enter a string:");
		fflush(stdin);
		gets(str);
	
		n = strlen(str);
		printf("Found characters:");
		for(i = 0; i <= n-1; i++){
			if(dem(str,i) == 1){
				printf("%5c",str[i]);
			}
		}
		printf("\n Press enter to continue, Esc to exit");
		key = getch();
	}while(key != 27);
	
return 0;
}


