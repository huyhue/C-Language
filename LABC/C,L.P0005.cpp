#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int numbersOfTotalFlight,maxDay=0;
int seat[100][100]; //seat[numberOfFlight,numberOfDay]
char from[100][30],to[100][30];
int check(char*a,char*b,int start,int end,int seats)
{
    int hasCity=0,validDay=0,hasSeat=1;
    for (int i=0;i<numbersOfTotalFlight;i++)
        if ((strcmp(a,from[i])==0)&&(strcmp(b,to[i])==0)) {
            hasCity=i; 
            for (int j=start;j<=end;j++) 
                if (seats>seat[i][j]) hasSeat=0; 
            break;
        }
    if (start<end) validDay=1;
    if (!hasCity) return -3;
    if (!validDay)return -2;
    if (!hasSeat) return -1;
    if(end>10) return -4;
    return hasCity;
}
void makingReservation(int pos,int start,int end,int seats)
{
    if (maxDay<end) maxDay=end;
    for (int i=start;i<=end;i++) seat[pos][i]-=seats;
}
void makeResetvation()
{
    char*name=(char*)calloc(30,sizeof(char));
    char*from=(char*)calloc(30,sizeof(char));
    char*to=(char*)calloc(30,sizeof(char));
    int startDay;int endDay;int seats;
    fflush(stdin);
    printf("What is your name, first followed by last?\n"); scanf("%[^\n]",name);
    printf("From which city do you want to fly?\n"); scanf("%s",from);
    printf("What is your destination city?\n"); scanf("%s",to);
    printf("Which day do you want to leave?\n"); scanf("%d",&startDay);
    printf("Which day do you want to come back?\n"); scanf("%d",&endDay);
    printf("How many seats do you want?\n"); scanf("%d",&seats);
    int temp=check(from,to,startDay,endDay,seats);
    if (temp>0) {
        makingReservation(temp,startDay,endDay,seats);
        printf("Thanks! The reservation has been make.\n");
        return;
    }
    printf("Sorry, that reservation could not be made.\n");
    switch (temp)
    {
    case -1:printf("Not enought seats are avaiable.\n"); 
            break;
    case -2:printf("You must come back on a later date than you leave!\n");
            break;
    case -3:printf("Don't have fight from %s to %s\n",from,to);
            break;
    case -4:printf("The days of flight are invalid.\n");
    		break;
    }
}
void printListOfFile(int n)
{
    printf("TOTAL FLIGHT: %d\n",n);
    printf("From\t\t\t   To\t\tSeat\n");
    for (int i=1;i<=n;i++) printf("%-20s %12s %10d\n",from[i],to[i],seat[i][1]);
}
void printListOfFlights(int n)
{
    printf("TOTAL FLIGHT: %d\n",n);
    for (int j=1;j<=9;j++)
    {	printf("\n=============================================\n");
        printf("DAY: %d\n",j);
        for (int i=1;i<=n;i++) printf("%-20s %12s %10d\n",from[i],to[i],seat[i][j]);
    }
}
int printMenu()
{
    int choice;
    printf("Which of the following you want?\n");
    printf("1) Make a resetvation\n");
    printf("2) Print out a listing of all flights\n");
    printf("3) Quit\n");
    printf("Your choice (1/2/3)? : ");
    scanf("%d",&choice);
    return choice;
}

int main()
{ 
    FILE*f=fopen("D:\\flights.txt","r");
    int choice;
    fscanf(f,"%d",&numbersOfTotalFlight); fflush(stdin);
    for (int i=1;i<=numbersOfTotalFlight;i++)
    {
        fscanf(f,"%s",from[i]);
        fscanf(f,"%s",to[i]);
//        char temp1=fscanf(f,"%c",&temp1);
        int temp2;
        fscanf(f,"%d",&temp2);
        for (int j=1;j<=9;j++) seat[i][j]=temp2;
    }
    while (choice!=3)
    {
        system("cls");
        choice=printMenu();
        switch(choice)
        {
        case 1: makeResetvation();            
                break;
        case 2: printListOfFlights(numbersOfTotalFlight);   
                break;
        case 3: printf("Have a nice day!\n"); 
                break;
        default:printf("Choice again!\n");    
                break;
        }
        system("pause");
    }
    return 0;
}
