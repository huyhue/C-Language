#include<stdio.h>
void input(int *a, int n)
{
	int i;
	for(i=0;i<n; i++) scanf("%5d", &a[i]);
}
void print(int *a, int n)
{
	int i;
	for(i=0;i<n; i++) printf("%5d", a[i]);
}
int  linearSearch( int x, int a[], int n)
{  int i;
   for ( i=0;  i<n;  i++)
       if ( x == a[i] ) return i;
   return -1;
}
int  binarySearch ( int x, int a[], int n)
{  int i=0, j= n-1, c ;
   while (i<=j)
     {   c= (i+j)/2;
         if ( x== a[c] ) return c ;
         if (x < a[c] ) j = c-1;
         else i = c +1;
     }
    return -1;
}
void selectionSort( int *a, int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++)
		if(a[j]<a[min]) min=j;
		if(min > i){
			int t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
		
	}
}
int main(){
int a[10]/*={ 0,3,5,99,3,13,25,36,6,97}*/;
input(a,10);

 //linearSearch(a,10);
 print(a,10);

return 0;
}

