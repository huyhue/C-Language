#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int r;
    for(int i = 0; i < 5; ++i){
        r = rand();
        printf("Rand %d is %d\n",i, r);
    }    
}
 
