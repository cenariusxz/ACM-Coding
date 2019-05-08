#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;

int fa[100005];
ll num[100005];
char s[10];

void init(int n){
	for(int i=0;i<n;i++){fa[i]=i;num[i]=0;}
}

int find(int x){
	ll r=x,t1,t2,c=0;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=c-num[x];
		num[x]=c;
		fa[x]=r;
		c=t2;
		x=t1;
	}
	return r;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n+m)){
		int i,j,a,b,c;
		init(n+3);
		for(i=1;i<=m;i++){
			scanf("%s",s);
			if(s[0]=='!'){
				scanf("%d%d%d",&a,&b,&c);
				int x=find(a),y=find(b);
				if(x!=y){
					fa[x]=y;
					num[x]=num[b]+c-num[a];
				}
			}
			else if(s[0]=='?'){
				scanf("%d%d",&a,&b);
				int x=find(a),y=find(b);
				if(x!=y){
					printf("UNKNOWN\n");
				}
				else printf("%lld\n",num[a]-num[b]);
			}

		}
	}
	return 0;
}
