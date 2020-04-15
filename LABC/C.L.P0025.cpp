#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include<string.h>
int withdraw;int accoun, transfer;
int n = 0;
struct acc{
	int account;
	int pin;
	int balances;
	char id[MAX], type[MAX];
	char name[MAX];
	char tran[50][MAX], with[50][MAX];
};
struct acc bank[100];
void LoadData(){
    FILE *f = fopen("D://bank.txt", "r");
    if (f == NULL){
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for(int i = 0; i < MAX; i++){
        fscanf(f, "%d\n", bank[i].account);
        fscanf(f, "%d\n", bank[i].pin);
        fscanf(f, "%d\n", bank[i].balances);
        fscanf(f, "%s\n", bank[i].id);
        fscanf(f, "%s\n", bank[i].type);
        fscanf(f, "%[^\n]s\n", bank[i].name);
        fscanf(f, "%[^\n]s\n", bank[i].tran);
        fscanf(f, "%[^\n]s\n", bank[i].with);
        if (bank[i].name == NULL){
            n = i;
            break;
        }
    }
    fclose(f);
}
void WriteStudent(){
    FILE *f = fopen("D://bank.txt", "w+");
    if (f == NULL){
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < n; i++){
        fprintf(f, "%d\n", bank[i].account);
        fprintf(f, "%d\n", bank[i].pin);
        fprintf(f, "%d\n", bank[i].balances);
        fprintf(f, "%s\n", bank[i].id);
        fprintf(f, "%s\n", bank[i].type);
        fprintf(f, "%s\n", bank[i].name);
        if(transfer!=NULL){
        	fprintf(f, "%s was tranfer\n",  bank[i].account);
		}else{
			fprintf(f, " no %s\n", bank[i].tran);
		}
		if(withdraw!=NULL){
        	fprintf(f, "%d was withdraw &d\n", bank[i].account,bank[i].balances);
		}else{
			fprintf(f, "no %s\n", bank[i].with);
		}
    }
    fclose(f);
}
void menu(){
	printf("\n===========================\n");
	printf("1. Login\n");
	printf("2. Register account\n");
	printf("3. Withdraw money\n");
	printf("4. Transfer money\n");
	printf("Select choice: ");
}
int Check(int acc, int p){
	for(int i ; i < n; i++){
		if(acc == bank[i].account && p == bank[i].pin){
			return i;
		}
	}
	return -1;
}
int pos;
void Login(){
	int acc, p;
	printf("\n======Please login=======\n");
	printf("Enter account: ");
	scanf("%d",&acc);
	printf("Enter PIN: ");
	scanf("%d",&p);
	int index = Check(acc,p);
	if(index==-1){
		printf("Your enter wrong account and PIN, please enter again.\n");
		return;
	}else{
		printf("Login success.\n");
		printf("your current balance is %d \n",bank[index].balances);
		pos = index;
	}
}
void Register(){
	int accoun, pi, ba;
	char id[20], ty[4],na[30];
	printf("\n======Please Register=======\n");
	printf("Enter account: ");
	scanf("%d",&accoun);
	printf("Enter PIN: ");
	scanf("%d",&pi);
	printf("Enter ID (account code): ");fflush(stdin);
	scanf("%s",id);
	printf("Enter account name: ");fflush(stdin);
	scanf("%[^\n]",na);
	printf("Enter balances: ");
	scanf("%d",&ba);
	printf("Enter money type: ");fflush(stdin);
	scanf("%s",ty);
	int index = Check(accoun,pi);
	if(index == -1){
		printf("account and PIN had user other use, please enter again.\n");
		return;
	}else{
		bank[n-1].account= accoun;
		bank[n-1].pin= pi;
		strcpy(bank[n-1].id,id);
		strcpy(bank[n-1].name,na);
		bank[n-1].balances= ba;
		strcpy(bank[n-1].type, ty);
		printf("Resgister success.\n");
		n++;
	}
	
}

void Withdraw(){
	Login();
	printf("Enter money you want withdraw: ");
	scanf("%d",&withdraw);
	if(withdraw >= bank[pos].balances){
		printf("Sorry insufficent balance.\n");
	}else{
		bank[pos].balances -= withdraw;
		printf("Your current balance is %d \n",bank[pos].balances);
	}
}

void Transfer(){
	Login();
	printf("Enter destination account: ");
	scanf("%d",&accoun);
	for(int i=0;i<n;i++){
		if(bank[i].account==accoun){
			printf("Enter money you want transfer: ");
			scanf("%d",&transfer);
			bank[i].balances += transfer;
			bank[pos].balances -= transfer;
			printf("You transfer successing...\n");
		}else{
			printf("This account don's exist in system bank.\n");
			return;
		}
	}
	
}
int main(){
	int c;
	do{
		menu();
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("===========Login=========\n");
				Login();
				break;
			case 2:
				printf("===========Register=========\n");
				Register();
				break;
			case 3:
				printf("===========Withdraw=========\n");
				Withdraw();
				break;
			case 4:
				printf("===========Transfer=========\n");
				Transfer();
				break; 
			default:
				printf("Thanks using service ATM.\n");
				exit(1);
		}
	}while(c>0&&c<5);
return 0;
}

