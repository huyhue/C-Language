#include <stdio.h>
#include <stdlib.h>
int main() {
	char name[50],code[50],date[50];
	int point;
	int marks,i=1,n;
	FILE *fptr;
	fptr=(fopen("D:\\Student.txt","a"));
	if(fptr == NULL) {
		printf("Error!");
		exit(1);
	}
	
		printf("For student : \nEnter code: ");
		scanf("%s",code);
		printf("Enter name: ");
		scanf("%s",name);
		printf("Enter date: ");
		scanf("%s",date);
		printf("Enter point: ");
		scanf("%d",&point);
		fprintf (fptr, "\n\n%d \n%s \n%s \n%s \n%d\n",i,code,name,date,point);
//		fprintf(fptr,"\n \nCode: %s \nName: %s \nDate: %s \nPoint: %d ",code,name,date,point);
//	fscanf(fptr,"%d",&i);
//	printf("so thu tu %d: ",i);
	fclose(fptr);
//	char c[1000];
//		fptr=(fopen("D:\\Student.txt","r"));
//		while((c=fgetc(fptr))!=EOF){
//			putchar(c);
//		}
	
//  fscanf(fptr, "%[^\n]", &name);
//    printf("Data from the file: %s\n", name);  
//    fscanf(fptr, "%[^\n]", &code);
//    printf("Data from the code: %s\n", code);  
//    fscanf(fptr, "%s", &name);
//    printf("Data from the date: %s\n", date);  
//    fscanf(fptr, "%d", &point);
//    printf("Data from the file: %d\n", point);
//    fclose(fptr);
	return 0;
}
