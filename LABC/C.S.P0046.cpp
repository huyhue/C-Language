#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int checkPrime(int n);
void outputPrime(int n);
int checkFibo(int n);
int sum(int n);
void menu();
int main(){
    while (true){
    	menu();
        int choice, n;
        printf("Choose an option: ");
        scanf("%d", &choice);
        if (choice == 0)  return 0;
        switch (choice){
	        case 1:
	            outputPrime(n);
	            break;
	        case 2:
	            printf("Number tested:");
	            scanf("%d", &n);
	            if (checkFibo(n) == 1){
	            	printf("It's fibonacci term\n");
	                printf("\n");
				} 
	            else{
	            	printf("It's not fibonacci term\n");
	                printf("\n");
				}
	            break;
	        case 3:
	            printf("Enter an integer: ");
	            scanf("%d", &n);
	            sum(n);
	            break;
	        default:
	            printf("Don't have option! Let choice again\n");
	            break;
        }
    }
}
int checkPrime(int n){
    int i;
    if (n < 2) return 0;
    for (i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void outputPrime(int n){
    int dem = 1;
    printf("Number of primes:");
    scanf("%d", &n);
    for (int i = 1;; i++){
        if (checkPrime(i) == 1){
            printf("%d  ", i);
            dem++;
        }
        if (dem > n) break;
    }
    printf("\n");
    printf("\n");
}
int checkFibo(int n){
    int f1 = 1, f2 = 1, f3;
    if (n == 0 || n == 1) return 1;
    while (f1 + f2 <= n){
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    if (f3 == n) return 1;
    else return 0;
}
int sum(int n){
    int temp, s = 0;
    while (n != 0){
        temp = n % 10;
        s += temp;
        n /= 10;
    }
    printf("Sum of it's digits: %d\n", s);
    printf("\n");
}
void menu(){
    printf("1-The first primes\n");
    printf("2-Fibonacci element\n");
    printf("3-Sum of digits\n");
}
