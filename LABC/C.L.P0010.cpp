#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0;
char key[50][100], variable[50][100];
int time[100];
void menu(){
	int choice;
	printf("============= Memcache =============\n");
	printf("\n1) Store data\n");
	printf("2) Retrieve item\n");
	printf("3) Delete item\n");
	printf("4) Flush all existing items\n");
	printf("5) Exit the program.\n");
}
void Store(){
	printf("\nEnter your key: ");
	fflush(stdin);
	scanf("%[^\n]",key[i]);
	printf("Enter your variable: ");
	fflush(stdin);
	scanf("%[^\n]",variable[i]);
	printf("Enetr expire time: ");
	scanf("%d",&time[i]);
	printf("\nStore data success with key '%s', using on-the-fly compression expire time is %d seconds.\n",key[i],time[i]);
	i++;
}
int findKey(char keyy[100]){
	int j;
	for(j=0;j<i;j++){
		if(strcmp(key[j],keyy)==0){
			return j;
		}
		return -1;
	}
}
void Retrieve(){
	char keyy[50];
	printf("\nEnter your key: ");
	fflush(stdin);
	scanf("%[^\n]",&keyy);
	if(findKey(keyy)==-1){
		printf("Store data key not exist...\n");
	}else{
		int index = findKey(keyy);
		printf("\nYour data is: %s\n",variable[index]);
	}
}
void Delete(){
	char keyy[50];
	printf("\nEnter your key: ");
	fflush(stdin);
	scanf("%[^\n]",&keyy);
	if(findKey(keyy)==-1){
		printf("Store data key not exist, do not delete...\n");
		return;
	}else{
		int index = findKey(keyy);
		strcpy(key[index],key[i]);
		strcpy(variable[index],variable[i]);
		time[index]=time[i];
		i--;
		printf("\nDelete success.\n");
	}
}
void Flush(){
	for(int j = 0;j<i;j++){
		strcpy(key[j],key[j+1]);
		strcpy(variable[j],variable[j+1]);
		time[j]=time[j+1];
	}
	i=0;
}
int main(){
	int c;
	menu();
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				Store();
				break;
			case 2:
				Retrieve();
				break;
			case 3:
				Delete();
				break;
			case 4:
				Flush();
				break;
			default:
				printf("Exit\n");
				exit(1);
		}
	}while(c>0&&c<4);
	
return 0;
}

