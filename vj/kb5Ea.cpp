#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int fa[50005],num[50005],n,m;

void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		num[i]=0;
	}
}

int find(int x){
	int r=x,t1,t2,c=0;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=c-num[x];
		num[x]=c%3;
		fa[x]=r;
		x=t1;
		c=t2;
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
		int a,b,v,i,ans=0;
		init();
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&v,&a,&b);
			if(a>n||b>n||(a==b&&v==2))ans++;
			else if(a==b&&v==1)continue;
			else{
				int x=find(a),y=find(b);
				if(x==y){
					if((((num[a]-num[b])%3)+3)%3!=(v-1))ans++;
				}
				else{
					fa[x]=y;
					num[x]=((num[b]+(v-1)-num[a])%3+3)%3;
				}
			}
		}
		printf("%d\n",ans);
	
	return 0;
}
