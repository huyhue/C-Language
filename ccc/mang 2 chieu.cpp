#include<stdio.h>
#define N 100
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
int main(){
int arr[N][N];
int m,n;
/*{1,2,3,4},
{5,6,7,8},
{9,8,7,2}
};*/

/*int m= sizeof(arr)/sizeof(int);
int n= sizeof(arr[0])/sizeof(int);
m/=n; //so hang */
puts("nhap so hang, so cot:");
scanf("%d %d",&m,&n);
nhap(arr,m,n);
xuat(arr, m,n);

return 0;
}

