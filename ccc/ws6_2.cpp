#include<stdio.h>
#define MAX 100

void NhapMang(int a[], int n){
    for(int i = 0;i < n; i++){
        printf("Nhap so thu %d: ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n){
    for(int i = 0;i < n; i++){
        printf("%4d", a[i]);
    }
}
void ThemPhanTu(int a[], int &n, int val, int pos){
    // Mang da day, khong the them.
    if(n >= MAX){
        return;
    }
    // Neu pos <= 0 => Them vao dau
    if(pos < 0){
        pos = 0;
    }
    // Neu pos >= n => Them vao cuoi
    else if(pos > n){
        pos = n;
    }
    // Dich chuyen mang de tao o trong truoc khi them.
    for(int i = n; i > pos; i--){
        a[i] = a[i-1];
    }
    // Chen val tai pos
    a[pos] = val;
    // Tang so luong phan tu sau khi chen.
    ++n;
}
int sort(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i ;j--)
		if(a[j]<a[j-1]){
			int t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
			
		}
	}
	
}
int  search(int a[], int x){
	int i;
	printf("nhap x:");
	scanf("%d",&x);
	for(i=0;i<10;i++){
		if(a[i]==x) 	return 1;
}
		return 0;
	}
	
input(int a[], int n){
	int i; 
	for(i=0;i<n;i++) {
		printf("%5d",a[i]);
	}
}
/*range(int a[], int n){
	int maxVal, minVal;
	printf("Enter minVal and maxVal:\n");
	scanf("%d %d",&minVal, &maxVal);
	printf("\nvalue in a range from %d to %d:",minVal,maxVal);
	for(int i=minVal;i<=maxVal;i++){
		printf("%4d",a[i]);
	}
	
}*/
range(int a[], int n){
	int maxVal, minVal, Val,i;
	printf("Enter minVal and maxVal:\n");
	scanf("%d %d",&minVal, &maxVal);
	printf("\nvalue in a range from %d to %d:  ",minVal,maxVal);
	 for (int i=1; i<=n; i++)
    {
        if ((a[i]<=maxVal)&&(a[i]>=minVal)) 
		sort(a,n);
		printf("%d ",a[i]);
    }
	/*for(int i=minVal;i<=maxVal;i++){
		printf("%4d",a[i]);*/

	}

int main(){
 int x,n=111; 
 int a[MAX];
 int val, pos;
 int choice;
 while(choice!=6){
 	printf("\n0.enter array:");
	printf("\n1.add a value:\n");
 	printf("2.search a value:\n");
 	printf("3.print out the array:\n");
 	printf("4.print out value in a range:\n");
 	printf("5.print out the array in ascending order:\n");
 	printf("enter a choice 0/1/2/3/4/5:   ");
 	fflush(stdin); 
	scanf("%d",&choice);
 	
 	switch(choice){
 		case 0:{	NhapMang(a, n);
    				
			break;
		 }
		 case 1:{   printf("\n=======THEM PHAN TU======\n");
				    printf("\nNhap so can them: ");
				    scanf("%d", &val);
				    printf("\nNhap vi tri muon chen: ");
				    scanf("%d", &pos);
				    ThemPhanTu(a, n, val, pos);
				    printf("\nMang sau khi them: ");
				    XuatMang(a, n);	
				break;
		 }
		case 2:{ 
			printf("\n Nhap x: ");
			scanf("%d",&x);
			search(a,x);
			break;
		 }
		case 3:{
			if(search(a,x)){
				printf("ton tai gia tri x");
			} else {
					printf("khong ton tai gia tri x");
			}
			break;
		}
		case 4:{
			range(a,n);
			break;
		}
		case 5:{   sort(a,n);
		printf("mang da sap xep");
		XuatMang(a, n);	
			break;
		}
		default:{ printf("you choice the strong!!!");
			break;
		}
	 }
 	
 }
return 0;
}

