/*#include<stdio.h>
int power(int m, int n);
int main(){
	
	int t;
	printf("i\t,2^i\t,-3^i\n");
	for(int i=0; i<10;++i)
	printf("%d\t %d\t %d\n ",i , power(2,i), power(-3,i));
	getchar();
	return 0;
}
int power(int coso, int somu)
{ 
	int i, ketqua;
	ketqua=1;
	for(i=1;i<=somu;++i)
	ketqua=ketqua*coso;
	return ketqua;
}*/
/*#include<stdio.h>
int power(int coso, int somu);

int main(){
	printf("%d \n",power(2,3));
	
	return 0;
}
int power(int coso, int somu)
{ 
	int i, ketqua;
	ketqua=1;
	for(i=1;i<=somu;++i)
	ketqua=ketqua*coso;
	return ketqua;
}*/
#include<stdio.h>
int max(int a, int b)
{ 
	if(a>b)
	return a; 
	return b;
}
int main()
{	printf("max la %d", max(200,600));
	return 0;
	}


