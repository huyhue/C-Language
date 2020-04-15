#include <stdio.h>
#define filename "D:\\hotellog.txt"
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int search(char *name,char names[][10], int stt){
	for(int i=0; i<stt; i++)
		if(strcmp(name, names[i])==0)
			return i;
	return -1;
}
void checkin(FILE *g, FILE *f, char names[][10], int occupants[], int *stt){
	fscanf(f, "%s", names[*stt]);
	char temp;
	fscanf(f, "%c", &temp);
	fscanf(f, "%d\n", &occupants[*stt]);
	int pos = search("0", names, *stt);
	if(pos == -1){
		fprintf(g,"\n%s was checked into room %d\n", names[*stt], *stt);
		(*stt)++;
	}
//	else{
//		strcpy(names[pos],names[*stt]);
//		occupants[pos]=occupants[*stt];
//		fprintf(g, "\n%s was checked into room %d\n", names[pos], pos);
//	}
}

void checkout(FILE *g, FILE *f, char names[][10], int *occupants, int stt){
	char name[10];

	fscanf(f, "%[^\n]\n", name);
	int pos = search(name, names, stt);
	if(pos==-1)
		fprintf(g, "\nSorry, there is no occupant named %s\n", name);
	else{
		fprintf(g, "\n%s was checked out of room %d\n", name, pos);
		strcpy(names[pos], "0");
	}	
}
void findByName (FILE *g, FILE *f, char names[][10], int *occupants, int stt){
	char name[10];
	fscanf(f, "%s\n", name);
	int pos = search(name, names, stt);
	if(pos ==-1)
		fprintf(g, "\nSorry, there is no occupant named %s\n", name);
	else
		fprintf(g, "\n%s is currently staying in room %d\n", name, pos);
}
void print(FILE *g, char names[][10], int *occupants, int stt){
	fprintf(g, "\n%-10s%-15s%-20s\n", "Name", "Room Number", "Number of Occupant");
	for (int i=0; i<stt; i++)
		fprintf(g, "%-10s%-15d%-20d\n", names[i], i, occupants[i]);
}
int main(){
	int a, stt=0;
	char names[10][10];
	int occupants[10];
	char k;
	FILE* f = fopen ("D:\\hotellog.txt", "r");
	FILE* g = fopen ("D:\\summary.txt", "w");
	fscanf(f, "%d\n", &a);
	for(int i=0; i<a; i++){
		char *log = (char*)malloc(10*sizeof(char));
		fscanf(f, "%[^ ]%*c", log);
		if(strcmp(log, "CHECKIN")==0)	
			checkin(g, f, names, occupants, &stt);
		else if(strcmp(log, "CHECKOUT")==0)	
			checkout(g,f,names, occupants, stt);
		else if(strcmp(log, "SEARCH")==0) 
			findByName(g,f, names, occupants, stt);
		else if(strcmp(log, "PRINTOCCUPANCY\n")==0)
			print(g, names, occupants, stt);
	}
	char check[500];
	fclose(g);
	g = fopen("D:\\summary.txt", "r");
	fread(&check, sizeof(char), 500, g);
	printf("%s", check);
	fclose(f);
	fclose(g);

}	
