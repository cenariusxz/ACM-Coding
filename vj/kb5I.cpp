#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=4e4+10;

int fa[maxm],north[maxm],east[maxm];
int a[maxm],b[maxm],l[maxm],ans[10005];
char s[maxm][3];
struct que{
	int num,a,b,t;
	bool operator < (const que a)const{
		return t<a.t;
	}
}q[10005];

int abs(int a){return a>0?a:-a;}

void init(int n){
	for(int i=1;i<=n;++i){
		fa[i]=i;
		north[i]=east[i]=0;
	}
}

int find(int x){
	int r=x,t1,t2,t3,cn=0,ce=0;
	while(r!=fa[r]){
		cn+=north[r];
		ce+=east[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=cn-north[x];
		t3=ce-east[x];
		north[x]=cn;
		east[x]=ce;
		fa[x]=r;
		cn=t2;
		ce=t3;
		x=t1;
	}
	return r;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;++i)scanf("%d%d%d%s",&a[i],&b[i],&l[i],s[i]);
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].t);
		q[i].num=i;
	}
	sort(q+1,q+k+1);
	int pos=1;
	for(int i=1;i<=m;++i){
		int x=find(a[i]),y=find(b[i]);
		int Cn=0,Ce=0;
		if(s[i][0]=='N')Cn=l[i];
		else if(s[i][0]=='S')Cn=-l[i];
		else if(s[i][0]=='E')Ce=l[i];
		else if(s[i][0]=='W')Ce=-l[i];
		if(x!=y){
			fa[x]=y;
			north[x]=north[b[i]]+Cn-north[a[i]];
			east[x]=east[b[i]]+Ce-east[a[i]];
		}
		
		while(q[pos].t==i&&pos<=k){
			x=find(q[pos].a);
			y=find(q[pos].b);
			if(x!=y)ans[q[pos].num]=-1;
			else ans[q[pos].num]=abs(north[q[pos].a]-north[q[pos].b])+abs(east[q[pos].a]-east[q[pos].b]);
			pos++;
		}
	}
	for(int i=1;i<=k;++i)printf("%d\n",ans[i]);
	return 0;
}
