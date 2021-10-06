/*
	C PROGRAM TO MAKE A SYSTEM DIGITAL CLOCK
	AUTHOR:: SREEPARNA RAY
	DATE:: 8TH SEP,2021
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


void zero(int , int );
void one(int , int );
void two(int , int );
void three(int , int );
void four(int , int );
void five(int , int );
void six(int , int );
void seven(int , int );
void eight(int , int );
void nine(int , int );
void colon(int , int );
void call(int ,int ,int );
void getTime(int ,int ,int );
void delay(int );
void gotoxy();

int main()
{
	int hour, minutes, seconds, day, month, year;
	gotoxy(30,2);
	printf("SYSTEM DIGITAL CLOCK");
	gotoxy(30,3);
	printf("--------------------");
    time_t now;
    time(&now);
    gotoxy(28,5);
    printf("%s", ctime(&now));
    struct tm *local = localtime(&now);
 
    hour = local->tm_hour;         
    minutes = local->tm_min;        
    seconds = local->tm_sec;
    
    day = local->tm_mday;            
    month = local->tm_mon + 1;      
    year = local->tm_year + 1900;  
    
    gotoxy(70,17);
    printf("%02d/%02d/%d\n", day, month, year);
	        
	while(1)
	{
		for(hour;hour<24;hour++)
		{
			gotoxy(70,15);
			if(hour<12)
				printf("AM");
			else
				printf("PM");
			for(minutes;minutes<60;minutes++)
			{
				for(seconds;seconds<60;seconds++)
				{
					getTime(hour,minutes,seconds);
					delay(1);
				}
				seconds=00;
			}
			minutes=00;
		}
		hour=00;
	}
	
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(int seconds)
{
	int ms=1000*seconds;
	
	clock_t start_time=clock();
	while(clock() < start_time + ms)
		;
}

void getTime(int hour,int minutes,int seconds)
{
	
	/*
	//using TURBO C++
	struct dostime_t time;
	_dos_gettime(&time);
	//printf("%d : %d : %d ",time.hour,time.minute,time.second);
	hour=time.hour;
	minutes=time.minute;
	seconds=time.second;
	*/
	
	call(hour/10,10,15);
	call(hour%10,19,15);
	colon(25,15);
	call(minutes/10,31,15);
	call(minutes%10,40,15);
	colon(46,15);
	call(seconds/10,52,15);
	call(seconds%10,61,15);
}

void call(int digit,int x,int y)
{
	switch(digit)
	{
		case 1:one(x,y);break;
		case 2:two(x,y);break;
		case 3:three(x,y);break;
		case 4:four(x,y);break;
		case 5:five(x,y);break;
		case 6:six(x,y);break;
		case 7:seven(x,y);break;
		case 8:eight(x,y);break;
		case 9:nine(x,y);break;
		case 0:zero(x,y);break;
		default:zero(x,y);break;
	}
}

void zero(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==9||j==1||j==5)
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void one(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(j==3)
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void two(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||i==9||(i<5 && j==5)||(j==1 && i>5))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void three(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||i==9||j==5)
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void four(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==5||j==5||(j==1 && i<5))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void five(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||i==9||(i>5 && j==5)||(j==1 && i<5))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void six(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||i==9||j==1||(j==5 && i>5))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void seven(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||j==5)
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void eight(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||i==9||j==1||j==5)
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void nine(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if(i==1||i==5||j==5||i==9||(j==1 && i<5))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}

void colon(int x, int y)
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=5;j++)
		{
			gotoxy(x,y);
			if((j==3 && i==3)||(j==3 && i==7))
				printf("@");
			else
				printf(" ");
			x++;
		}
		y++;
		x=x-5;
		printf("\n");
	}
}


