#include<stdio.h>
#include<string.h>

char a[55][55];
bool vis[30];

int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)scanf("%s",a[i]+1);
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){	
			memset(vis,0,sizeof(vis));
			vis[a[i][j]-'a']=1;
			if(a[i+1][j]>='a'&&a[i+1][j]<='z')vis[a[i+1][j]-'a']=1;
			if(a[i][j+1]>='a'&&a[i][j+1]<='z')vis[a[i][j+1]-'a']=1;
			if(a[i+1][j+1]>='a'&&a[i+1][j+1]<='z')vis[a[i+1][j+1]-'a']=1;
			if(vis['a'-'a']&&vis['f'-'a']&&vis['c'-'a']&&vis['e'-'a'])ans++;
		}
	}
	printf("%d\n",ans);
}
