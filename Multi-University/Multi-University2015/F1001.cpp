#include<stdio.h>
#include<string.h>
typedef long long ll;

int a[100005],b[100005];
bool vis[100005];

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

int que[100005],cnt;
int ans1[200005],ans2[200005];

int main(){
	int T=read();
	while(T--){
		int n=read();
		int i;
		ll sum=0;
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			a[i]=read();
			b[i]=a[i];
			sum+=a[i];
		}
		ll ave=sum/n;
		if(ave*n!=sum){
			printf("NO\n");
			continue;
		}
		bool f=1;
		for(i=1;i<=n;i++){
			if(a[i]==ave-2||a[i]==ave+2)que[++cnt]=i;
			if(a[i]>ave+2||a[i]<ave-2)f=0;
		}
		if(cnt&&n==2)f=0;
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		int p1=1,p2=2*n;
		int fro=0;
		for(i=1;i<=cnt&&f;i++){
			int u=que[i];
			if(a[u]!=ave-2&&a[u]!=ave+2)continue;
			if(a[u]==ave+2){
				vis[u]=1;
				int j=u+1;
				if(j>n)j-=n;
				if(vis[j]||a[j]>ave){
					f=0;
					break;
				}
				ans1[p1]=u;
				ans2[p1]=j;
				a[j]++;
				a[u]--;
				p1++;
				if(fro==0)fro=j;
				j=u-1;
				if(j<=0)j+=n;
				if(vis[j]||a[j]>ave){
					f=0;
					break;
				}
				ans1[p1]=u;
				ans2[p1]=j;
				a[j]++;
				a[u]--;
				p1++;
			}
			else{
				vis[u]=1;
				int j=u+1;
				if(j>n)j-=n;
				if(vis[j]||a[j]<ave){
					f=0;
					break;
				}
				ans1[p2]=j;
				ans2[p2]=u;
				a[j]--;
				a[u]++;
				p2--;
				if(fro==0)fro=j;
				j=u-1;
				if(j<=0)j+=n;
				if(vis[j]||a[j]<ave){
					f=0;
					break;
				}
				ans1[p2]=j;
				ans2[p2]=u;
				a[j]--;
				a[u]++;
				p2--;
			}
		}
		if(!f){printf("NO\n");continue;}
		if(fro){
			int p;
			int pre=fro;
			int ff=0;
			for(p=0;p<=n&&f;p++){
				i=fro+p;
				if(i>n)i-=n;
				if(ff&&vis[i])f=0;
				if(vis[i])continue;
				if(ff){
					a[pre]-=ff;
					a[i]+=ff;
					if(ff==-1){
						ans1[p2]=i;
						ans2[p2]=pre;
						p2--;
					}
					else{
						ans1[p1]=pre;
						ans2[p1]=i;
						p1++;
					}
				}
				ff=a[i]-ave;
				if(ff>1||ff<-1)f=0;
				vis[pre]=1;
				pre=i;
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(a[i]==ave-1||a[i]==ave+1)fro=i;
				if(a[i]>ave+2||a[i]<ave-2)f=0;
			}
			if(f&&fro){
				int pre=fro;
				int ff=0;
				int p;
				for(p=0;p<=n&&f;p++){
					i=fro+p;
					if(i>n)i-=n;
					if(ff&&vis[i])f=0;
					if(vis[i])continue;
					if(ff){
						a[pre]-=ff;
						a[i]+=ff;
						if(ff==-1){
							ans1[p2]=i;
							ans2[p2]=pre;
							p2--;
						}
						else{
							ans1[p1]=pre;
							ans2[p1]=i;
							p1++;
						}
					}
					ff=a[i]-ave;
					if(ff>1||ff<-1)f=0;
					vis[pre]=1;
					pre=i;
				}
				if(!f){
					p1=1;
					p2=2*n;
					f=1;
					ff=0;
					pre=fro;
					memset(vis,0,sizeof(vis));
					for(p=0;p<=n&&f;p++){
						i=fro-p;
						if(i<=0)i+=n;
						if(ff&&vis[i])f=0;
						if(vis[i])continue;
						if(ff){
							b[pre]-=ff;
							b[i]+=ff;
							if(ff==-1){
								ans1[p2]=i;
								ans2[p2]=pre;
								p2--;
							}
							else{
								ans1[p1]=pre;
								ans2[p1]=i;
								p1++;
							}
						}
						ff=b[i]-ave;
						if(ff>1||ff<-1)f=0;
						vis[pre]=1;
						pre=i;
					}
				}
			}
		}
		if(f){
			printf("YES\n%d\n",p1+(2*n-p2-1));
			for(i=1;i<=2*n;i++){
				if(ans1[i]==0&&ans2[i]==0)continue;
				printf("%d %d\n",ans1[i],ans2[i]);
			}
		}
		else printf("NO\n");
	}
	return 0;
}
