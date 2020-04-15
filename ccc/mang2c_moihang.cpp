#include<stdio.h>
#define N 100
void tong(int arr[N][N], int m, int n){
	int i,j;
	int sum=0;
	int max=arr[0][0];
	for(i=0;i<m;i++){
		for(j=0; j<n; j++){
		if(arr[i][j]>max)  max=arr[i][j];
		} sum+=max;
		
	}printf("\n tong cua moi hang la %d",sum);
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
int main(){
int arr[N][N];
int m,n;
puts("nhap so hang, so cot:");
scanf("%d %d",&m,&n);
nhap(arr,m,n);
xuat(arr, m,n);
tong(arr,m,n);

return 0;
}

