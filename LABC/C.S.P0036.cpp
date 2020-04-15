#include<stdio.h>
#include<string.h>
#include<ctype.h>
void dem(char *arr1, int *arr2)
{
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
        printf("%c: %d \n", arr1[i], arr2[i]);
}
int main(){
	char str[100];
	int a[50];
	printf("Enter a string: ");
	fflush(stdin);
	gets(str);
	strlwr(str);
	dem(str, a);
	return 0;
}

