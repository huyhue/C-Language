#include <stdio.h>
#include <math.h>

void input(float arr[], int *n){
	printf("Please enter the number:\n");
	do{
		scanf("%f", &arr[*n]);
		if(arr[*n]==-999)	break;
		if(arr[*n]<0 || arr[*n]>100){
			printf("You just input integer number in the interval [0-100].\n");
			printf("Please enter again: ");
		}
		else{
			if(*n>99)	printf("You just input maximum 100 numbers.\n");
			(*n)++;
		}
	}
	while(arr[*n]!=-999);
	arr[*n]=arr[(*n)+1];//xoa phan tu -999
}
void interval(float *arr, int n){
	int a=0, b=4;
	printf("\nHere is a histogram of the adjusted data:\n");
	while(a<=100){
		if(a<100){
			printf("%-3d - %-3d| ", a, b);
			for(int i=0; i<n; i++)
				if(arr[i]>=a && arr[i]<=b)
					printf("*");
			printf("\n");
			a+=5;
			b+=5;
		}
		else{
			printf("%-9d| ", a);
			for(int i=0; i<n; i++)
				if(arr[i]==100)
					printf("*");
			printf("\n");
			break;
		}
	}
}
void minGrade(float *arr, int *n){
	int min = 0;
	for (int i=1; i<*n; i++)//tim kiem phan tu min
		if(arr[min]>arr[i])	min=i;	
	printf("\nThe data has been adjusted by removing the minimum %.2f\n", arr[min]);
	for (; min<*n; min++)//xoa phan tu min
		arr[min]=arr[min+1];	
	(*n)--;			
}
void maxGrade(float *arr, int *n){
	int max = 0;
	for (int i=1; i<*n; i++)
		if(arr[max]<arr[i])	max=i;
	printf("The data has been adjusted by removing the maximum %.2f\n", arr[max]);
	for (; max<*n; max++)
		arr[max]=arr[max+1];
	(*n)--;				
}
float meanGrade(float *arr, int n){
	float mean=0;
	for(int i=0; i<n; i++)
		mean+=arr[i];
	mean/=n;
	return mean;
}
void deviation(float *arr, int n){
	float mean = meanGrade(arr, n);
	float deviation = 0;
	for(int i=0; i<n; i++)
		deviation+=pow((arr[i]- mean), 2);
	deviation = sqrt(deviation/n);
	printf("The adjusted standard deviation is %.2f\n", deviation);
}	
int main(){
	float arr[100]; 
	int n=0;
	input(arr, &n);
	minGrade(arr, &n);
	maxGrade(arr, &n);
	printf("The adjusted mean is %.2f\n", meanGrade(arr, n));
	deviation(arr, n);
	interval(arr, n);
	return 0;
}

