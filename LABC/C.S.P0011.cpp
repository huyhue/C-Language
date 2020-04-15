#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
void menu();
int choice();
int binaryToDecimal(long long n);
int octalToDecimal(int octalNumber);
void hexaToDecimal();
void mainProgram();
int main(){
	int key;
	do{
		mainProgram();
		printf("Press enter to coninue, Esc to return the main menu\n");
		key = getch();
	}while(key != 27);
}
void menu(){
    printf("1.Convert binary number to decimal number\n");
    printf("2.Convert octal number to decimal number\n");
    printf("3.Convert hexadecimal number to decimal number\n");
    printf("4.Exit\n");
}
int choice(){
    int c;
    printf("Please choose number(1 - 4):");
    scanf("%d", &c);
    return c;
}
int binaryToDecimal(long long n){
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0){
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}
int octalToDecimal(int octalNumber){
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
void hexaToDecimal(){
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    printf("Enter hexadecimal number: ");
    gets(hex);

    len = strlen(hex);
    len--;

    for (i = 0; hex[i] != '\0'; i++)
    {

        if (hex[i] >= '0' && hex[i] <= '9')
        {
            val = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            val = hex[i] - 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
    printf("Decimal number is: %lld\n", decimal);
}
void mainProgram(){
    int ch;
    menu();
    do{
        ch = choice();
        switch (ch){
	        case 1:
	            int n1;
	            printf("Enter binary number: ");
	            scanf("%d", &n1);
	            printf("Decimal number is: %d\n", binaryToDecimal(n1));
	            break;
	        case 2:
	            int n;
	            printf("Enter octal number: ");
	            scanf("%d", &n);
	            printf("Decimal number is: %d\n", octalToDecimal(n));
	            break;
	        case 3:
	            hexaToDecimal();
	            break;
	        case 4:
	            break;
        }
    }while (ch < 1 || ch > 4);
}
