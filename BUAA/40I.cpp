#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct col{
	int x,yy,y2,l;
	bool operator<(const col a)const{
		return x<a.x;
	}
}c[10];

struct row{
	int y,xx,x2,l;
	bool operator<(const row a)const{
		return y<a.y;
	}
}
r[10];

int cntr,cntc;
int xx,yy,x2,y2;

void check(){
	if(xx==x2&&yy!=y2){
		++cntc;
		if(yy>y2)swap(yy,y2);
		c[cntc].x=xx;
		c[cntc].yy=yy;
		c[cntc].y2=y2;
		c[cntc].l=y2-yy;
	}
	else if(yy==y2&&xx!=x2){
		++cntr;
		if(xx>x2)swap(xx,x2);
		r[cntr].y=yy;
		r[cntr].xx=xx;
		r[cntr].x2=x2;
		r[cntr].l=x2-xx;
	}
}

int main(){
	while(scanf("%d%d%d%d",&xx,&yy,&x2,&y2)!=EOF){
		cntr=0,cntc=0;
		check();
		for(int i=1;i<=5;++i){
			scanf("%d%d%d%d",&xx,&yy,&x2,&y2);
			check();
		}
		if(cntc!=3||cntr!=3)printf("sro\n");
		else{
			sort(c+1,c+3+1);
			sort(r+1,r+3+1);
			int l=r[1].l;
			if(c[1].l!=2*l||c[3].l!=2*l)printf("sro\n");
			else if(c[2].l!=l||r[1].l!=l||r[2].l!=l||r[3].l!=l)printf("sro\n");
			else if(c[2].x-c[1].x!=l||c[3].x-c[2].x!=l)printf("sro\n");
			else if(c[1].yy!=c[2].yy||c[2].yy!=c[3].yy)printf("sro\n");
			else if(r[2].y-r[1].y!=l||r[3].y-r[2].y!=l)printf("sro\n");
			else if(r[2].xx!=r[1].xx||r[3].xx!=r[2].xx)printf("sro\n");
			else if(r[3].xx!=c[1].x||r[3].y!=c[1].y2)printf("sro\n");
			else printf("orz\n");
		}
	}
	return 0;
}
