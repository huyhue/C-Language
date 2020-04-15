#include<stdio.h>  
 
int main() {
    int a = 10, b = 20;
    int *p1 = &a,*p2 = &b;  
    printf("Truoc khi hoan doi: *p1=%d *p2=%d\n", *p1, *p2);
    // hoan doi
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("Sau khi hoan doi: *p1=%d *p2=%d", *p1, *p2);
    return 0;
}

