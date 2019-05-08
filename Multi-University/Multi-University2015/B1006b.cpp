#include<stdio.h>
#include<string.h>

int n,m,ans;
bool vis[9][9];
int cnt[9],ccnt[9];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void dfs(int a,int b,int c){
	if(a==n&&c==0){
		if(ccnt[a]==cnt[a]/2)ans++;
		return;
	}
	if(c==0){
		if(ccnt[a+1]>cnt[a+1]/2)return;
		dfs(a+1,a+2,cnt[a+1]/2-ccnt[a+1]);
		return;
	}
	int i;
	for(i=b;i<=n;i++){
		if(vis[a][i]){
			ccnt[a]++;
			ccnt[i]++;
			dfs(a,i+1,c-1);
			ccnt[a]--;
			ccnt[i]--;
		}
	}
}

int main(){
	int T=read();
	while(T--){
		n=read();
		m=read();
		int i;
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		memset(ccnt,0,sizeof(ccnt));
		ans=0;
		for(i=1;i<=m;i++){
			int a=read(),b=read();
			vis[a][b]=vis[b][a]=1;
			cnt[a]++;
			cnt[b]++;
		}
		bool f=1;
		for(i=1;i<=n&&f;i++){
			if(cnt[i]%2)f=0;
		}
		if(!f){
			printf("0\n");
			continue;
		}
		dfs(1,2,cnt[1]/2);
		printf("%d\n",ans);
	}
	return 0;
}
