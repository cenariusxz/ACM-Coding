#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int fa[1005],n,v[1005];
struct seg{
	int a,b,v;
}s[1000005];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool cmp(seg a,seg b){
	return a.v<b.v;
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d",&n);
			int i,j,c=0,ans=0,t=0;
			for(i=1;i<=n;i++){
				scanf("%d",&v[i]);
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					int l;
					scanf("%d",&l);
					if(i!=j){
						s[++c].a=i;
						s[c].b=j;
						s[c].v=v[i]+v[j]+l;
					}
				}
			}
			sort(s+1,s+c+1,cmp);
			init();
			for(i=1;i<=c;i++){
				int x=find(s[i].a),y=find(s[i].b);
				if(x!=y){
					ans+=s[i].v;
					fa[x]=y;
					t++;
				}
				if(t==n-1)break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
