#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
char name[50][31];
int n = 0;
int Search(char *s);
void Input();
void Output();
void Find();
void Remove();
void swapString(char *a, char *b);
void sortNameStudent();
int getKey();
int main(){
    int key;
    while (key != 5){
        key = getKey();
        switch (key){
        case 1:
            Input();
            break;
        case 2:
            Remove();
            break;
        case 3:
            Find();
            break;
        case 4:
            sortNameStudent();
            Output();
            break;
        case 5:
            printf("Program excuted !\n");
            break;
        default:
            printf("Choice again\n");
            break;
        }
        system("pause");
    }
    return 0;
}
int Search(char *s){
    for (int i = 1; i <= n; i++)
        if ((strcmp(name[i], s) == 0))
            return i;
    return -1;
}

void Input(){
    char s[50];
    printf("Enter new student name: \n");
    fflush(stdin);
    gets(s);
    n++;
    strcpy(name[n], s);
    printf("Student has been added to list successfully! \n");
}
void Find(){
    char s[50];
    printf("Enter student name to search : ");
    fflush(stdin);
    gets(s);
    int possition = Search(s);
    if (possition > 0){
        printf("The possition of student name in list is %d \n", possition);
    }
    else
        printf("Name not found!\n");
}
void Remove(){
    char s[50];
    printf("Enter student name to remove: \n");
    fflush(stdin);
    scanf("%[^\n]", s);
    int possition = Search(s);
    if (possition == 0){
        printf(" %s not found!\n", s);
        return;
    }
    else
        strcpy(name[possition], name[n]);
    n--;
    printf("Student removed!\n");
}

void swapString(char *a, char *b){
   char c[50];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}
void sortNameStudent(){
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (strcmp(name[i], name[j]) > 0)
                swapString(name[i], name[j]);
}
void Output(){
    for (int i = 1; i <= n; i++){
        printf("%d. %s\n", i, name[i]);
    }
}
int getKey(){	
	int key;
    system("cls");
	printf("\n************************************\n");
	printf("1 - Add a student.\n");
	printf("2 - Remove a student.\n");
	printf("3 - Search a student.\n");
	printf("4 - Print list student in an ascending folder.\n");
	printf("5 - Exit\n");
	printf("************************************\n");
    fflush(stdin);
    scanf("%d", &key);
    return key;
}
