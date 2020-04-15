#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int scoreTF[100], scoreMC[100], scoreSA[100];
char TF[100][80], MC[100][80], SA[100][80];
char answerTF[100][80], answerMC[100][10][80], answerSA[100][80];
int numTF = 0, numMC = 0, numSA = 0;
int n = 0;
int point = 10;
void getType1(FILE *f){
    fscanf(f, "%d\n", &scoreTF[numTF]);
    fscanf(f, "%[^\n]\n", TF[numTF]);
    fscanf(f, "%[^\n]\n", answerTF[numTF++]);
}
void getType2(FILE *f){
    int numOfChoice = 0;
    fscanf(f, "%d\n", &scoreMC[numMC]);
    fscanf(f, "%[^\n]\n", MC[numMC]);
    fscanf(f, "%d\n", &numOfChoice);
    for (int i = 0; i < numOfChoice; i++)
        fscanf(f, "%[^\n]\n", answerMC[numMC][i]);
    //Read answer
    fscanf(f, "%[^\n]\n", answerMC[numMC++][numOfChoice]);
}
void getType3(FILE *f){
    fscanf(f, "%d\n", &scoreSA[numSA]);
    fscanf(f, "%[^\n]\n", SA[numSA]);
    fscanf(f, "%[^\n]\n", answerSA[numSA++]);
}
char first[10], last[10];
int getInputFile(FILE *f){
    char *filename = (char *)calloc(50, sizeof(char));
	printf("What is your first name ?\n");
	scanf("%s",first);
	printf("What is your last name ?\n");
	scanf("%s",last);
    fflush(stdin);
    printf("Whats file store your question ?\n");
    scanf("%[^\n]", filename); 
    f = fopen(filename, "r");
    fscanf(f, "%d",&n);
    fflush(stdin);
    for (int i = 1; i <= n; i++){
        char type[2];
        fscanf(f, "%s", type);
        if (strcmp(type, "TF") == 0)
            getType1(f);
        if (strcmp(type, "MC") == 0)
            getType2(f);
        if (strcmp(type, "SA") == 0)
            getType3(f);
    }
}
void questionType1(int pos)
{
    char *answer = (char *)calloc(50, sizeof(char));
    printf("Question: %s\n", TF[pos]);
    printf("YOUR ANSWER: ");
    fflush(stdin);
    scanf("%[^\n]", answer);
    if(strcmp(answer,"SKIP")==0){
    	point=point-scoreTF[pos];
    	printf("You have elected to skip that question.\n");
    	return;
	}
    if (strcmp(answer,answerTF[pos])==0){
	point=point+scoreTF[pos];
	printf("Correct! You get %d points.\n",scoreTF[pos]);
	}else{
	point=point-scoreTF[pos];
	printf("Incorrect, the answer was %s. You lose %d points!\n",answerTF[pos],scoreTF[pos]);
	}
}
void questionType2(int pos){
    int posChoice=0;
    char *answer = (char *)calloc(50, sizeof(char));
    printf("Question: %s\n", MC[pos]);
    while (1){
        int temp=strcmp(answerMC[pos][posChoice],"");
        if (temp==0) break;
        posChoice++;
    }
    for(int i=0;i<posChoice-1;i++) 
	printf("%c| %s\n",(char)(i+65),answerMC[pos][i]);
    printf("YOUR ANSWER: ");
    fflush(stdin);
    scanf("%[^\n]", answer);
    if(strcmp(answer,"SKIP")==0){
    	point = point - scoreMC[pos];
    	printf("You have elected to skip that question.\n");
    	return;
	}
    if (strcmp(answer,answerMC[pos][posChoice-1]) == 0) {
	point=point+scoreMC[pos];
	printf("Correct! You get %d points.\n",scoreMC[pos]);
	}else{
	point = point - scoreMC[pos];
	printf("Incorrect, the answer was %s. You lose %d points!\n",answerMC[pos],scoreMC[pos]);
	}
}
void questionType3(int pos){
    char *answer = (char *)calloc(50, sizeof(char));
    printf("QUIZ: %s\n", SA[pos]);
    printf("YOUR ANSWER: ");
    fflush(stdin);
    scanf("%[^\n]", answer);
    if(strcmp(answer,"SKIP")==0){
    	point = point - scoreSA[pos];
    	printf("You have elected to skip that question.\n");
    	return;
	}
    if (strcmp(answer,answerSA[pos])==0) {
	point = point + scoreSA[pos];
	printf("Correct! You get %d points.\n",scoreSA[pos]);
	}else{
	point = point - scoreSA[pos];
	printf("Incorrect, the answer was %s. You lose %d points!\n",answerSA[pos],scoreSA[pos]);
	}
}
void printInputFile(FILE *f){
    for (int i = 0; i < numTF; i++){
        printf("%s\nAnwer:%s\n", TF[i], answerTF[i]);
    }
    for (int i = 0; i < numMC; i++)
    {
        printf("%s\n", MC[i]);
        int j = 0;
        do
            printf("%s\n", answerMC[i][j++]);
        while (strlen(answerMC[i][j]) != 1);
    }
    for (int i = 0; i < numSA; i++)
    {
        printf("%s\nAnwer:%s\n", SA[i], answerSA);
    }
}
int random(int a, int b)
{
    return a + rand() % (b - a + 1);
}
void question(int type){
	printf("Points: %d\n",point);
    switch (type){
    case 1:
        questionType1(random(0, numTF - 1));
        break;
    case 2:
        questionType2(random(0, numMC - 1));
        break;
    case 3:
        questionType3(random(0, numSA - 1));
        break;
    }
}
void getRandomQuestion(FILE *f){
    int num;
    bool check;
    while (true){
        printf("How many questions would you like (out of %d)?\n",n);
        scanf("%d", &num);
        if (num <= n){
        	
            break;
		}else if(num > n){
			printf("Sorry, that is too many.\n");
			check = true;
		}else{
			printf("Sorry, that is not valid.\n");
			check = true;
		}
    }
    srand(time(NULL));
    while (num--) question(random(1, n)); //Random types of question
}
int main(){
    FILE *f;
    getInputFile(f);
    getRandomQuestion(f);
    printf("%s %s, your game is over!\n",first,last);
    printf("Your final score is %d points.\n",point);
    printf("Better luck next time!\n");
    system("pause");
}
