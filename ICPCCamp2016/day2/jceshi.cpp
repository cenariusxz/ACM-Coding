#include<stdio.h>
#include<string.h>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int vis[16];
		for(int i=1;i<(1<<n);++i){
			memset(vis,0,sizeof(vis));
			int num=0;
			for(int j=0;j<n;++j){
				if(i&(1<<(j))){
					num^=(j+1);
					vis[j+1]=1;
				}
			}
			if(!num){
				bool f=0;
			//	for(int j=2;j<=n;j+=2)if(vis[j]&&vis[j+1])f=1;
				int cnt=0;
				if(!vis[13])f=1;
				for(int j=1;j<=n;++j)if(vis[j])cnt++;
				if(!f&&cnt==3){
					for(int j=1;j<=n;++j)if(vis[j])printf("%d ",j);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
