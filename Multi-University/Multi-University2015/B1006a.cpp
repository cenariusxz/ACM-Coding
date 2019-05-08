#include<stdio.h>
#include<string.h>

struct ss{
	int a,b;
}s[30];

int seg[10][30],cnt[10],numm[10][2],ans=0,n,m,cntt[10];
bool vis[30],vis2[30];

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

inline void out(int x){
	if(x>9)out(x/10);
	putchar(x%10+'0');
}

void dfs(int a,int num){
	if(a==n&&num==0){
		bool f=1;
		for(int j=1;j<=n&&f;j++){
			int cc1=0,cc2=0;
			for(int k=1;k<=cnt[j];k++){
				if(vis[seg[j][k]])cc1++;
				else cc2++;
			}
			if(cc1!=cc2)f=0;
		}
		if(f)ans++;
		return;
	}
	if(num==0){
		if(cntt[a+1]<0)return;
		dfs(a+1,cntt[a+1]);
		return;
	}
	int i,j;
	for(i=1;i<=cnt[a];++i){
		if(vis2[seg[a][i]])continue;
		if(s[seg[a][i]].a<a)continue;
		vis2[seg[a][i]]=1;
		vis[seg[a][i]]=1;
		cntt[s[seg[a][i]].a]--;
		cntt[s[seg[a][i]].b]--;
		dfs(a,num-1);
		vis[seg[a][i]]=0;
		vis2[seg[a][i]]=0;
		cntt[s[seg[a][i]].a]++;
		cntt[s[seg[a][i]].b]++;
	}
}

int main(){
	int T=read();
	while(T--){
		n=read();
		m=read();
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		memset(cnt,0,sizeof(cnt));
		int i,j,c=0;
		for(i=1;i<=m;i++){
			int a,b;
			a=read();
			b=read();
			c++;
			if(a>b){
				int t=a;
				a=b;b=t;
			}
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
			cntt[i]=cnt[i]/2;
		}
		if(!f){
			printf("0\n");
			continue;
		}
		ans=0;
		dfs(1,cntt[1]);
		out(ans);
		printf("\n");
	}
	return 0;
}

