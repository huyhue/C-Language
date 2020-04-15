#include <stdio.h>
 
 int main() {  
    FILE *fptr;
    int id;
    char name[30];
    int salary;
     
    fptr = fopen("emp.txt", "w+");
     
    if (fptr == NULL) {
        printf("File khong ton tai.\n");
       
    }
     
    printf("Nhap id: ");
    scanf("%d", &id);
    fprintf(fptr, "Id = %d\n", id);
    printf("Nhap name: ");
    scanf("%s", name);
    fprintf(fptr, "Name = %s\n", name);
    printf("Nhap salary: ");
    scanf("%f", &salary);
    fprintf(fptr, "Salary = %.2f\n", salary);
     
    fclose(fptr);
}

