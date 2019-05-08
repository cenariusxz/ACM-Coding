#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

char s[10][10];

int main(){
	int n;
	for(int i=1;i<=8;++i)scanf("%s",s[i]+1);
	int answ=10,ansb=10;
	for(int i=1;i<=8;++i){
		int minw=10,maxw=0,minb=10,maxb=0;
			bool fw=0,fb=0;
		for(int j=1;j<=8;++j){
			if(s[j][i]=='W'){
				fw=1;
				if(j<minw)minw=j;
				if(j>maxw)maxw=j;
			}
			if(s[j][i]=='B'){
				fb=1;
				if(j>maxb)maxb=j;
				if(j<minb)minb=j;
			}
		}
		if(!fw&&fb){
			if(8-maxb<ansb)ansb=8-maxb;
		}
		else if(!fb&&fw){
			if(minw-1<answ)answ=minw-1;
		}
		else if(fw&&fb){
			if(minw<minb&&minw-1<answ)answ=minw-1;
			if(maxb>maxw&&8-maxb<ansb)ansb=8-maxb;
		}

	}
	if(answ<=ansb)printf("A\n");
	else printf("B\n");
	return 0;
}
