#include <stdio.h>
#include <errno.h>
#include <string.h>
 
extern int errno;
 
int main () {
 
    FILE * pf;
    int errnum;
    pf = fopen ("unexist.txt", "rb");
     
    if (pf == NULL) { 
        errnum = errno;
        fprintf(stderr, "Gia tri cua loi: %d\n", errno);
        perror("Loi duoc in ra boi perror");
        fprintf(stderr, "Loi mo file: %s\n", strerror( errnum ));
    } else {
        fclose (pf);
    }
 
    return 0;
}

