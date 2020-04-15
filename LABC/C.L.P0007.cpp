#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define numPeg 4
#define numValue 6

void menu(){
	printf("Welcome to MasterMind!!\n\n");
	printf("At each turn, you will enter your guess for the playing board.\n");
	printf("A valid guess ahs 4 values in between 0 and 5.\n");
	printf("Each guess will have each number within the guess separated by a space.\n");
	printf("When you are ready, enter your first guess.\n");
	printf("From the point on, you will be told how many perfect and imperfect matches you have.\n");
	printf("After this message, you should guess again. You have 10 chances, good luck!\n\n");
}
void input(int *guess){ // Nhap 4 so du doan
	int value;
	for (int i = 0; i < numPeg; i++)
		scanf("%d", &guess[i]);
}
void resultValue(int *result){ // 4 so ma de bai cho
	srand((int)time(0));
	for (int i = 0; i < numPeg; i++)
		result[i] = rand() % numValue;
}
void displayResult(int arr[]){
	for (int i = 0; i < numPeg; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int checkPerfect(int *guess, int *result, int *copy, int *num){
	int n = 0;
	for (int i = 0; i < *num; i++){
	 //copy ra 1 ham moi giong het dung de xoa cac phan tu perfect
		copy[i] = result[i];
	}
	for (int i = 0; i < *num; i++){
		if (guess[i] == copy[i]){
			n++;
			if (n == 4)
				continue; //bo bot cac lenh phia duoi, khong gay ra ton them thao tac
			for (int j = i; j < (*num) - 1; j++){ 
			//xoa cac cap perfect o ca 2 mang, phuc vu cho viec tim so imperfect
				guess[j] = guess[j + 1];
				copy[j] = copy[j + 1];
			}
			(*num)--;
			i--;
		}
	}
		
	return n;
}
int checkImperfect(int *guess, int *copy, int num){
	int n = 0;
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			if (guess[i] == copy[j]){
				n++;
				copy[j] = copy[j + 1]; //xoa luon phan tu da imperfect
				num--;
			}
		}
	}	
	return n;
}

int main(){
	int guess[numPeg], result[numPeg], copy[numPeg], start, end, perfect, imperfect, count = 0, minute, second;
	menu();
	resultValue(result);
	printf("Result: ");
	displayResult(result);
	start = time(0);
	while (count < 10){
		int num = numPeg;
		input(guess);
		perfect = checkPerfect(guess, result, copy, &num);
		count++;
		if (perfect == 4){
			printf("You have 4 perfect matches and 0 imperfect matches.\n");
			end = time(0);
			minute = (end - start) / 60;
			second = (end - start) % 60;
			printf("Your have won the game in %d turns and %02d:%02d!!!\n", count, minute, second);
			break;
		}
		else{
			imperfect = checkImperfect(guess, copy, num);
			printf("You have %d perfect matches and %d imperfect matches.\n", perfect, imperfect);
		}
	}

	if (perfect != 4){
		printf("Sorry, you have exceeded the maximum number of turns. You lose.\n");
		printf("Here is the winning board: ");
		displayResult(result);
	}
//	system("pause");
}
