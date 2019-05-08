#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct ti{
	int h,m,num,id;
	bool operator < (const ti a)const{
		if(h==a.h)return m<a.m;
		return h<a.h;
	}
}t[100];

int vis[50][50];
int val[50][50];
int last[50][50];
int n,m,k;
int ans11[100],ans22[100];

void change(int x,int y){
	int cnt=1;
	for(int i=y-1;i>=1;--i){
		if(vis[x][i])return;
		last[x][i]=cnt++;
	}
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		if(n==0&&m==0&&k==0)break;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&val[i][j]);
		}
		for(int i=1;i<=n;++i){
			int num=m;
			for(int j=1;j<=m;++j){
				last[i][j]=num--;
			}
		}
		for(int i=1;i<=k;++i){
			scanf("%d:%d %d",&t[i].h,&t[i].m,&t[i].num);
			t[i].id=i;
		}
		sort(t+1,t+k+1);
		for(int q=1;q<=k;++q){
			int ans1=-1,ans2=-1;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(last[i][j]>=t[q].num){
						if(ans1==-1){ans1=i;ans2=j;}
						else if(val[ans1][ans2]<val[i][j]){
							ans1=i;ans2=j;
						}
					}
				}
			}
			if(ans1==-1){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						if(vis[i][j]==0){
							if(ans1==-1){ans1=i;ans2=j;}
							else if(val[ans1][ans2]<val[i][j]){
								ans1=i;ans2=j;
							}
						}
					}
				}
				if(ans1==-1){
					ans11[t[q].id]=-1;
					ans22[t[q].id]=-1;
				}
				else{
					change(ans1,ans2);
					vis[ans1][ans2]=1;
					last[ans1][ans2]=-1;
					ans11[t[q].id]=ans1;
					ans22[t[q].id]=ans2;
				}
			}
			else{
				for(int i=0;i<t[q].num;++i){
					vis[ans1][ans2+i]=1;
					last[ans1][ans2+i]=-1;
				}
				change(ans1,ans2);
				ans11[t[q].id]=ans1;
				ans22[t[q].id]=ans2;
			}
		/*	for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					printf("%d ",last[i][j]);
				}
				printf("\n");
			}*/
		}
		for(int i=1;i<=k;++i){
			if(ans11[i]==-1)printf("-1\n");
			else printf("%d %d\n",ans11[i],ans22[i]);
		}
	}
	return 0;
}
