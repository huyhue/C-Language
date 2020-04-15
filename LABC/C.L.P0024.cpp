#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char nameWord[15]="_index.dat", nameMeaning[20]="_meaning.dat";
void menu(){
	printf("1. Create a new word\n");
	printf("2. Edit a word\n");
	printf("3. Look up meaning\n");
	printf("4. Exit\n");
	printf("Please choose number (1 - 4):\n");
}
void fileName (char *wordList, char *meaningList, char *word){
	char name1[30] = "D:\\", name2[30] = "D:\\"; 
	strncat(name1, &word[0], 1);
	strcat(name1,  nameWord);
	strncat(name2, &word[0], 1);
	strcat(name2, nameMeaning);
	strcpy(wordList, name1);
	strcpy(meaningList, name2);
}	
int findWord (char *word, char *fileName){
	char words[20];
	char c;
	int count=0;
	FILE *fp = fopen (fileName, "r"); 
	while (fscanf(fp, "%s", &words)!=EOF){
		fscanf(fp, "%s", &words);
//		fscanf(fp, "\n", &c);
		count++; 
		if(strcmp(word, words)==0)
			return count;
	}
	fclose(fp);
	return -1;
}
void Create(){
	char word[20], meaning[200], wordList[30], meaningList[30];
	printf("Enter a new word: ");
	scanf("%s", &word);
	fileName (wordList, meaningList, word);
	if(findWord(word, wordList)!=-1)
		printf("This word was existed.\n");
	else{
		fflush(stdin);
		printf("Meaning: ");
		gets(meaning);
		FILE *fw = fopen(wordList, "a");
		FILE *fm = fopen(meaningList, "a");
		fprintf(fw, "%s\n", word);
		fprintf(fm, "%s\n", meaning);
		printf("Create successfully.\n\n");
		fclose(fw);
		fclose(fm);
		
	}	
}

int findMeaning (char mean[][200], char *fileName){
	int i=0;
	char c;
	FILE *fp = fopen (fileName, "r"); 
	do{
		fscanf(fp, "%[^\n]", &mean[i]);
		fscanf(fp, "\n", &c);
		i++; 
	}
	while(fscanf(fp, "%[^\n]", &mean[i])!=EOF);
	fclose(fp);
	return i;
}
void Edit(){
	char word[20], mean[50][200], wordList[30], meaningList[30]; 
	printf("Enter a word to update: ");
	fflush(stdin);
	gets(word); 
	fileName(wordList, meaningList, word);
	int index1 = findWord (word, wordList); 
	int index2;
	if(index1==-1)
		printf("This word was not existed.\n");
	else{
		index2=findMeaning(mean, meaningList); 
		printf("Meaning: "); 
		scanf("%[^\n]", &mean[index1]); 
	}
	FILE *fp = fopen (meaningList, "w"); 
	for(int i=0; i<index2; i++)
		fprintf(fp, "%s\n", mean[i]);
	fclose(fp);
}			
void Look(){
	char word[20], mean[50][200], wordList[30], meaningList[30]; 
	printf("Enter a word to look up: ");
	fflush(stdin);
	gets(word); 
	fileName(wordList, meaningList, word);
	int index1 = findWord(word, wordList); 
	if(index1==-1)
		printf("This word was not existed.\n");
	else{
		findMeaning(mean, meaningList); 
		printf("Meaning: %s\n", mean[index1]);
	}
}
int main(){
	int choice;
	menu();
	do{
		scanf("%d",&choice);
		printf("User choose %d:\n",choice);
		switch(choice){
			case 1:
				Create();
				break;
			case 2:
				Edit();
				break;
			case 3:
				Look();
				break;
			default:
				exit(1);
		}
	}while(choice > 0 && choice < 4);	
return 0;
}

