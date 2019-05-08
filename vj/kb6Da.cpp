#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct seg{
	int a,b,l;
}s[10005];

int n,fa[105];

bool cmp(seg a,seg b){
	return a.l<b.l;
}

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
//	return fa[x]==x?x:fa[x]=find(fa[x]);
	int r=x,t;
	while(fa[r]!=r)r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		int i,j,c=0;
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				int l;
				scanf("%d",&l);
				if(i!=j){
					s[++c].l=l;
					s[c].a=i;
					s[c].b=j;
				}
			}
		}
		sort(s+1,s+c+1,cmp);
		init();
		int q,t=0;
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a),y=find(b);
			if(x!=y){
				fa[x]=y;
				t++;
			}
		}
		int ans=0;
		for(i=1;i<=c;i++){
			if(t==n-1)break;
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				ans+=s[i].l;
				fa[x]=y;
				t++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
