/*#include<stdio.h>
int main(){
char c1='A';
char c2=65;
char c3=0x41;
char c4=0101;
printf("%c,%c,%c,%c\n",c1,c2,c3,c4);
getchar();
return 0;

*/
/*#include <stdio.h>
int main(){

printf("\a");
printf("He said that \"I love you\"\n");
printf("She say 'A'\n");
printf("My file: C:\\t1\\t111\\new_year.txt");
getchar();
return 0;
}
*/
#include <stdio.h>
#include <conio.h>
#define PI 3.141592
const double PI1 = 3.141593;
const double PI2 =3.141593;
const int MAXINT1 =12;
const  int MAXINT2=10;
const char MAXCHAR1 ='Z';
const char MAXCHAR2= 'A';
int main()
{printf("%d\n", PI*3*3);
printf("Non-type Constant: PI1: %d byte\n", sizeof(PI1));
printf("Non-type Constant: MAXINT1: %d byte\n", sizeof(MAXINT1));
printf("Non-type Constant: MAXCHAR1: %d byte\n", sizeof(MAXCHAR1));
printf("Type specified Constant: PI2: %d byte\n", sizeof(PI2));
printf("Type specified Constant: MAXINT2: %d byte\n", sizeof(MAXINT2));
printf("Type specified Constant: MAXCHAR2: %d byte\n", sizeof(MAXCHAR2));
getch();
}


