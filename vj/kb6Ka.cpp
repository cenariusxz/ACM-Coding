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

int n,fa[105],p[105];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int T,i;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int m;
			scanf("%d%d",&n,&m);
			for(i=1;i<=m;i++){
				scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].l);
			}	
			sort(s+1,s+m+1);
			init();
			int c=0,t=0,ans=0;
			for(i=1;i<=m;i++){
				int x=find(s[i].a),y=find(s[i].b);
				if(x!=y){
					fa[x]=y;
					ans+=s[i].l;
					t++;
					p[++c]=i;
					if(t==n-1)break;
				}
			}
			bool f=1;
			for(int j=1;j<=c;j++){
				if(!f)break;
				init();
				t=0;
				int tmp=0;
				for(i=1;i<=m;i++){
					if(i!=p[j]){
						int x=find(s[i].a),y=find(s[i].b);
						if(x!=y){
							fa[x]=y;
							tmp+=s[i].l;
							t++;
							if(t==n-1){
								if(tmp==ans)f=0;
								break;
							}
						}
					}
				}
			}
			if(f)printf("%d\n",ans);
			else printf("Not Unique!\n");
		}
	}
	return 0;
}
