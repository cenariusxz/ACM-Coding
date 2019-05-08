#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int fa[1005],n;

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	int r=x,t;
	while(r!=fa[r])r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int main(){
	int m,t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			cin>>n>>m;
			int c=n;
			int i;
			init();
			for(i=1;i<=m;i++){
				int a,b;
				cin>>a>>b;
				int x=find(a),y=find(b);
				if(x!=y){
					fa[x]=y;
					c--;
				}
			}
			cout<<c<<endl;
		}
	}
	return 0;
}
