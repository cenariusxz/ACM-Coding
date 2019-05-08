#include<stdio.h>
#include<string.h>
#include<algorithm>

#include<math.h>
using namespace std;
typedef long long ll;

int NUM[10000][13][32];
int D[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


bool is(int x){
	if(x%4)return 0;
	if(!(x%400))return 1;
	if(!(x%100))return 0;
	return 1;
}

int main(){
//	printf("%d\n",is(2001));
	int tmp=0;
	for(int i=2000;i<=9999;++i){
		int y1=0,t=i;
		for(int j=1;j<=4;++j){
			if(t%10==9)y1++;
			t/=10;
		}
	//	if(i==9996)printf("y1:%d\n",y1);
		for(int j=1;j<=12;++j){
			int m1=0;
			if(j==9)m1=1;
			for(int k=1;k<=D[j];++k){
				if(!is(i)&&j==2&&k==29)continue;
				int d1=0;
				if(k%10==9)d1=1;
				NUM[i][j][k]=tmp+y1+m1+d1;
				tmp=NUM[i][j][k];
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d,e,f;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(a>d||(a==d&&b>e)||(a==d&&b==e&&c>f)){
			swap(a,d);
			swap(b,e);
			swap(c,f);
		}
		int ans=0;
		int aa=a;
		while(aa){
			if(aa%10==9)ans++;
			aa/=10;
		}
		aa=b;
		while(aa){
			if(aa%10==9)ans++;
			aa/=10;
		}
		aa=c;
		while(aa){
			if(aa%10==9)ans++;
			aa/=10;
		}
		printf("%d\n",NUM[d][e][f]-NUM[a][b][c]+ans);
	}
	return 0;
}
