#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int maxn=1050000;

struct rect{
	int x1,y1,x2,y2;
}r[25];

ll area[maxn];
short l[maxn],r[maxn],u[maxn],d[maxn];
int query[25];

int main(){
	int n,m,c=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		for(int i=1;i<=n;++i)scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
		for(int i=1;i<(1<<n);++i){
			int bit=0;
			area[i]=0;
			int maxl=-INF,minr=INF,maxd=-INF,minu=INF;
			for(int j=1;j<=n;++j){
				if(i&(1<<(j-1))){
					bit++;
					if(r[j].x1>maxl)maxl=r[j].x1;
					if(r[j].x2<minr)minr=r[j].x2;
					if(r[j].y1>maxd)maxd=r[j].y1;
					if(r[j].y2<minu)minu=r[j].y2;
				}
			}
			if(maxl>=minr||maxd>=minu)continue;
			if(bit%2)area[i]+=(minr-maxl)*(ll)(minu-maxd);
			else area[i]-=(minr-maxl)*(ll)(minu-maxd);
		}

		printf("Case %d:\n",++c);
		for(int q=1;q<=m;++q){
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;++i)scanf("%d",&query[i]);
			ll ans=0;
			for(int i=1;i<(1<<k);++i){
				int pos=0;
				for(int j=1;j<=k;++j){
					if(i&(1<<(j-1))){
						pos+=1<<(query[j]-1);
					}
				}
				ans+=area[pos];
			}
			printf("Query %d: %lld\n",q,ans);
		}
		printf("\n");
	}
	return 0;
}
