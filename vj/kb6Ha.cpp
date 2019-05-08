#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct point{
	int x,y;
}p[755];

struct seg{
	int a,b;
	double l;
	bool operator <(const seg a)const
	{
		return l<a.l;
	}
}s[750*750+5];
/*
inline bool cmp(seg a,seg b){
	return a.l-b.l<1e-10;
}
*/
int fa[755],n;

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		int c=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				double l=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)*1.0);
				s[++c].a=i;
				s[c].b=j;
				s[c].l=l;
			}
		}
		sort(s+1,s+c+1);
		int m;
		scanf("%d",&m);
		int t=0;
		for(i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a),y=find(b);
			if(x!=y){
				t++;
				fa[x]=y;
			}
		}
		for(i=1;i<=c;i++){
			if(t==n-1){
				break;
			}
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				t++;
				if(s[i].l>1e-10)printf("%d %d\n",s[i].a,s[i].b);
				fa[x]=y;
			}
		}
	}
	return 0;
}
