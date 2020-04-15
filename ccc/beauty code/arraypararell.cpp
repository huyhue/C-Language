#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
char code[100][50],name[100][50];
double salary[100],allowance[100];
int n=0;

//KIEM TRA DINH DANG CODE----------------------------------------
int checkCode(char*s)
{
    int spaceCount=0;
    for (int i=0;i<strlen(s);i++){
        //KIEM TRA KY TU IN HOA---------------
        if ((s[i]>='A')&&(s[i]<='Z')) continue;
        //KIEM TRA KY TU THUONG---------------
        else if ((s[i]>='a')&&(s[i]<='z')) continue;
        //KIEM TRA CHU SO---------------------
        else if ((s[i]>='0')&&(s[i]<='9')) continue;
        //KIEM TRA DAU CACH-------------------
        else if (s[i]==' ') spaceCount++;
        //------------------------------------
        else return 0;
    }
    if (spaceCount==strlen(s)) return 0;
    return 1;
}
//KIEM TRA DINH DANG NAME----------------------------------------
int checkName(char*s)
{
    int spaceCount=0;
    for (int i=0;i<strlen(s);i++){
        //KIEM TRA KY TU IN HOA---------------
        if ((s[i]>='A')&&(s[i]<='Z')) continue;
        //KIEM TRA KY TU THUONG---------------
        else if ((s[i]>='a')&&(s[i]<='z')) continue;
        //KIEM TRA DAU CACH-------------------
        else if (s[i]==' ') spaceCount++;
        //------------------------------------
        else return 0;
    }
    if (spaceCount==strlen(s)) return 0;
    return 1;
}
//QUET THONG TIN-------------------------------------------------
int Search(char*s)
{ 
    //CHAY HET DANH SACH HOC SINH---------------
    for (int i=1;i<=n;i++)
    //NEU DA TON TAI TEN HOAC CODE THI TRA VE i
        if ((strcmp(name[i],s)==0)||(strcmp(code[i],s)==0)) return i;
    return 0;
}
//AUTO FIX CODE--------------------------------------------------
void corectCode(char*s)
{
    //Mang CODE dung de luu lai CODE khi da correct
    char*code=(char*)calloc(50,sizeof(char));
    int j=-1;
    for (int i=0;i<strlen(s);i++)
        //XOA TAT CA DAU CACH
        if (s[i]==' ') continue;
        else{
            j++;
            code[j]=toupper(s[i]);       
        }
    //TRA VE GIA TRI CHO MANG S
    strcpy(s,code);
    free(code);
}
//AUTO FIX TEN---------------------------------------------------
void corectName(char*s)
{
    //Mang NAME dung de luu lai ten khi da correct
    char*name=(char*)calloc(50,sizeof(char));
    int j=-1;
    for (int i=0;i<strlen(s);i++)
        //TRUONG HOP CO NHIEU DAU CACH
        if ((s[i]==' ')&&(s[i+1]==' ')) continue;
        //TRUONG HOP DAU CACH O DAU
        else if ((j==-1)&&(s[i]==' ')) continue;
        //TRUONG HOP DAU CACH O CUOI
        else if ((i==strlen(s)-1)&&(s[i]==' ')) continue;
        //NEU KHONG CO 3 TRUONG HOP TREN THI GHI VAO NAME
        else{
            j++;
            name[j]=s[i];
            if (name[j-1]==' ') name[j]=toupper(name[j]);
            else name[j]=tolower(name[j]);            
        }
    //CHU DAU TIEN GHI HOA
    name[0]=toupper(name[0]);
    //TRA VE GIA TRI CHO MANG S
    strcpy(s,name);
    free(name);
}        
//NHAP THONG TIN CUA EMPLOYEE------------------------------------
void Input()
{  
    char *s1=(char*)calloc(50,sizeof(char));
    char *s2=(char*)calloc(50,sizeof(char));
    int j=-1;
    //NHAP CODE va KIEM TRA CODE-------------
    printf("Type employee's code to add: \n");
    fflush(stdin); scanf("%[^\n]",s1); 
    corectCode(s1);
    if (checkCode(s1)==0){     
        printf("WRONG CODE FORMAT!\n");
        return;
    }
    //NHAP TEN va KIEM TRA TEN---------------
    printf("Type employee's name to add: \n");
    fflush(stdin); scanf("%[^\n]",s2);
    corectName(s2);
    if (checkName(s2)==0){
        printf("WRONG NAME FORMAT!\n");
        return;
    }
    //KIEM TRA TEN(CODE) CO HAY CHUA---------
    if ((Search(s1)!=0)||(Search(s2)!=0)){
        printf("Name or Code are Adready Exits!\n");
        return;
    } 
    //THEM VAO DANH SACH---------------------
    n++;
    strcpy(code[n],s1);
    strcpy(name[n],s2);
    printf("Type salary of employee: "); scanf("%lf",&salary[n]);
    printf("Type allowance of employee: "); scanf("%lf",&allowance[n]);
    printf("Information sucessfully added!\n");
    free(s1);
    free(s2);
}
//TIM KIEM THONG TIN CUA EMPLOYEES-------------------------------
void Find()
{
    char*s=(char*)calloc(50,sizeof(char));
    printf("Type employee name to find: ");
    fflush(stdin); scanf("%[^\n]",s);  
    corectName(s);
    int possition=Search(s);
    if (possition!=0){
        printf("-----------------------------------------------\n");
        printf("Employee \"%s\" is at possition: %d\n",name[possition],possition);
        printf("Code of the employee: %s\n", code[possition]);
        printf("Salary: %.0lf\n",salary[possition]);
        printf("Allowance: %.0lf\n",allowance[possition]);
        printf("-----------------------------------------------\n");
    }
    else printf("Name not found!\n");
    free(s);
}
//XOA EMPLOYEES--------------------------------------------------
void Remove()
{
    char*s=(char*)calloc(50,sizeof(char));
    printf("Type CODE of employees to remove: ");
    fflush(stdin); scanf("%[^\n]",s);
    corectCode(s);
    //TIM VI TRI XOA
    int possition=Search(s);
    if (possition==0){
        printf("Code \"%s\" not found!\n",s);
        return;
    }
    //UPDATE LAI DANH SACH
    strcpy(code[possition],code[n]);
    strcpy(name[possition],name[n]);
    salary[possition]=salary[n];
    allowance[possition]=allowance[n];
    n--;
    printf("Employee remove!\n");
    free(s);
}
//SWAP DOUBLE----------------------------------------------------
void swapInt(double*a,double*b)
{
    double t=*a;
    *a=*b;
    *b=t;
}
//SWAP NAME------------------------------------------------------
void swapString(char*a,char*b)
{
    char *c=(char*)calloc(50,sizeof(char));
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
    free(c);
}
void Sort()
{
    double soft[100];
    for (int i=1;i<=n;i++) soft[i]=salary[i]+allowance[i];
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (soft[i]>soft[j]){
                swapInt(&soft[i],&soft[j]);
                swapInt(&salary[i],&salary[j]);
                swapInt(&allowance[i],&allowance[j]);
                swapString(code[i],code[j]);
                swapString(name[i],name[j]);
            }
}
//XUAT DANH SACH RA MAN HINH-------------------------------------
void Output()
{
    Sort();
    //GHI KET QUA RA MAN HINH-----------
    for (int i=1;i<=n;i++){
        printf("----------CODE: %s----------\n",code[i]);
        printf("NAME: %s\n",name[i]);
        printf("SALARY: %.0lf\n",salary[i]);
        printf("ALLOWANCE: %.0lf\n",allowance[i]);
    }
}
//---------------------------------------------------------------
int getKey()
{
    char*key=(char*)calloc(50,sizeof(char));
    system("cls");
    printf("1- Adding a new employee\n");
    printf("2- Find data about employees unsing a name inputted\n");
    printf("3- Remove an employee based on a code inputted\n");
    printf("4- Print the list in ascending order based on salary + allowance\n");
    printf("5- Quit\n");
    printf("YOUR CHOICE (1/2/3/4/5) ?\n");
    fflush(stdin); scanf("%[^\n]",key);
    if (strlen(key)!=1) return 0;
    if ((key[0]<'0')||(key[0]>'9')) return 0;
    return (int)(key[0])-48;
    free(key);
}
//---------------------------------------------------------------
int main()
{
    int key=0;
    while (key!=5)
    {
        key=getKey(); 
        switch(key)
        {
            case 1:
                Input();
                break;
            case 2:
                Find();
                break;
            case 3:
                Remove();
                break;
            case 4:
                Output();
                break;
            case 5: 
                printf("Program excuted !\n");
                break;
            default:
                printf("Choice again\n");
                break;
        }
        system("pause");
    }
    return 0;
}


