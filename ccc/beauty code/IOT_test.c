#include<stdio.h>
#include<stdlib.h>

// Điều chỉnh độ lớn mảng ở đây
#define MAX 13

int x[MAX],i;
void Input(), Output(), LinearSearch(), BinarySearch(), BubleSort();

int main()  {
    int choice;
    do {
        system("cls");  // Xóa màn hình
        printf("******* MENU *******\n");
        printf("1: Input\n");
        printf("2: Output\n");
        printf("3: Linear Search\n");
        printf("4: Binary Search\n");   
        printf("5: Quit\n");
        printf("********************\n");
        printf("What do you want? \n");
        scanf("%d",&choice);
        printf("\n");

        switch (choice) {
            case 1: Input();  break;
            case 2: Output();  break;
            case 3: LinearSearch();  break;
            case 4: Output();   // In ra mảng gốc
                    BubleSort();
                    Output();   // In ra mảng đã sắp xếp
                    BinarySearch(); // Tìm kiếm dựa trên mảng đã sắp xếp
                    break;
            // Lưu ý: đối với switch, các lệnh sẽ thực hiện liên tục nhau nên không cần có { } bọc bên ngoài
            // Case trong switch chỉ ngừng khi gặp lệnh break
            case 5: break;
            default: printf("Loi! Yeu cau nhap lai!!\n\n");
        }
        system("pause");        
    }
    while (choice!=5);
}


/* ---- nhập vào giá trị ---- */

void Input()    {
    printf("Nhap vao so luong phan tu: ");
    scanf("%d",&i);
    for (int j=0; j<i; j+=1)    {
        printf("Nhap vao phan tu x[%d]: ",j);
        scanf("%d",&x[j]);
    }
}

/* ---- Cách nhập tuần tự/từng lượt 1 ---- */

// void Input()  {
//     printf("Press input: ");
//     scanf("%d",&x[i]);
//     i+=1;
// }


// In ra giá trị của các phần tử mảng
void Output()  {
    for (int j=0; j<i; j+=1)  
        printf("%-4d",x[j]);
    printf("\n\n");
}


/* ---- Tìm kiếm tuần tự ---- */

void LinearSearch()  {
    Output();
    int n, j=0;
    printf("Press number: ");   scanf("%d",&n);
    for ( j ; j<i && x[j]!=n ; j+=1);
    printf("Value: %d - Stt: %d - Address: %d\n", x[j],j,&x[j]);
}


/* ---- Tìm kiếm nhị phân ---- */

void BinarySearch()  {
    int n;
    printf("Nhap so muon tim: ");
    scanf("%d",&n);
    int min=0, max=i, j;
    while (min<=max)    {
        j=(min+max)/2;
        if (x[j]==n)   printf("Value: %d - Stt: %d - Address: %d\n", x[j],j,&x[j]);
        if (x[j]>n)
            max=j-1;
        else min = j+1;
    }
}


/* ---- Sắp xếp nổi bọt ---- */

void BubleSort()   {
    int stt=0;
    do {
        stt=0;
        for (int j=0; j<i; j+=1)    {
            if (x[j]>x[j+1])    {
                int swap=x[j+1];
                x[j+1]=x[j];
                x[j]=swap;
                stt=1;
            }
        }
    }
    while (stt!=0);
    // Biến stt có tác dụng kiểm tra các phần tử đã được sắp xếp hoàn toàn hay chưa
    // Nếu còn bất cứ phần tử nào bị lệch, stt sẽ nhận giá trị 1 -> vòng lặp tiếp tục kiểm tra và sắp xếp
}
