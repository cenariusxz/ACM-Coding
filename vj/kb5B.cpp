#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,fa[30005],num[30005];

void init(){
	for(int i=0;i<n;i++){fa[i]=i;num[i]=1;}
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

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0)){
		init();
		int i,j;
		for(i=1;i<=m;i++){
			int t,a,b;
			cin>>t;
			for(j=1;j<=t;j++){
				cin>>a;
				if(j==1)b=a;
				else{
					int x=find(a),y=find(b);
					if(x!=y){
						fa[x]=y;
						num[y]+=num[x];
					}
				}
			}
		}
		int x=find(0);
		printf("%d\n",num[x]);
	}
	return 0;
}
