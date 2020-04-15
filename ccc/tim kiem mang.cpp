#include<stdio.h>
#define LENGTH 10
int *nhap(){
	static int arr[LENGTH];	
	int i; 
	for(i=0;i<LENGTH; i++){
		scanf("%d",&arr[i]);
	}
	return arr;
}
void hienThi(const int arr[])
{
	int i;
	for(i=0;i<LENGTH;i++){
		printf("%5d",arr[i]);
	}
	printf("\n");
}
int linearSearch(int arr[],int x){
	for(int i=0;i<LENGTH; i++){
		if(arr[i]==x)
		return 1;
	} return 0;
}
int timX(int *arr, int x){
	int i, count=0;
	for(i=0;i<LENGTH;i++){
		if(arr[i]==x) ++count;
	}
	return count;
}
int main(){
	int *arr;
	arr=nhap();
	hienThi(arr);
	
	int x;
	printf("\n Nhap x: ");
	scanf("%d",&x);
	printf("so lan xuat hien cua x trong mang %d lan",timX(arr,x));
/*if(linearSearch(arr,x)){
	printf("\n ton tai x trong mang: ");
}
else{
	printf("\n khong ton tai x trong mang: ");
}*/
return 0;
}

