#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int vis[105][105];
int num[2][50];
int v[105];
ll a[105];

char s[105],t[105];

void init(){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=100;++i){
		a[i]=a[i-1]*i;
	}
}

int main(){
	init();
	int m,len;
	while(scanf("%d",&m)!=EOF){
		memset(v,0,sizeof(v));
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j)vis[i][j]=1;
		}
		scanf("%s%s",s+1,t+1);
		len=strlen(s+1);
		int n=len/m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int pos1=(i-1)*m+j;
				for(int k=1;k<=m;++k){
					int pos2=(i-1)*m+k;
					if(s[pos1]!=t[pos2])vis[j][k]=0;
				}
			}
		}
	/*	for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j)printf("%d ",vis[i][j]);
			printf("\n");
		}*/
		bool f=1;
		for(int i=1;i<=n;++i){
			memset(num,0,sizeof(num));
			for(int j=1;j<=m;++j){
				int pos=(i-1)*m+j;
				num[0][s[pos]-'a']++;
				num[1][t[pos]-'a']++;
			}
			for(int j='a'-'a';j<='z'-'a';++j){
				if(num[0][j]!=num[1][j])f=0;
			}
		}
		if(!f){
			printf("0\n");
			continue;
		}
		ll ans=1;
		for(int i=1;i<=m;++i){
			int cnt=0;
			f=1;
			for(int j=1;j<=m;++j){
				if(vis[i][j]==1){
					if(v[j])f=0;
					cnt++;
					v[j]=1;
				}
			}
			if(f)ans*=a[cnt];
		}
		ll ans2=1;
		memset(v,0,sizeof(v));
		for(int i=1;i<=m;++i){
			int cnt=0;
			f=1;
			for(int j=1;j<=m;++j){
				if(vis[j][i]==1){
					if(v[j])f=0;
					cnt++;
					v[j]=1;
				}
			}
			if(f)ans2*=a[cnt];
		}
		if(ans==ans2)printf("%lld\n",ans);
		else printf("0\n");
	}
	return 0;
}
