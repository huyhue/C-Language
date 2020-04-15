#include <stdio.h>
 
int main()
{
    int i, k;
 
    i = 5; k = i++;
    printf("i = %d, k = %d\n", i, k);
 
    i = 5; k = ++i;
    printf("i = %d, k = %d\n", i, k);
 
    i = 5; k = i--;
    printf("i = %d, k = %d\n", i, k);
 
    i = 5; k = --i;
    printf("i = %d, k = %d\n", i, k);
 
    return 0;
}
