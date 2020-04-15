#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
int pos = 0;
typedef struct Student
{
    char code[10];
    char Name[30];
    char Date[15];
    float Point;

} Student;
Student student[20];
void LoadData(){
    FILE *f = fopen("D://student.txt", "r");
    if (f == NULL){
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for(int i = 0; i < MAX; i++){
        fscanf(f, "%s\n", student[i].code);
        fscanf(f, "%[^\n]s\n", student[i].Name);
        fscanf(f, "%s\n", student[i].Date);
        fscanf(f, "%f\n", &student[i].Point);
        if (student[i].Point == 0 || student[i].Name == NULL){
            pos = i;
            break;
        }
    }
    printf("List student.txt found %d student\n", pos);
    fclose(f);
}
void WriteStudent(){
    FILE *f = fopen("D://student.txt", "w+");
    if (f == NULL){
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < pos; i++){
        fprintf(f, "%s\n", student[i].code);
        fprintf(f, "%s\n", student[i].Name);
        fprintf(f, "%s\n", student[i].Date);
        fprintf(f, "%.2f\n", student[i].Point);
    }
    fclose(f);
}
void EnterStudent(){
    char c;
    do{
        printf("Enter new student:\n");
        printf("Student code: ");
        fflush(stdin);
        gets(student[pos].code);
        printf("Enter student name: ");
        fflush(stdin);
        gets(student[pos].Name);
        printf("Enter date of birth: ");
        fflush(stdin);
        gets(student[pos].Date);
        printf("Learning point: ");
        scanf("%f", &student[pos].Point);
        printf("\n-------------------------------------------\nPress enter to continue, Esc to return the main menu.\n");
        pos++;
        c = getch();
    }while (c != 27);
}
int Trim(char s[], char st[]){
    char *key;
    char word[10][30];
    int count = 0;

    key = strtok(s, " \t");
    while (key != NULL){
        strcpy(word[count++], key);
        key = strtok(NULL, " \t");
    }
    for (int i = --count; i >= 0; i--){
        if (strcmp(word[i], st) == 0){
            return 1;
        }
    }
    return 0;
}
//int Trim(char s[], char st[]){
//	for(int i=0;i<pos;i++){
//		if(strcmp(s,st)==0){
//			return 1;
//		}
//	}
//	return 0;
//}
void Search(){
    char c;
    do{
        char s[10], st[30];
        int count = 0;
        printf("Please enter student name: ");
        fflush(stdin);
        gets(s);
        printf("\n----------------------------------\n");
        for (int i = 0; i <= pos; i++){
            strcpy(st, student[i].Name);
            if (Trim(st, s) == 1){
                count++;
                printf("Student code: %s\nStudent name: %s\nDate of Date: %s\nLearning point: %.2f\n", student[i].code, student[i].Name, student[i].Date, student[i].Point);
            }
        }
        if (count == 0){
            printf("No student found in student\n");
        }
        else{
            printf("Found %d studen name %s in list", count, s);
        }
        printf("\nPress enter to continue, Esc to return the main menu.\n");
        c = getch();
    } while (c != 27);
}
void Sort()
{
    Student tg;
    for (int i = 0; i < pos - 1; i++)
    {
        for (int j = i + 1; j < pos; j++)
        {
            if (strcmp(student[i].code, student[j].code) > 0)
            {

                tg = student[i];
                student[i] = student[j];
                student[j] = tg;
            }
        }
    }
}
void Display()
{
    Sort();
    printf("\nStudent list:");
    printf("\n---------------------------\n");
    for (int i = 0; i < pos; i++)
    {
        printf("\nStudent code: %s\nStudent name: %s\nDate of birth: %s\nLearning point: %.2f\n", student[i].code, student[i].Name, student[i].Date, student[i].Point);
        printf("\n----------------------------\n");
    }
}
int uChoice(){
    int choice;
    printf("\n=================MENU================\n");
    printf("\n 1- Enter Student List.");
    printf("\n 2- Look up student.");
    printf("\n 3- Display student student.");
    printf("\n 4- Exit.");
    printf("\nInput [1..4]:  ");
    scanf("%d", &choice);
    return choice;
}
int main(){
    int choice;
    LoadData();
    do{
        choice = uChoice();
        switch (choice){
        case 1:
            EnterStudent();
            break;
        case 2:
            Search();
            break;
        case 3:
            Display();
            WriteStudent();
            break;
        case 4:
            printf("\nGood bye");
            WriteStudent();
            exit(1);
        default:
            WriteStudent();
        }
    }while (choice >= 1 && choice <= 4);
    getch();
    return 0;
}
