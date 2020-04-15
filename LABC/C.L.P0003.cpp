#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int checkWin(int n){
    int a = n%10;	n/=10;
    int b = n%10;	n/=10;
    int c = n;
    printf("The slot machine shows %d%d%d.\n",c,b,a);
    if ((a==b) && (b==c)) return 2;
    if ((a==b) || (a==c) || (b==c)) return 1;
    return 0;
}
void play(float*money){
    int n = 100 + rand()%(999-100+1);
    int win = checkWin(n);
    switch(win){
        case 0:	printf("Sorry you don't won anything.\n");	break;
        case 1:	printf("You win 50 cents!\n");*money += 0.5;break;
        case 2:printf("You win the big prize, $10.00!\n");*money+=10;break;
    }
}
void drawMenu(float*money, int*choice){
    printf("You have $%.2f.\n",*money);
    printf("Choose one of the following menu options:\n");
    printf("1) Play the slot machine.\n");
    printf("2) Save game.\n");
    printf("3) Cash out.\n");
    scanf("%d",choice);
}
int main(){
    int choice, stop = 0;
    float money;
    srand(time(NULL));
    FILE*f = fopen("D:\\lab.txt","w+");
 	fputs("10",f);
  	rewind(f);
  	fscanf(f,"%f",&money);
    while (stop == 0){
        if ((int)money == 0){
            printf("Sorry, you out of money, exitting...\n");
            system("pause");
            break;
        }
        drawMenu(&money, &choice);
        switch (choice){
        case 1 :
				money -= 0.25;
                play(&money);
                break;
        case 2 :
				printf("Your money had saved \n");
                rewind(f);
                fprintf(f,"%.2f",money);
                break;
        case 3 :printf("Thank you for playing! You end with $%.2f!\n",money);stop=1;
                rewind(f);
                fprintf(f,"0");
                break;
        default:printf("Choice again !\n");
                break;
        }
    }
    fclose(f);
}
