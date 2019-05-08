#include<stdio.h>
int main()
{
int year,day,month,i,j,k,m,n,count;

n=49+365+366+365+365+365+366+365+365+365+366+365+365+365+1;
i=(n-49-365-366)/365;
j=i;
if ((i%4)==0&&(n-49-365-366)%365<=(i/4)) j--;
year=2012+j+1;
m=n-49-365-366-365*j-j/4;
if (m==0) 
{
	year--;
	if (i%4==0) m=366;
	else m=365;
}
//if (i%4==0)
return 0;
}