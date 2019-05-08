#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct seg{
	int a,b,l;
	bool operator <(const seg a)const{
		return l<a.l;
	}
}s[5000];

int n,fa[105];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		int c=n*(n-1)/2;
		int i;
		for(i=1;i<=c;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].l);
		}
		sort(s+1,s+c+1);
		init();
		int t=0,ans=0;
		for(i=1;i<=c;i++){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				ans+=s[i].l;
				t++;
				fa[x]=y;
				if(t==n-1)break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
