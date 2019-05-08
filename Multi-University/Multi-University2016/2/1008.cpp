#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n,m;
int x[1010];
int a,b;

void solve(){
	int pos1=0,pos2=0;
	int s0=0,s1=0;
	while(pos1<n&&pos2<n){
		int r0=0,r1=0;
		int l0=0,l1=0;
		if(pos1==pos2){
			if(pos1%2){
				l1=1;
				r1=x[pos1];
			}
			else{
				l0=1;
				r0=x[pos1];
			}
		}
		else{
			if(pos1%2){r1+=x[pos1];l1+=1;}
			else {r0+=x[pos1];l0+=1;}
			if(pos2%2){r1+=x[pos2];l1+=1;}
			else {r0+=x[pos2];l0+=1;}
		}
		if(s0+l0<=a&&s0+r0>=a&&s1+l1<=b&&s1+r1>=b){
			putchar('1');
			return;
		}
		int p1=0,p2=0;
		if(s0+l0>a||s1+l1>b)p1=1;
		if(s0+r0<a||s1+r1<b)p2=1;
		if(p2){
			if(pos1<pos2){
				int add=x[pos2];
				if(pos2%2)s1+=add;
				else s0+=add;
			}
			pos2++;
		}
		if(p1){
			if(pos1+1<pos2){
				int del=x[pos1+1];
				if((pos1+1)%2)s1-=del;
				else s0-=del;
			}
			pos1++;
		}
	}
	putchar('0');
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%d",&x[i]);
		}
		while(m--){
			scanf("%d%d",&a,&b);
			solve();
		}
		printf("\n");
	}
	return 0;
}
