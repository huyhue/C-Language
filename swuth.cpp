#include<stdio.h>
int Choice1(int n)
{
	int S1=0;
	for(int i=0;i<=n;i++)
	S1+=i*(i+1);
	return S1;
}

int Choice2(int n)
{
	
	int S2=1;
	for (int i=1;i<=n;i++) S2*=i;
	return S2;
}

int Choice3(int n)
{
	int S3=0;
	for (int i=2;i<=n;i+=2) S3+=(int)(1/(i*(i+2)));
	return S3;

}
int main(){
int c,n;
do
{
	printf("nhap vao choice:");
	scanf("%d",&c);
	printf("input number:"); scanf("%d",&n);
switch(c)
{
	case 1:
		printf("result: %d\n",Choice1(n)); break;
	case 2:
		printf("result: %d\n",Choice2(n)); break;
	case 3:
		printf("result: %f\n",Choice3(n)); break;
}
}
while (c!=4);


return 0;
}

