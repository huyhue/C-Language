#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int c,d;
int first[MAX][MAX], second[MAX][MAX];
void menu(){
	printf("1. Nhap vào 2 ma tran m x n\n");
	printf("2. Nhan 2 ma tran\n");
	printf("3. Cong 2 ma tran\n");
	printf("4. Ma tran nghich dao\n");
	printf("5. Tích chap (convolution) 2 ma tran (Optional)\n");
	printf("6. Luu noi dung ket qua ra file\n");
}
FILE *fp = fopen("D://matrix.txt","w+");
void Luu(){	
	if(fp = NULL){
		printf("file khong ton tai...\n");
		exit(1);
	}else{
		printf(" da thuc hien ghi file...\n");
		fclose(fp);
	}
}
void Nhap(){
	printf("Cho dong = 3 va cot = 3 cua ma tran ");
	
	printf("Nhap ma tran 1: ");
	for(c=0;c<3;c++){
		for(d=0;d<3;d++){
			scanf("%d",&first[c][d]);
		}
	}
	
	printf("Nhap ma tran 2: ");
	for(c=0;c<3;c++){
		for(d=0;d<3;d++){
			scanf("%d",&second[c][d]);
		}
	}
		for(c=0;c<3;c++){
			for(d=0;d<3;d++){
				fprintf(fp,"%d\t",first[c][d]);
			}
			fprintf(fp,"\n");
		}
		for(c=0;c<3;c++){
			for(d=0;d<3;d++){
				fprintf(fp,"%d\t",second[c][d]);
			}
			fprintf(fp,"\n");
		}
}
void Tong(){
	printf("Tong cua hai ma tran 1 va 2 la: ");
	int sum[MAX][MAX];
	
	for(c=0;c<3;c++){
		for(d=0;d<3;d++){
			sum[c][d] = first[c][d] + second[c][d];
			printf("%d\t",sum[c][d]);
			fprintf(fp,"%d\t",sum[c][d]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
}
void Nhan(){
	printf("Nhan cua hai ma tran 1 va 2 la: ");
	int mul[MAX][MAX], sum = 0;
	
	for(c=0;c<3;c++){
		for(d=0;d<3;d++){
			for(int k=0;k<3;k++){
				sum += first[c][k] * second[k][d];
			}
			mul[c][d] = sum;
			sum = 0;
		}
	}
	printf("Ket qua la: ");
	for (c = 0; c < 3; c++) {
        for (d = 0; d < 3; d++){
           printf("%d\t", mul[c][d]);
           fprintf(fp,"%d\t",mul[c][d]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
}
void NghichDao(){
	float determinant = 0;
	for(c = 0; c < 3; c++){
		determinant = determinant + (first[0][c] * (first[1][(c+1)%3] * first[2][(c+2)%3] - first[1][(c+2)%3] * first[2][(c+1)%3]));
	}
	
	printf("Ma tran 1 nghich dao la: \n");
	for(c = 0; c < 3; c++){
		for(d = 0; d < 3; d++){
			printf("%.2f\t",((first[(d+1)%3][(c+1)%3] * first[(d+2)%3][(c+2)%3]) - (first[(d+1)%3][(c+2)%3] * first[(d+2)%3][(c+1)%3]))/ determinant);
			fprintf(fp,"%.2f\t",((first[(d+1)%3][(c+1)%3] * first[(d+2)%3][(c+2)%3]) - (first[(d+1)%3][(c+2)%3] * first[(d+2)%3][(c+1)%3]))/ determinant);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
}
int main(){
	int choice;
	do{
		menu();
		printf("Chon chuc nang thuc hien: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				Nhap();
				break;
			case 2:
				Tong();
				break;
			case 3:
				Nhan();
				break;
			case 4:
				NghichDao();
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				exit(1);
				break;
			
		}

	}while(choice>0&&choice<7);
return 0;
}

