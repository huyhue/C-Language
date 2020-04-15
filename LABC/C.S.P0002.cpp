#include<stdio.h>
#include<conio.h>

//input string
void input(int &n){
	printf("\nEnter a number from 0 to 9999:");
	scanf("%d",&n);
}

//in hang don vi
void inDonVi(int donVi,int chuc){
	if(chuc >1){
		switch(donVi){
		case 0: printf(""); 
			break;
		case 1: printf(" one"); 
			break;
		case 2: printf(" two"); 
			break;
		case 3: printf(" three"); 
			break;
		case 4: printf(" four"); 
			break;
		case 5: printf(" five"); 
			break;
		case 6: printf(" six"); 
			break;
		case 7: printf(" seven"); 
			break;
		case 8: printf(" eight"); 
			break;
		case 9: printf(" nine"); 
			break;
		}
	}
	
}

//in hang chuc
void inChuc(int chuc,int donvi){
	switch(chuc){
		case 1: switch(donvi){
			case 1: printf("eleven");break;
			case 2:printf("twelve");break;
			case 3:printf("thirteen");break;
			case 4:printf("fourteen");break;
			case 5: printf("fiveteen");break;
			case 6: printf("sixteen");break;
			case 7: printf("seventeen");break;
			case 8:printf("eighteen");break;
			case 9:printf("nineteen");break;
		}break;
		case 2: printf("twenty"); 
			break;
		case 3: printf("thirty"); 
			break;
		case 4: printf("forty"); 
			break;
		case 5: printf("fifty"); 
			break;
		case 6: printf("sixty"); 
			break;
		case 7: printf("seventy"); 
			break;
		case 8: printf("eighty"); 
			break;
		case 9: printf("ninety"); 
			break;
	}
}
//in hang tram
void inTram(int tram){
	switch(tram){
		case 1: printf("one hundred "); 
			break;
		case 2: printf("two hundred "); 
			break;
		case 3: printf("three hundred "); 
			break;
		case 4: printf("four hundred "); 
			break;
		case 5: printf("five hundred "); 
			break;
		case 6: printf("six hundred "); 
			break;
		case 7: printf("seven hundred "); 
			break;
		case 8: printf("eight hundred "); 
			break;
		case 9: printf("nine hundred "); 
			break;
	}
}

//in hang ngan
void inNgan(int ngan){
	switch(ngan){
		case 1: printf("One thousand "); 
			break;
		case 2: printf("Two thousand "); 
			break;
		case 3: printf("Three thousand "); 
			break;
		case 4: printf("Four thousand "); 
			break;
		case 5: printf("Five thousand "); 
			break;
		case 6: printf("Six thousand "); 
			break;
		case 7: printf("Seven thousand "); 
			break;
		case 8: printf("Eight thousand "); 
			break;
		case 9: printf("Nine thousand "); 
			break;
	}
}

//convert string
void convert(int n){
	if(n == 0) printf("zero");
	else if(n == 1) printf("one");
	else if(n == 2) printf("two");
	else if(n == 3) printf("three");
	else if(n == 4) printf("four");
	else if(n == 5) printf("five");
	else if(n == 6) printf("six");
	else if(n == 7) printf("seven");
	else if(n == 8) printf("eight");
	else if(n == 9) printf("nine");
	else if(n == 10) printf("ten");
	else if(n == 11) printf("eleven");
	else if(n == 12) printf("twelve");
	else if(n == 13) printf("thirteen");
	else if(n == 14) printf("fourteen");
	else if(n == 15) printf("fifteen");
	else if(n == 16) printf("sixteen");
	else if(n == 17) printf("seventeen");
	else if(n == 18) printf("eighteen");
	else if(n == 19) printf("nineteen");
	else if(n >= 20 && n < 100){
		int chuc;
		int donvi;
		chuc = n / 10;
		donvi = n % 10;
		inChuc(chuc,donvi);
		inDonVi(donvi,chuc);
	}
	else if(n >= 100 && n < 1000){
		int tram, chuc, donvi;
		tram = n / 100;
		chuc = n % 100 / 10;
		donvi = n % 100 % 10;
		inTram(tram);
		inChuc(chuc,donvi);
		inDonVi(donvi,chuc);
	}
		else if(n >= 1000 && n < 10000){
		int ngan, tram, chuc, donvi;
		ngan = n / 1000;
		tram = n % 1000 / 100;
		chuc = n % 100 / 10;
		donvi = n % 100 % 10;
		inNgan(ngan);
		inTram(tram);
		inChuc(chuc,donvi);
		inDonVi(donvi,chuc);
	}
}

int main(){
	int n, key;
	do{
		input(n);
		//output a string
		convert(n);	
		printf("\nPress enter to continue or ESC to exit: ");
		key = getch();
	} while(key != 27);
	return 0;
}

