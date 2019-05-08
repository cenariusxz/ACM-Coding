#include<stdio.h>
#include<string.h>

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

int a[100005],b[100005];
int ans[100005];
bool vis[100005];
int num[100005];

int main(){
	int T=read();
	while(T--){
		int n=read();
		int i,j;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			a[i]=read();
			b[a[i]]=i;
		}
		int pos1=1,pos2=n;
		int cnt=0;
		while(pos1<=n){
			if(vis[pos1]){
				pos1++;
				continue;
			}
			int x=b[pos1];
			if(x==n){
				int pre=n,maxx=pos1;
				for(i=n-1;i>=1&&!vis[a[i]];i--){
					if(a[i]>maxx){
						maxx=a[i];
						pre=i;
					}
				}
				cnt++;
				for(i=pre;i<=n;i++){
					vis[a[i]]=1;
					num[i]=cnt;
				}
			}
			else if(vis[a[x+1]]){
				if(a[x-1]>a[x]){
					num[x]=++cnt;
				}
				else{
					num[x]=num[x-1];
				}
				vis[pos1]=1;
			}
			else{
				cnt++;
				num[x]=cnt;
				num[x+1]=cnt;
				vis[pos1]=1;
				vis[a[x+1]]=1;
			}
			pos1++;
		}
		pos1=1,pos2=num[1];
		for(i=2;i<=n;i++){
			if(num[i]==pos2){
				ans[a[i-1]]=a[i];
			}
			else{
				ans[a[i-1]]=a[pos1];
				pos1=i;
				pos2=num[i];
			}
		}
		ans[a[n]]=a[pos1];
		for(i=1;i<=n;i++){
			printf("%d",ans[i]);
			if(i==n)printf("\n");
			else printf(" ");

		}
	}
	return 0;
}
