#include <stdio.h>
#include <stdlib.h>
int main()
{  char c1, c2;
   printf("Input a character:");
   fflush(stdin);
   c1= getchar();
   printf("Input a character:");
   fflush(stdin);
   c2= getchar();
   printf("c1: %c, ASCI code: %d, %o, %X\n", c1,c1,c1,c1);
   printf("c2: %c, ASCI code: %d, %o, %X\n", c2,c2,c2,c2);
   system("pause");
}

