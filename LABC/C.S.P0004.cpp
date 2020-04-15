#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void toLower(char *s)
{
    for (int i = 0; i < strlen(s); i++)
        if (isupper(s[i]))
            s[i] += 32;
}
void display(char *arr1, int *arr2)
{
    toLower(arr1);
    for (int i = 0; i < strlen(arr1); i++)
    {
        char a = arr1[i];
        int b = 1;
        if (a == ' ')
        {
            for (int l = i; l < strlen(arr1); l++)
                arr1[l] = arr1[l + 1];
            i--;
            continue;
        }
        for (int j = i + 1; j < strlen(arr1); j++)
        {
            if (a == arr1[j])
            {
                for (int k = j; k < strlen(arr1); k++)
                    arr1[k] = arr1[k + 1];
                b++;
                j--;
            }
        }
        arr2[i] = b;
    }
    for (int i = 0; i < strlen(arr1); i++)
        printf("%-5c", arr1[i]);
    printf("\n");
    for (int i = 0; i < strlen(arr1); i++)
        printf("%-5d", arr2[i]);
}
void timesOfAppearance(int *arr2, char *arr1)
{
    int max = 0;
    for (int i = 0; i < strlen(arr1); i++)
    {
        for (int j = i + 1; j < strlen(arr1); j++)
            if (arr2[max] < arr2[j])
                max = j;
    }
    printf("\n");
    for (int i = 0; i < strlen(arr1); i++)
        if (arr2[max] == arr2[i])
            printf("%-5c", arr1[i]);
    printf("\n");
    for (int i = 0; i < strlen(arr1); i++)
        if (arr2[max] == arr2[i])
            printf("%-5d", arr2[i]);
}

int main()
{
    char str[50];
    int a[20];
    char key;
    do{
        //input string
		printf("\nInput a string: ");
		gets(str);
        printf("Times of appearance for each character:\n");
        display(str, a);
        printf("\n--------------------------------------------------\n");
        printf("Characters that appears the most:");
        timesOfAppearance(a, str);
        printf("\nPress any key to continue, ESC to exit.\n\n");
        fflush(stdin);
        key = getch();
    }while(key != 27);
}
