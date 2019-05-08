#include<stdio.h>
#include<string.h>
typedef long long ll;

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

int ans[11][100005];
int cnt[11];
bool vis[41];
int ans2[11][41];
int cnt2[11];

int main(){
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		ll sum=(ll)n*(n+1)/2;
		ll ave=sum/m;
		if(ave*m!=sum||n<2*m-1){printf("NO\n");continue;}
		memset(cnt,0,sizeof(cnt));
		while(n>=2*m&&n>40){
			for(int i=1;i<=m;++i){
				ans[i][++cnt[i]]=n-i+1;
			}
			n-=m;
			for(int i=m,j=1;i>=1;--i,++j){
				ans[j][++cnt[j]]=n-i+1;
			}
			n-=m;
			ave-=ans[1][cnt[1]]+ans[1][cnt[1]-1];
		}
		if((n==23&&m==6)||(n==27&&m==7)||(n==28&&m==7)||(n==31&&m==8)||(n==32&&m==8)||(n==35&&m==9)||(n==36&&m==9)||(n==39&&m==10)||(n==40&&m==10)){
			for(int i=1;i<=m;++i){
				ans[i][++cnt[i]]=n-i+1;
			}
			n-=m;
			for(int i=m,j=1;i>=1;--i,++j){
				ans[j][++cnt[j]]=n-i+1;
			}
			n-=m;
			ave-=ans[1][cnt[1]]+ans[1][cnt[1]-1];
		}
		memset(vis,0,sizeof(vis));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=1;i<=m;++i){
			int ss=ave;
			for(int j=n;j>=1;--j){
				if(!vis[j]&&j<=ss){
					vis[j]=1;
					ss-=j;
					ans2[i][++cnt2[i]]=j;
					if(!ss)break;
				}
			}
		}
		printf("YES\n");
		for(int i=1;i<=m;++i){
			printf("%d ",cnt[i]+cnt2[i]);
			for(int j=1;j<=cnt[i];++j){
				printf("%d ",ans[i][j]);
			}
			for(int j=1;j<=cnt2[i];++j){
				printf("%d",ans2[i][j]);
				if(j==cnt2[i])printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
