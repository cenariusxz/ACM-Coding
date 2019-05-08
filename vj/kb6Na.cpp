#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct seg{
	int a,b;
	double l;
	bool operator <(const seg a)const{
		return l-a.l<1e-10;
	}
}s[5000];

struct point{
	int x,y;
}p[105];

int n,fa[105];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d",&n);
			int i;
			for(i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
			int j,c=0;
			for(i=1;i<=n;i++){
				for(j=i+1;j<=n;j++){/*
					double l=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)*1.0+(p[i].y-p[j].y)*(p[i].y-p[j].y)*1.0);
					if(l-10>=1e-10&&l-1000<=1e-10){
						s[++c].a=i;
						s[c].b=j;
						s[c].l=l;
					}*/
					int m=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
					if(m>=100&&m<=1000000){
						double l=sqrt(1.0*m);
						s[++c].a=i;
						s[c].b=j;
						s[c].l=l;
					}
				}
			}
			init();
			sort(s+1,s+c+1);
			bool f=0;
			int t=0;
			double ans=0;
			if(t==n-1)f=1;
			for(i=1;i<=c;i++){
				int x=find(s[i].a),y=find(s[i].b);
				if(x!=y){
					fa[x]=y;
					t++;
					ans+=s[i].l;
					if(t==n-1){
						f=1;
						break;
					}
				}
			}
			if(f) printf("%.1lf\n",ans*100);
			else printf("oh!\n");
		}
	}
	return 0;
}
