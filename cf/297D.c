#include<stdio.h>
#include<string.h>

char a[2005][2005];
bool vis[2005][2005];


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}

	return 0;
}
