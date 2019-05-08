#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct seg{
	int a,b,l;
	bool operator<(const seg a)const{
		return l<a.l;
	}
}s[2*1000*1000+100];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x;
}

int fa[1000*1000+100];

void init(int n){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	int r=x,t;
	while(fa[r]!=r)r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int g[1000][1000];

int aabs(int a){
	return a>=0?a:-a;
}

int main(){
	int T,i,j;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int m,n;
		n=read();
		m=read();
		init(m*n);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)g[i][j]=read();;
		}
		int cnt=0,t=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i+1<=n){
					if(g[i][j]-g[i+1][j]==0){
						int x=find((i-1)*m+j),y=find(i*m+j);
						if(x!=y){
							fa[x]=y;
							t++;
						}
					}
					else{
						cnt++;
						s[cnt].a=(i-1)*m+j;
						s[cnt].b=i*m+j;
						s[cnt].l=aabs(g[i][j]-g[i+1][j]);
					}
				}
				if(j+1<=m){
					if(g[i][j]-g[i][j+1]==0){
						int x=find((i-1)*m+j),y=find((i-1)*m+j+1);
						if(x!=y){
							fa[x]=y;
							t++;
						}
					}
					else{
						cnt++;
						s[cnt].a=(i-1)*m+j;
						s[cnt].b=(i-1)*m+j+1;
						s[cnt].l=aabs(g[i][j]-g[i][j+1]);
					}
				}
			}
		}
		sort(s+1,s+cnt+1);
		int ans=0;
		for(i=1;i<=cnt&&t<n*m-1;i++){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				ans+=s[i].l;
				t++;
				fa[x]=y;
				if(t==n*m-1)break;
			}
		}
		printf("Case #%d:\n%d\n",q,ans);
	}
	return 0;
}
