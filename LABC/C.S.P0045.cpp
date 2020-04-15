#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char name[20][50];
	char temp[50];
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter %d names\n",n);
	for(int i =0;i<n;i++){
		fflush(stdin);
		scanf("%s",&name[i]);
	}
	printf("List input name:\n");
	for(int i =0;i<n;i++){
		printf("%d. %s\n",i+1,name[i]);
	}
	printf("List sort name:\n");
	for(int i = 0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(name[i],name[j]) > 0){
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		printf("%d. %s\n",i+1,name[i]);
	}
return 0;
}

