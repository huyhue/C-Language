#include<stdio.h>
#define N 4
void xuat(int arr[N][N], int m, int n){
	puts("cac phantu cua mang: ");
	int i,j;
	for(i=0;i<m;i++){
		for(j=0; j<n; j++){
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
}
void nhap(int arr[N][N], int m, int n){
	puts("Nhap cac phan tu cua mang:");
	int i,j;
	for(i=0;i<m;i++){
		for(j=0; j<n; j++){
			scanf("%d",&arr[i][j]);
		}
	}
}
int max(int arr[N][N], int m, int n){
	int max=arr[0][0];
	for(int i=0;i<m;i++){
		for(int j=1; j<n; j++){
			if(arr[0][j]>max)  max=arr[0][j];
		}
		max++;
	}return max;
}
int main(){
int arr[3][4]={{1,2,3,4},
              {5,6,7,8},
             {9,8,7,2}};

int m= sizeof(arr)/sizeof(int);
int n= sizeof(arr[0])/sizeof(int);
m/=n; //so hang */
/*puts("nhap so hang, so cot:");
scanf("%d %d",&m,&n);*/
//nhap(arr,m,n);
max(arr,m,n);

return 0;
}


