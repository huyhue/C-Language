#include<stdio.h>
#include<string.h>
int search(char *name, char names[][10], int stt){
	for(int i=0;i<stt;i++){
		if(strcmp(name,names[i])==0){
			return i;
		}
		return -1;
	}
}
void checkout(FILE *g,FILE *f,char names[][10],int occupants[],int stt){
	char name[10];
	fscanf(f,"[^\n]\n",name);
	int pos = search(name, names,stt);
	if(pos==-1){
		fprintf(g,"\nSorry, there is no occupant named %s\n",name);
	}else{
		fprintf(g,"\n%s was checked out of room %d\n",name,pos);
		strcpy(names[pos],"0");
	}
}
void findByName(FILE *g,FILE *f,char names[][10],int occupants[],int stt){
	char name[10];
	fscanf(f,"[^\n]\n",name);
	int pos = search(name, names,stt);
	if(pos ==-1)
		fprintf(g, "\nSorry, there is no occupant named %s\n", name);
	else
		fprintf(g, "\n%s is currently staying in room %d\n", name, pos);
}
void checkin(FILE *g,FILE *f,char names[][10],int occupants[], int *stt){
	fscanf(f,"%s",names[*stt]);
	char temp;
	fscanf(f, "%c", &temp);
	fscanf(f, "%d\n", &occupants[*stt]);
	
	int pos = search("0",names, *stt);
	if(pos==-1){
		fscanf(g,"\n%s was checked into room %d\n",names[*stt],*stt);
		(*stt)++;
	}else{
		strcpy(names[pos],names[*stt]);
		occupants[pos]=occupants[*stt];
		fprintf(g, "\n%s was checked into room %d\n", names[pos], pos);
	}
}
void print(FILE *g, char names[][10], int *occupants, int stt){
	fprintf(g, "\n%-10s%-15s%-20s\n", "Name", "Room Number", "Number of Occupant");
	for (int i=0; i<stt; i++)
		fprintf(g, "%-10s%-15d%-20d\n", names[i], i, occupants[i]);
}
int main(){
	FILE *f =fopen("D:\\hotellog.txt","r");
	FILE *g =fopen("D:\\summary.txt","w");
	
	int a;
	int stt=0;
	char names[10][10];
	int occupants[10];
	
	fscanf(f,"%d",&a);
	for(int i=0;i<a;i++){
		char log[20];
		fscanf(f,"%[^ ]%*c",log);
		if(strcmp(log,"CHECKIN")==0){
			checkin(g, f, names, occupants, &stt);
		}else if((log,"CHECKOUT")==0){
			checkout(g,f,names, occupants, stt);
		}else if((log,"SEARCH")==0){
			findByName(g,f,names,occupants,stt);
		}else if((log, "PRINTOCCUPANCY\n")==0){
			print(g,names,occupants,stt);
		}
	}
	fclose(g);
	char check[500];
	g=fopen("D:\\summary.txt","r");
	fread(&check,sizeof(char),500,g);
	printf("%s",check);
	fclose(g);
	fclose(f);
return 0;
}

