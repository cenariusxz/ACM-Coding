#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
struct Point{
	int x,y;
	bool operator < (const Point a)const{
		if(x==a.x)return y<a.y;
		return x<a.x;
	}
}p[10005];
int cnt;

struct Line{
	int x,l,r;
	bool operator < (const Line a)const{
		return x<a.x;
	}
}l[10005];

int ansx[200000],ansy[200000];

int main(){
	int c=0;
	while(scanf("%d",&n)!=EOF&&n){
		cnt=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		sort(p+1,p+n+1);
		int pre=-1;
		for(int i=1;i<=n;++i){
			if(p[i].x!=pre){
				++cnt;
				l[cnt].x=p[i].x;
				l[cnt].l=p[i].y;
				l[cnt].r=p[i].y;
				pre=p[i].x;
			}
			else{
				l[cnt].r=p[i].y;
			}
		}
		int maxx=-1,minn=0x3f3f3f3f;
		int maxpos,minpos;
		for(int i=1;i<=cnt;++i){
			if(l[i].l<minn){
				minn=l[i].l;
				minpos=i;
			}
			if(l[i].r>maxx){
				maxx=l[i].r;
				maxpos=i;	
			}
		}
		int prel=l[1].l;
		for(int i=2;i<=minpos;++i){
			if(l[i].l>prel){
				l[i].l=prel;
			}
			else{
				prel=l[i].l;
			}
		}
		prel=l[cnt].l;
		for(int i=cnt;i>=minpos;--i){
			if(l[i].l>prel){
				l[i].l=prel;
			}
			else{
				prel=l[i].l;
			}
		}
		int prer=l[1].r;
		for(int i=2;i<=maxpos;++i){
			if(l[i].r<prer){
				l[i].r=prer;
			}
			else{
				prer=l[i].r;
			}
		}
		prer=l[cnt].r;
		for(int i=cnt;i>=maxpos;--i){
			if(l[i].r<prer){
				l[i].r=prer;
			}
			else{
				prer=l[i].r;
			}
		}
		int res=0;
		++res;
		ansx[res]=l[1].x;
		ansy[res]=l[1].l;
		++res;
		ansx[res]=l[1].x;
		ansy[res]=l[1].r+9;
		for(int i=2;i<=cnt;++i){
			if(l[i].r>l[i-1].r){
				++res;
				ansx[res]=l[i].x;
				ansy[res]=l[i-1].r+9;
				++res;
				ansx[res]=l[i].x;
				ansy[res]=l[i].r+9;
			}
			if(l[i].r<l[i-1].r){
				++res;
				ansx[res]=l[i].x-1;
				ansy[res]=l[i-1].r+9;
				++res;
				ansx[res]=l[i].x-1;
				ansy[res]=l[i].r+9;

			}
		}
		++res;
		ansx[res]=l[cnt].x+9;
		ansy[res]=l[cnt].r+9;
		++res;
		ansx[res]=l[cnt].x+9;
		ansy[res]=l[cnt].l;
		for(int i=cnt-1;i>=1;--i){
			if(l[i].l>l[i+1].l){
				++res;
				ansx[res]=l[i+1].x;
				ansy[res]=l[i+1].l;
				++res;
				ansx[res]=l[i+1].x;
				ansy[res]=l[i].l;
			}
			if(l[i].l<l[i+1].l){
				++res;
				ansx[res]=l[i+1].x-1;
				ansy[res]=l[i+1].l;
				++res;
				ansx[res]=l[i+1].x-1;
				ansy[res]=l[i].l;
			}

		}
		printf("Case %d: ",++c);
		for(int i=1;i<=res;++i){
			printf("%d %d",ansx[i],ansy[i]);
			if(i==res)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
