#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct cake{
	int a,b;
	bool operator < (const cake p)const{
		return a>p.a;
	}
}c[805];
int vis[805];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&c[i].a,&c[i].b);
		}
		memset(vis,0,sizeof(vis));
		sort(c+1,c+n+1);
		for(int i=1;i<=n;++i){
			int num=0;
			for(int j=1;j<=n;++j){
				if(!vis[j]&&c[j].b>c[i].b)num++;
			}
			if(num>0){
				vis[i]=num;
				for(int j=1;j<=n;++j){
					
				}
			}
		}
	}
	return 0;
}
