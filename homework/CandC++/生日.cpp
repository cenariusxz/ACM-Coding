#include<stdio.h>
int main()
{
	int year,day,month,i,j,m,n;
	int month1(int m);
	int day1(int m);
	int month2(int m);
	int day2(int m);
	scanf("%d",&n);
	if (n<=8)
	{
		year=1996;
		month=9;
		day=22+n;
	}
	else 
	{
		if (n>8&&n<=8+31)
		{
			year=1996;
			month=10;
			day=n-8;
		}
		else
		{
			if (n>8+31&&n<=8+31+30)
			{
				year=1996;
				month=11;
				day=n-8-31;
			}
			else
			{
				if (n>8+31+30&&n<=8+31+30+31)
				{
					year=1996;
					month=12;
					day=n-8-31-30;
				}
				else
				{
					if (n>8+31+30+31)
					{
						i=(n-8-31-30-31)/365;
						j=i;
						if ((i%4)==0&&(n-8-31-30-31)%365<=(i/4)) j--;
						year=1996+j+1;
						m=n-8-31-30-31-365*j-j/4;
						if (m==0) 
						{
							year--;
							if (i%4==0) m=366;
							else m=365;
						}
						if (year%4==0)
						{
							month=month2(m);
							day=day2(m);
						}
						else
						{
							month=month1(m);
							day=day1(m);
						}
					}
				}
			}
		}
	}
	printf("阿喵生日的第%d天是%d年%d月%d日\t",n,year,month,day);
	return 0;
}

int month1(int m)
{
	if (m>=1&&m<=31) return 1;
	if (m>31&&m<=31+28) return 2;
	if (m>31+28&&m<=31+28+31) return 3;
	if (m>31+28+31&&m<=31+28+31+30) return 4;
	if (m>31+28+31+30&&m<=31+28+31+30+31) return 5;
	if (m>31+28+31+30+31&&m<=31+28+31+30+31+30) return 6;
	if (m>31+28+31+30+31+30&&m<=31+28+31+30+31+30+31) return 7;
	if (m>31+28+31+30+31+30+31&&m<=31+28+31+30+31+30+31+31) return 8;
	if (m>31+28+31+30+31+30+31+31&&m<=31+28+31+30+31+30+31+31+30) return 9;
	if (m>31+28+31+30+31+30+31+31+30&&m<=31+28+31+30+31+30+31+31+30+31) return 10;
	if (m>31+28+31+30+31+30+31+31+30+31&&m<=31+28+31+30+31+30+31+31+30+31+30) return 11;
	if (m>31+28+31+30+31+30+31+31+30+31+30&&m<=31+28+31+30+31+30+31+31+30+31+30+31) return 12;
}

int day1(int m)
{
	if (m>=1&&m<=31) return m;
	if (m>31&&m<=31+28) return m-31;
	if (m>31+28&&m<=31+28+31) return m-31-28;
	if (m>31+28+31&&m<=31+28+31+30) return m-31-28-31;
	if (m>31+28+31+30&&m<=31+28+31+30+31) return m-31-28-31-30;
	if (m>31+28+31+30+31&&m<=31+28+31+30+31+30) return m-31-28-31-30-31;
	if (m>31+28+31+30+31+30&&m<=31+28+31+30+31+30+31) return m-31-28-31-30-31-30;
	if (m>31+28+31+30+31+30+31&&m<=31+28+31+30+31+30+31+31) return m-31-28-31-30-31-30-31;
	if (m>31+28+31+30+31+30+31+31&&m<=31+28+31      +30+31+30+31+31+30) return m-31-28-31-30-31-30-31-31;
	if (m>31+28+31+30+31+30+31+31+30&&m<=31+28+31+30+31+30+31+31+30+31) return m-31-28-31-30-31-30-31-31-30;
	if (m>31+28+31+30+31+30+31+31+30+31&&m<=31+28+31+30+31+30+31+31+30+31+30) return m-31-28-31-30-31-30-31-31-30-31;
	if (m>31+28+31+30+31+30+31+31+30+31+30&&m<=31+28+31+30+31+30+31+31+30+31+30+31) return m-31-28-31-30-31-30-31-31-30-31-30;
}

int month2(int m)
{
	if (m>=1&&m<=31) return 1;
	if (m>31&&m<=31+29) return 2;
	if (m>31+29&&m<=31+29+31) return 3;
	if (m>31+29+31&&m<=31+29+31+30) return 4;
	if (m>31+29+31+30&&m<=31+29+31+30+31) return 5;
	if (m>31+29+31+30+31&&m<=31+29+31+30+31+30) return 6;
	if (m>31+29+31+30+31+30&&m<=31+29+31+30+31+30+31) return 7;
	if (m>31+29+31+30+31+30+31&&m<=31+29+31+30+31+30+31+31) return 8;
	if (m>31+29+31+30+31+30+31+31&&m<=31+29+31+30+31+30+31+31+30) return 9;
	if (m>31+29+31+30+31+30+31+31+30&&m<=31+29+31+30+31+30+31+31+30+31) return 10;
	if (m>31+29+31+30+31+30+31+31+30+31&&m<=31+29+31+30+31+30+31+31+30+31+30) return 11;
	if (m>31+29+31+30+31+30+31+31+30+31+30&&m<=31+29+31+30+31+30+31+31+30+31+30+31) return 12;
}

int day2(int m)
{
	if (m>=1&&m<=31) return m;
	if (m>31&&m<=31+29) return m-31;
	if (m>31+29&&m<=31+29+31) return m-31-29;
	if (m>31+29+31&&m<=31+29+31+30) return m-31-29-31;
	if (m>31+29+31+30&&m<=31+29+31+30+31) return m-31-29-31-30;
	if (m>31+29+31+30+31&&m<=31+29+31+30+31+30) return m-31-29-31-30-31;
	if (m>31+29+31+30+31+30&&m<=31+29+31+30+31+30+31) return m-31-29-31-30-31-30;
	if (m>31+29+31+30+31+30+31&&m<=31+29+31+30+31+30+31+31) return m-31-29-31-30-31-30-31;
	if (m>31+29+31+30+31+30+31+31&&m<=31+29+31+30+31+30+31+31+30) return m-31-29-31-30-31-30-31-31;
	if (m>31+29+31+30+31+30+31+31+30&&m<=31+29+31+30+31+30+31+31+30+31) return m-31-29-31-30-31-30-31-31-30;
	if (m>31+29+31+30+31+30+31+31+30+31&&m<=31+29+31+30+31+30+31+31+30+31+30) return m-31-29-31-30-31-30-31-31-30-31;
	if (m>31+29+31+30+31+30+31+31+30+31+30&&m<=31+29+31+30+31+30+31+31+30+31+30+31) return m-31-29-31-30-31-30-31-31-30-31-30;
}