#include<stdio.h>
int main(){
	char luaChon;
	printf("Cau hoi: Con cho di chuyen bang may chan?\n");
	printf("A. 1 \nB. 2 \nC. 3 \nD. 4");
	printf("\nNhap vao dap an ban chon(a,b,c,d): ");
	luaChon= getchar(); //nhap vao mot ki tu
switch(luaChon){
	case 'a':
	case 'A':
	case 'b':
	case 'B':
	case 'c':
	case 'C':{printf("\n Rat tiec ban da chon sai");
		break;
	}
	case 'd':
	case 'D':{printf("\a\nChinh xac! xin chuc mung!");
		break;
	}
	default:
		printf("\nDap an ban chon khong phu hop");
}
	return 0;
}
