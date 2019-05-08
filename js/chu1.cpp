#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int num[11]={6,2,5,5,4,5,6,3,7,6};
int mm[13],dd[32];
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yy[3000];
int day[3000][13][32];
char s[15];

void init(){
	int i,j,k;
	for(i=1;i<=12;i++){
		mm[i]=num[i/10]+num[i%10];
	}
	for(i=1;i<=31;i++){
		dd[i]=num[i/10]+num[i%10];
	}
	for(i=0;i<=2999;i++){
		yy[i]=num[i/1000]+num[(i%1000)/100]+num[(i%100)/10]+num[i%10];
	}
	for(i=0;i<=2999;i++){
		for(j=1;j<=12;j++){
			int lim=md[j];
			if((j==2)&&(((i%400)==0)||((i%100)!=0&&(i%4)==0)))lim++;
			for(k=1;k<=lim;k++){
				day[i][j][k]=yy[i]+mm[j]+dd[k];
			}
		}
	}
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%s%d",s,&n);
		int y=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
		int m=(s[4]-'0')*10+s[5]-'0';
		int d=(s[6]-'0')*10+s[7]-'0';
		int cnt=0,i,j,k;
		bool f=1;
		for(i=y;i<=2999&&f;i++){
			for(j=1;j<=12&&f;j++){
				int lim=md[j];
				if((j==2)&&(((i%400)==0)||((i%100)!=0&&(i%4)==0)))lim++;
				for(k=1;k<=lim&&f;k++){
					if(i==y&&(j<m||(j==m&&k<d))){
						continue;
					}
					if(day[i][j][k]==n){
						f=0;
						break;
					}
					cnt++;
				}

			}
		}
		if(f)printf("-1\n");
		else printf("%d\n",cnt);
	}
	return 0;
}
