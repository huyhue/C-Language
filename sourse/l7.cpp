#include<stdio.h>
#define numPeg 4
#define numValue 6
#include <time.h>
#include <stdlib.h>
void resultValue(int *result){
	srand((int)time(0));
	for(int i = 0;i < numPeg; i++){
		result[i] = rand() % numValue;
	}
}
void displayResult(int arr[]){
	for(int i=0;i<numPeg;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void input(int *guess){
	printf("Enter 4 number:\n");
	for(int i = 0; i < numPeg; i++){
		scanf("%d", &guess[i]);
	}
}
int checkPerfect(int *guess, int *result, int *copy, int* num){
	int n = 0;
	for(int i = 0 ;i < *num; i++){
		copy[i] = result[i];
	}
	for(int i = 0; i < (*num); i++){
		if(guess[i] == copy[i]){
			n++;
			if(n == 4) 
				continue;
			for(int j = i ; j < (*num)-1; j++){
				guess[j] = guess[j + 1];
				copy[j] = copy[j + 1];
			}
			(*num)--;
			i--;
		}
	}
	return n;
}
//int checkPerfect(int *guess, int *result, int *copy, int *num){
//	int n = 0;
//	for (int i = 0; i < *num; i++){
//	 //copy ra 1 ham moi giong het dung de xoa cac phan tu perfect
//		copy[i] = result[i];
//	}
//	for (int i = 0; i < *num; i++){
//		if (guess[i] == copy[i]){
//			n++;
//			if (n == 4)
//				continue; //bo bot cac lenh phia duoi, khong gay ra ton them thao tac
//			for (int j = i; j < (*num) - 1; j++){ 
//			//xoa cac cap perfect o ca 2 mang, phuc vu cho viec tim so imperfect
//				guess[j] = guess[j + 1];
//				copy[j] = copy[j + 1];
//			}
//			(*num)--;
//			i--;
//		}
//	}
//		
//	return n;
//}
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
	int result[numPeg], guess[numPeg],copy[numPeg];
	printf("Play now:\n");
	resultValue(result);
	printf("Result: ");
	displayResult(result);
	
	int start = time(0);
	int count = 0;
	int perfect, imperfect;
	while(count < 10){
		int num = numPeg;
		input(guess);
		perfect = checkPerfect(guess, result, copy, &num);
		count++;
		if(perfect == 4){
			printf("You win...\n");
			int end = time(0);
			int minute = (end-start) / 60;
			int second = (end-start) % 60;
			printf("With %d turns and %02d:%02d", count, minute, second);
			break;
		}else{
			imperfect = checkImperfect(guess, copy, num);
			printf("You have %d perfect and %d imperfect\n",perfect,imperfect);
		}
	}
	if(perfect != 4){
		printf("you lost:");
		displayResult(result);
	}
return 0;
}

