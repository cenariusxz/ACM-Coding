#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int fa[200005],num[200005],n,m;

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
		num[x]=c;
		fa[x]=r;
		c=t2;
		x=t1;
	}
	return r;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		int i,ans=0;
		for(i=1;i<=m;i++){
			int a,b,v;
			cin>>a>>b>>v;
			a--;
			int x=find(a),y=find(b);
			if(x==y){
				if(num[b]-num[a]!=v)ans++;
			}
			else{
				fa[y]=x;
				num[y]=num[a]+v-num[b];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
