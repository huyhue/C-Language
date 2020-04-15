#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
char a[100];
int end=0,n,k;

int ASCII(char c)
{
    return (int)c-48;
}
//-----------------------------------------------------------------
void getInput()
{
    printf("Type the ISBN (type \"0\" to quit)\n"); scanf("%s",a);
    //CHECK EXIT---------------------------------------------------
    if ((a[0]=='0')&&(strlen(a)==1))
    {
        printf("Have a nice day !\n");
        end=1;
        return;
    }
    //CHECK STRING-------------------------------------------------
    if (strlen(a)!=10)
    {
        printf("Wrong format! Please type agian!\n");
        getInput();
    }
}
//CALCULATOR--------------------------------------------------------
int Conver()
{
    int s=0;
    for (int i=1; i<=9; i++)
    {
        s+=ASCII(a[i])*(11-i);
    }
    if (((s+ASCII(a[9]))%11)==0) return 1;
    return 0;
}
//-----------------------------------------------
int main()
{
    while (end==0)
    {
        system("cls");
        printf("ISBN Validator\n-------------\n");
        getInput();
        switch (end)
        {
            case 0:
                if (Conver()) printf("This is valid ISBN\n");
                 else printf("This is not a valid ISBN\n");
                break;
            case 1:
                printf("Program excuted !\n");
                break;
        }
        system("pause");
    }
    return 0;
}
