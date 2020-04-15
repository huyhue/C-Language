#include<stdio.h>
#include<math.h>
#include <conio.h>
bool check(double a){
	double x = sqrt(a);
	return (x - floor(x)==0);
}
int main(){
	double n;
	char key;
	
	while(true){
		printf("Check Square Number Program\n");
			printf("Enter a position integer n = ");
			scanf("%lf",&n);
		if(n < 0){
			printf("Please enter a positive integer!\n");
		}else{
			if(check(n) == true){
				printf("%.1lf is a square number %.1lf = %.1lf x %.1lf\n",n,n,sqrt(n),sqrt(n));
			}else{
				printf("%.1lf is not a square number\n",n);
			}
		}
		printf("Press any key to continue.\n");
        key = getch();
		if(key == 27){
			break;
		}
		printf("\n");
	}
return 0;
}

