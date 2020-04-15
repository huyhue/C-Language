#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int day, mon,year;
int doy;
int days_in_feb = 28;
int dayOfYear(){
	doy = day;
    
    // check for leap year
    if( (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0) ){
        days_in_feb = 29;
    }
    switch(mon){
        case 2:
            doy += 31;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 31+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;            
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;            
            break;                                    
    }
    return doy;
}
int findm(int months, int yearss){
           int findmonth, leapyr;
           if ((yearss % 100 == 0) && (yearss % 400 != 0))
           leapyr = 0;
           else if (yearss % 4 == 0)
           leapyr = 1;
           else
           leapyr = 0;
           findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months))+ (5 * months + months / 9) / 2;
           findmonth = findmonth % 7;
           return findmonth;
}
void dayOfWeek(){
	int dayWeek, yr, yd;
    yr = year % 100;
    yd = year / 100;
    dayWeek = 1.25 * yr + findm(mon, year) + day - 2 * (yd % 4);
   	dayWeek = dayWeek % 7;
    switch (dayWeek){
     	   case 0:  printf("Day of week: Saturday\n");
            			break;
           case 1:  printf("Day of week: Sunday\n");
                        break;
           case 2:  printf("Day of week: Monday\n");
                        break;
           case 3:  printf("Day of week: Tuesday\n");
                        break;
           case 4:  printf("Day of week: Wednesday\n");
                        break;
           case 5:  printf("Day of week: Thursday\n");
                        break;
           case 6:  printf("Day of week: Friday\n");
                        break;
	}
}
int main(){
	int key;
	do{
		printf("Please enter a date (dd/mm/yyyy): ");
		scanf("%d/%d/%d",&day,&mon,&year);
		printf("Day of year: %d\n",dayOfYear());
		dayOfWeek();
		printf("Week of year: %d\n",dayOfYear()/7+1);
		printf("Press enter to continue, Esc to exit.\n");
		key = getch();
	}while(key != 27);
	
return 0;
}

