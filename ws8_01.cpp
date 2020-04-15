#include<stdio.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0
//check whether the file existed or not
int exist(char* filename){
	int existed= FALSE;
	FILE* f= fopen(filename,"r");//try oping it for reading
	if(f!=NULL){
		existed=TRUE;
		fclose(f);
	}
	return existed;
}
//write a file from character inputted until ctrl+z is pressed
int writeFile(char* filename){
	char c;//inputted character
	int CTRL_Z=-1;
	if(exist(filename)==TRUE){
		printf("The file %s existed.Override it Y/N? :",filename);
		if(toupper(getchar())=='N') return FALSE;
	}
		FILE* f= fopen(filename,"w");//open the file for writing
		fflush(stdin);//clear input buffer
		do{
			c=getchar();//get a character
			if(c!=CTRL_Z) fputc(c,f);//write it to file
		}
		while(c!=CTRL_Z);
		fclose(f);
		return TRUE;
}
int main(int ardCount, char* args[]){
	if(ardCount!=2)  printf("Syntax: copy_con filename\n");
	else if (writeFile(args[1])==TRUE)
             printf("Writing the file %s: done\n",args[1]);
    	else   printf("Can not write the file %s: done\n",args[1]);
return 0;
}

