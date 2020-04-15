#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
int a[100000],soft[100000],n=0;

void Add()
{
    int num;
    printf("Type 1 NUMBER to add: "); scanf("%d",&num);
    n++;
    a[n]=num;
    printf("Number added!\n");
}

void Search()
{
    int count=0,num,n;
    printf("Type value: "); scanf("%d",&num);
    for(int i=1; i<=n; i++)
    {
        if (a[i]==num) count++;
    }
    printf("There are(is) %d existences of number \"%d\"\n", count, num);
}

void Print()
{
    printf("Value in the array\n");
    for (int i=1; i<=n; i++) printf("%d ",a[i]);
    printf("\n");
}

void Range()
{
    int minVal,maxVal;
    printf("Type minVal: "); scanf("%d",&minVal);
    printf("Type maxVal: "); scanf("%d",&maxVal);
    for (int i=1; i<=n; i++)
    {
        if ((a[i]<=maxVal)&&(a[i]>=minVal)) printf("%d ",a[i]);
    }
    printf("\n");
}

void Soft()
{
    int num;
    for (int i=1; i<=n; i++) soft[i]=a[i];
    for (int i=1; i<=(n-1); i++)
    for (int j=i+1; j<=n; j++)
    {
        if (soft[i]>soft[j])
        {
            num=soft[i];
            soft[i]=soft[j];
            soft[j]=num;
        }
    }
    printf("Value in ascending order\n");
    for (int i=1; i<=n; i++) printf("%d ",soft[i]);
    printf("\n");
}

int getKey()
{
    int key;
    system("cls");
    printf("1- Add a value\n");
    printf("2- Search a value\n");
    printf("3- Print out the array\n");
    printf("4- Print out values in a range\n");
    printf("5- Print out the array in ascending order\nOther- Quit\n");
    scanf("%d",&key);
    return key;
}

int main()
{
    int key=1;

    while ((key>=1)&&(key<=5))
    {
        key=getKey();
        switch(key)
        {
            case 1:
                Add();
                break;
            case 2:
                Search();
                break;
            case 3:
                Print();
                break;
            case 4:
                Range();
                break;
            case 5:
                Soft();
                break;
            default:
                printf("Program excuted !\n");
                break;
        }
        system("pause");
    }
    return 0;
}
