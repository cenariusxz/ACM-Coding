#include<stdio.h>
#include<string.h>

struct ss{
	int a,b;
}s[30];

int seg[10][30],cnt[10],numm[10][2],ans=0,n,m;
bool vis[30];

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void dfs(int a,int num){
	if(num==0){
		bool f=1;
		for(int j=1;j<=n&&f;j++){
			if(numm[j][1]!=numm[j][0])f=0;
		}
		if(f)ans++;
		return;
	}
	if(m-a+1<num)return;
	int i,j;
	for(i=a;i<=m;i++){
		if(vis[i])continue;
		vis[i]=1;
		numm[s[i].a][1]++;
		numm[s[i].a][0]--;
		numm[s[i].b][1]++;
		numm[s[i].b][0]--;
		dfs(i+1,num-1);
		vis[i]=0;
		numm[s[i].a][1]--;
		numm[s[i].a][0]++;
		numm[s[i].b][1]--;
		numm[s[i].b][0]++;
	}
}

inline void out(int x){
	if(x>9)out(x/10);
	putchar(x%10+'0');
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		n=read();
		m=read();
		int i,j,c=0;
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		memset(numm,0,sizeof(numm));
		for(i=1;i<=m;i++){
			int a,b;
			a=read();
			b=read();
			c++;
			s[c].a=a;
			s[c].b=b;
			seg[a][++cnt[a]]=c;
			seg[b][++cnt[b]]=c;
		}
		if(m==0){
			printf("1\n");
			continue;
		}
		bool f=1;
		for(i=1;i<=n&&f;i++){
			if(cnt[i]%2)f=0;
			numm[i][0]=cnt[i];
		}
		if(!f){
			printf("0\n");
			continue;
		}
		vis[1]=1;
		numm[s[1].a][1]++;
		numm[s[1].a][0]--;
		numm[s[1].b][1]++;
		numm[s[1].b][0]--;
		ans=0;
		dfs(2,m/2-1);
		out(ans*2);
		printf("\n");
	}
	return 0;
}
