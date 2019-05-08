#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

struct seg{
	int x,y;
	bool operator < (const seg a)const{
		if(x==0)return 1;
		if(a.x==0)return 0;
		return y*a.x>x*a.y;
	}
}a[55];

map<int,int>M[55];
map<int,int>::iterator it;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,K;
		scanf("%d%d",&n,&K);
		for(int j=0;j<=n;++j)M[j].clear();
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1);
		M[0][0]=0;
		M[1][a[1].y]=a[1].x*a[1].y;
		for(int i=1;i<n;++i){
			int stx=max(0,K+i-n),lim=min(i,K-1);
			for(int j=lim;j>=stx;--j){
				int ma=-1;
				for(it=M[j].end(),it--;;it--){
					if((*it).second>ma){
						ma=(*it).second;
						int k=(*it).first;
						M[j+1][k+a[i+1].y]=max(M[j+1][k+a[i+1].y],ma+k*a[i+1].x*2+a[i+1].x*a[i+1].y);
					}
					if(it==M[j].begin())break;
				}
			}
		}
		int ans=0;
		for(it=M[K].begin();it!=M[K].end();it++){
			ans=max(ans,(*it).second);
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
