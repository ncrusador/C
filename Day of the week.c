#include <stdio.h>
#include <stdlib.h>

int main()
{
	// INTRO //
	short count=0;
	printf("------------------------------------\nDAY   OF   THE   WEEK   CALCULATION\n------------------------------------\n");
	printf("Give date in <Day Month Year> format\n          (0 0 0 to exit)          \n------------------------------------\n");
	
	// REPEAT CALCULATION //
	while(count<100) {
	short day=0, month=0, year=0, year_code=0, sum=0, code=0, year2=0, year3=0, disekto=0, error=0;
	count++;
	// SCAN //
	printf("(%hd) >> ", count);
	scanf("%hd %hd %hd", &day, &month, &year);
	
	// ERROR //
	if(!day && !month && !year) break;
	if(year<0) error=1;
	
	// LEAP YEAR //
	if(year%4==0)
	{
		disekto=1;
		if(year%100==0)
		{
			disekto=0;
			if(year%400==0) disekto=1;
		}
	}
	
	// YEAR //
	year2 = year%100;
	year3 = year/100;
	
	if(year3%4==0) code=2;
	else if(year3%4==1) code=0;
	else if(year3%4==2) code=5;
	else code=3; // year%4==3
	year_code = code + (year2/12) + (year2%12) + ((year2%12)/4);
	
	// MONTH & DAY //
	if (month==1) // JAN = 3/1 or 4*/1
	{
		if((day>31||(day<1))) error=1;	
		if(day>=3) sum = year_code + (day-3);
		else sum = year_code + day + 7 - 3;
		if(disekto) sum--;
	}
	else if (month==2) // FEB 28/2 or 29*/2
	{
		sum = year_code + day;
		if(disekto) sum--;
		if((day>28||(day<1)))
		{
			if((day!=29)||(disekto==0)) error=1;
		}
	}
	else if (month==3) // MAR = 14/3
	{
		if((day>31||(day<1))) error=1;
		sum = year_code + day;
	}
	else if (month==4) // APR = 4/4
	{
		if((day>30||(day<1))) error=1;
		if(day>=4) sum = year_code + (day-4);
		else sum = year_code + day + 7 - 4;
	}
	else if (month==5) // MAY = 9/5
	{
		if((day>31||(day<1))) error=1;
		if(day>=2) sum = year_code + (day-2);
		else sum = year_code + day + 7 - 2;
	}
	else if (month==6) // JUN = 6/6
	{
		if((day>30||(day<1))) error=1;
		if(day>=6) sum = year_code + (day-6);
		else sum = year_code + day + 7 - 6;
	}
	else if (month==7) // JUL = 11/7
	{
		if((day>31||(day<1))) error=1;
		if(day>=4) sum = year_code + (day-4);
		else sum = year_code + day + 7 - 4;
	}
	else if (month==8) // AUG = 8/8
	{
		if((day>31||(day<1))) error=1;
		if(day>=1) sum = year_code + (day-1);
		else sum = year_code + day + 7 - 1;
	}
	else if (month==9) // SEP = 5/9
	{
		if((day>30||(day<1))) error=1;
		if(day>=5) sum = year_code + (day-5);
		else sum = year_code + day + 7 - 5;
	}
	else if (month==10) // OCT = 10/10
	{
		if((day>31||(day<1))) error=1;
		if(day>=3) sum = year_code + (day-3);
		else sum = year_code + day + 7 - 3;
	}
	else if (month==11) // NOV = 7/11
	{
		if((day>30||(day<1))) error=1;
		sum = year_code + day;
	}
	else if (month==12) // DEC = 12/12
	{
		if((day>31||(day<1))) error=1;
		if(day>=5) sum = year_code + (day-5);
		else sum = year_code + day + 7 - 5;
	}
	else error=1;
	
	// RESULTS //
	printf("\t");
	if(error) printf("WRONG INPUT !!"); // ERROR 
	else
		{	// CORRECT RESULT
		if(sum%7==0) printf("It's Sunday!");
		else if(sum%7==1) printf("It's Monday!");
		else if(sum%7==2) printf("It's Tuesday!");
		else if(sum%7==3) printf("It's Wednesday!");
		else if(sum%7==4) printf("It's Thursday!");
		else if(sum%7==5) printf("It's Friday!");
		else printf ("It's Saturday!");
		}
	printf("\n");
	
	}
	
	//END //
	printf("\n\n~~~Bye!~~~\n\n");
	system("PAUSE");
	return 0;
}
