#include<stdio.h>
#include<string.h>

int vis[5];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		vis[a]++;
	}
	int ans=0;
	ans+=vis[4];
	ans+=vis[3];
	if(vis[3]<=vis[1]){
		vis[1]-=vis[3];
	}
	else{
		vis[1]=0;
	}
	ans+=vis[2]/2+(vis[2]%2);
	if(vis[2]%2){
		vis[1]-=2;
	}
	if(vis[1]>0){
		ans+=vis[1]/4+(vis[1]%4?1:0);
	}
	printf("%d\n",ans);
	return 0;
}
