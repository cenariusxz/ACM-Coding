#include <bits/stdc++.h>
using namespace std;

int mm[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int Y1,m1,d1,Y2,m2,d2;

bool is(int year){
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool checkin(int y,int m,int d){
	if((y == Y1 && m < m1) || (y == Y1 && m == m1 && d < d1))return 0;
	if((y == Y2 && m > m2) || (y == Y2 && m == m2 && d > d2))return 0;
	return 1;
}

bool checkis(int y,int m,int d){
	int s[10];
	s[1] = y/1000;
	s[2] = y/100%10;
	s[3] = y/10%10;
	s[4] = y%10;
	s[5] = m/10;
	s[6] = m%10;
	s[7] = d/10;
	s[8] = d%10;
	return s[1] == s[8] && s[2] == s[7] && s[3] == s[6] && s[4] == s[5];
}

int main(){
	scanf("%4d%2d%2d",&Y1,&m1,&d1);
	scanf("%4d%2d%2d",&Y2,&m2,&d2);
	int ans = 0;
	for(int y = Y1 ; y <= Y2 ; ++y){
		for(int m = 1 ; m <= 12 ; ++ m){
			int limd = mm[m];
			if(is(y) && m==2)limd++;
			for(int d = 1 ; d <= limd ; ++ d){
				if(checkin(y,m,d) && checkis(y,m,d))ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
