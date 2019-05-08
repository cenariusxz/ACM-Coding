#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int fa[30],n;

struct seg{
	int a,b,l;
}s[80];

bool cmp(seg a,seg b){
	return a.l<b.l;
}

void init(){
	int i;for(i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

void unio(int x,int y){
	int dx=find(x),dy=find(y);
	if(dx!=dy)fa[dx]=dy;
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		char a[2],b[2];
		int i,t,c=0;
		memset(s,0,sizeof(s));
		for(i=1;i<n;i++){
			scanf("%s%d",a,&t);
			int v;
			for(int j=1;j<=t;j++){
				scanf("%s%d",b,&v);
				s[++c].a=a[0]-'A'+1;
				s[c].b=b[0]-'A'+1;
				s[c].l=v;
			}
		}
		init();
		sort(s+1,s+c+1,cmp);
		int ans=0;t=0;
		for(i=1;i<=c;i++){
			if(find(s[i].a)==find(s[i].b))continue;
			ans+=s[i].l;
			unio(s[i].a,s[i].b);
			t++;
			if(t==n-1)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
