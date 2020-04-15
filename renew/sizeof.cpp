#include <stdio.h>
#include <limits.h>  // limits for interger
#include <float.h>   // limits for float
 
int main()
{
    printf("TYPE                %6s %20s %20s\n", "SIZE", "MIN VALUE", "MAX VALUE");
    printf("char:          %6ld byte %20d %20d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char: %6ld byte %20d %20d\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("short:         %6ld byte %20d %20d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int:           %6ld byte %20d %20d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long:          %6ld byte %20ld %20ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long:     %6ld byte %20lld %20lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float:         %6ld byte %20e %20e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double:        %6ld byte %20e %20e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double:   %6ld byte %20Le %20Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);
    return 0;
}
