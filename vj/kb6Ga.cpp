#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct point{
	int x,y;
}p[505];

struct seg{
	int a,b;
	double l;
}s[500*500+5];

bool cmp(seg a,seg b){
	return a.l<b.l;
}

int fa[505],n;

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int m;
			scanf("%d%d",&m,&n);
			int c=0,i,j;
			for(i=1;i<=n;i++){
				scanf("%d%d",&p[i].x,&p[i].y);
			}
			for(i=1;i<=n;i++){
				for(j=i+1;j<=n;j++){
					double l=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)*1.0);
					s[++c].a=i;
					s[c].b=j;
					s[c].l=l;
				}
			}
			sort(s+1,s+c+1,cmp);
			init();
			double ans=0;
			int t=0;
			for(i=1;i<=c;i++){
				if(t==n-m)break;
				int x=find(s[i].a),y=find(s[i].b);
				if(x!=y){
					ans=s[i].l;
					fa[x]=y;
					t++;
				}
			}
			printf("%.2lf\n",ans);
		}
	}
	return 0;
}
