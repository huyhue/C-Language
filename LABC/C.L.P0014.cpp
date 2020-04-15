#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int money = 1000;
int chips = 0;
int cash;
int menu(){
	printf("Welcome to the Casino. Here are your choices:\n");
	printf("1) Buy chips\n");
	printf("2) Sell chips\n");
	printf("3) Play Craps\n");
	printf("4) Play Arup's Game of Dice\n");
	printf("5) Status Report\n");
	printf("6) Quit\n");
	int choice;
	scanf("%d",&choice);
	return choice;
}
void Sell(){
	 int sellchips;
    printf("How many chips do you want to sell?\n");
    scanf("%d", &sellchips);
    if (sellchips > chips){
        printf("Sorry, not enough chip to sell!\n");
    }else{
        chips -= sellchips;
        money += sellchips * 10;
    }
}
void Buy(){
	printf("How much cash do you want to spend for chips?\n");
	scanf("%d",&cash);
	if(cash > money){
		printf("Sorry, you do not have that much money. No chips bought.\n");
	}else{
		chips += cash / 11;
		money -= (cash - cash % 11);
	}
}
void Report(){
	printf("You currently have $%d left and %d chips.\n",money,chips);
}
int randomize(){
    srand(time(NULL));
    return 2 + rand()%(12+1-2);
}
void PlayCraps(){
    char r;
    int random;
    int betchips;
    printf("How many chips do you want to bet?\n");
    scanf("%d",&betchips);

    if (betchips == 0){
        printf("Sorry, that is not allowed. No game played.\n");
        return;
    }else if (betchips > chips){
        printf("Sorry, that is not allowed. No game played.");
        return;
    }else{
        do
        {
            fflush(stdin);
            printf("Press 'r' and hit enter your first roll\n");
            scanf("%c",&r);
        }while(r!='r');

        random = randomize();
        printf("You rolled a %d.\n", random);

        if (random == 7 || random == 11){
                printf("You win!");
                chips += betchips;
        }else if (random == 2 || random == 3 || random == 12){
                printf("You lose!\n");
                chips -= betchips;
        }else{
            check:
            int prediction;
                    do {
                        fflush(stdin);
                        printf("Press 'r' and hit enter your next roll.\n");
                        scanf("%c",&r);
                    }while(r!='r');


                    prediction = randomize();
                    printf("You rolled a %d.\n",prediction);
                        if (prediction == random){
                                printf("You win!\n");
                                chips += betchips;
                            }else if (prediction == 7){
                                    printf("You lose!\n");
                                    chips -= betchips;
                            }else goto check;
        }
    }
}
void PlayArup(){
	char r;
	int chipbet, ram, ram1;
    printf("How many chips would you like to bet?\n");
    scanf("%d",&chipbet);
    
    if(chipbet == 0){
    	printf("Sorry, you do not have that many chips to bet. No game played.\n");
    	return;
	}else if(chipbet > chips){
		printf("Sorry, you do not have that many chips to bet. No game played.\n");
		return;
	}else{	
		do{
			fflush(stdin);
			printf("Press 'r' and hit enter for your first roll.\n");
			scanf("%s",r);
		}while(r!='r');
		
		ram = randomize();
		printf("You roller a %d\n",ram);
		
		if(ram == 11 && ram == 12){
			printf("You win.\n");
			chips += chipbet;
		}else if(ram == 2){
			printf("You lost.\n");
			chips -= chipbet;
		}else{
			checkk:
			do{
				fflush(stdin);
				printf("Press 'r' and hit enter for your next roll.\n");
				scanf("%s",r);
			}while(r!='r');
			
			ram1 = randomize();
			if(ram1 == ram || ram1 < ram){
				printf("You lost.\n");
				chips -= chipbet;
			}else if(ram1 > ram){
				printf("You win.\n");
				chips += chipbet;
			}else goto checkk;
		}
	}
}
int main(){
	int c;
	do{
		c = menu();
		switch(c){
			case 1:
				Buy();
				break;
			case 2:
				Sell();
				break;
			case 3:
				PlayCraps();
				break;
			case 4:
				PlayArup();
				break;	
			case 5:
				Report();
				break;	
			case 6:
				printf("After selling your chips, you have $d. Thanks for playing!\n",money);
				exit(1);
		}
	}while(c > 0 && c < 6);
return 0;
}

