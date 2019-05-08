#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,fa[105];

struct seg{
	int a,b,l;
	bool operator <(const seg a)const{
		return l<a.l;
	}
}s[100*100+5];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		int i,j,c=0;
		init();
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				int l;
				scanf("%d",&l);
				if(i!=j){
					s[++c].a=i;
					s[c].b=j;
					s[c].l=l;
				}
			}
		}
		int ans=0,t=0;
		sort(s+1,s+c+1);
		for(i=1;i<=c;i++){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				fa[x]=y;
				t++;
				ans+=s[i].l;
				if(t==n-1)break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
