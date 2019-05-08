#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int fa[105],n;

struct cell{
	double x,y,z,r;
}c[105];

struct seg{
	int a,b;
	double l;
}s[10005];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
/*
void unio(int x,int y){
	int dx=find(x),dy=find(y);
	if(dx!=dy)fa[dx]=dy;
}
*/
bool cmp(seg a,seg b){
	return a.l-b.l<1e-10;
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j,cnt=0;
		for(i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&c[i].x,&c[i].y,&c[i].z,&c[i].r);
			for(j=1;j<i;j++){
				double l=sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y)+(c[i].z-c[j].z)*(c[i].z-c[j].z))-c[i].r-c[j].r;
				if(l-0<=1e-10)l=0;
				s[++cnt].l=l;
				s[cnt].a=i;
				s[cnt].b=j;
			}
		}
		init();
		sort(s+1,s+cnt+1,cmp);
		int t=0;
		double ans=0;
		for(i=1;i<=cnt;i++){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				fa[x]=y;
				ans+=s[i].l;
				t++;
			}
			if(t==n-1)break;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
