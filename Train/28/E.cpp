#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair

char s[6][6];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int id[6][6];
int x[20],y[20];
int ans=0;
//ll pp[20];
map<ll,pii>M;

pii dfs(ll s){
//	printf("%lld\n",s);
//	printf("aaa\n");
	if(M.find(s)!=M.end())return M[s];
//	printf("bbb\n");
	char sta[20];
	ll tmp=s;
	int f=0,step=0;
	for(int i=15;i>=0;--i){
		sta[i]=tmp%3;
		tmp/=3;
	}
	int vis[20]={0};
	for(int i=0;i<16;++i){
		if(!vis[i]&&sta[i]){
	//		printf("i: %d\n",i);
			ll sub=0;
			int que[20],cnt=0,col=sta[i];
			vis[i]=1;sta[i]=0;
			que[++cnt]=i;
			while(cnt){
				int u=que[cnt];
				cnt--;
				for(int k=0;k<4;++k){
					int dx=x[u]+xx[k],dy=y[u]+yy[k];
					if(dx>=1&&dx<=4&&dy>=1&&dy<=4){
						int tid=id[dx][dy];
						if(!vis[tid]&&sta[tid]==col){
							vis[tid]=1;sta[tid]=0;
							que[++cnt]=tid;
						}
					}
				}
			}
	//		for(int j=0;j<=15;++j)printf("%d ",sta[j]);
	//		printf("\n");
	//		scanf("%d",&f);
			int sum=0;
			for(int j=12;j<=15;++j){
				int pos=j+4;
				for(int k=j;k>=0;k-=4){
					if(sta[k]){
						sum++;
						sta[pos-4]=sta[k];
						pos-=4;
						if(k!=pos)sta[k]=0;
					}
				}
			}
			for(int j=0;j<16;++j){
				tmp=tmp*3+sta[j];
			}
	//		for(int j=0;j<=15;++j)printf("%d ",sta[j]);
	//		printf("\n");
	//		scanf("%d",&f);

//			if(!f&&sum<=step){
//				tmp=s;
//				for(int j=15;j>=0;--j){
//					sta[j]=tmp%3;
//					tmp/=3;
//				}
//				continue;
//			}
			if(f&&sum>=step){
				tmp=s;
				for(int j=15;j>=0;--j){
					sta[j]=tmp%3;
					tmp/=3;
				}
				continue;
			}
			pii u=dfs(tmp);
			if(!f){
				if(u.first==1)step=max(step,u.second);
				else f=1,step=u.second;
			}
			else{
			tmp=s;
			for(int j=15;j>=0;--j){
				sta[j]=tmp%3;
				tmp/=3;
			}
				if(u.first==0)step=min(step,u.second);
			}
			tmp=s;
			for(int j=15;j>=0;--j){
				sta[j]=tmp%3;
				tmp/=3;
			}
		}
	}
	return mp(f,step+1);
}

int main(){
	int cnt=0;
	for(int i=1;i<=4;++i){
		for(int j=1;j<=4;++j){
			id[i][j]=cnt;
			x[cnt]=i,y[cnt]=j;
			cnt++;
		}
	}
	M[0]=mp(0,0);
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		ll sta=0;
		for(int i=1;i<=4;++i){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=4;++i){
			for(int j=1;j<=4;++j){
				if(s[i][j]=='B'){
					s[i][j]=1;
				}
				else s[i][j]=2;
			}
		}
		if(s[1][1]==2){
			for(int i=1;i<=4;++i){
				for(int j=1;j<=4;++j){
					s[i][j]=3-s[i][j];
				}
			}
		}
		for(int i=1;i<=4;++i){
			for(int j=1;j<=4;++j){
				sta=sta*3+s[i][j];
			}
		}
		pii u=dfs(sta);
		printf("Case %d: ",q);
		if(u.first==1)printf("win ");
		else printf("loss ");
		printf("%d\n",u.second);
	}
	return 0;
}
