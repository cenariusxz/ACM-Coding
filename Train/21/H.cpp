#include<bits/stdc++.h>
#define MAXN 510
using namespace std;
int n,m;
int fa[MAXN],v[MAXN];

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void fuck()
{
	int i,x,y,ans=n;
	memset(v,0,sizeof(v));
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			if(v[fx]+v[fy]==1) ans--;
			else if(v[fx]+v[fy]==0) ans--;
		}
		else{
			if(v[fx]==0){
				v[fx]=1;
				ans--;
			}
		}
		fa[fy]=fx;
		v[fx]=(v[fx]|v[fy]);
	}
	if(ans==0) printf("No trees.\n");
	else if(ans==1) printf("There is one tree.\n");
	else printf("A forest of %d trees.\n",ans);
}

int main()
{
	int t=0;
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		printf("Case %d: ",++t);
		fuck();
	}
 return 0;
}
