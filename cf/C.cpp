#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
struct point{
	ll v;
	int x,y;
	int num;
	bool operator<(const point a)const{
		return v<a.v;
	}
}p1[2000010],p2[2000010];
int m[2005][2005];

int main(){
	int n,i,j,k;
	ll v;
	scanf("%d",&n);
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	int cnt1=0,cnt2=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i+j)%2){
				++cnt2;
				p2[cnt2].x=i;
				p2[cnt2].y=j;
				p2[cnt2].num=cnt2;
				m[i][j]=cnt2;
			}
			else{
				++cnt1;
				p1[cnt1].x=i;
				p1[cnt1].y=j;
				p1[cnt1].num=cnt1;
				m[i][j]=cnt1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lld",&v);
			if((i+j)%2){
				p2[m[i][j]].v+=v;
				for(k=1;k<=n;k++){
					if(k==j)continue;
					if(i+(j-k)<=n&&i+j-k>=1)p2[m[i+(j-k)][k]].v+=v;
					if(i-(j-k)>=1&&i-(j-k)<=n)p2[m[i-(j-k)][k]].v+=v;
				}
			}
			else{
				p1[m[i][j]].v+=v;
				for(k=1;k<=n;k++){
					if(k==j)continue;
					if(i+(j-k)<=n&&i+j-k>=1)p1[m[i+(j-k)][k]].v+=v;
					if(i-(j-k)>=1&&i-(j-k)<=n)p1[m[i-(j-k)][k]].v+=v;
				}
			}
		}
	}
	sort(p1+1,p1+cnt1+1);
	sort(p2+1,p2+cnt2+1);
	printf("%lld\n%d %d %d %d\n",p1[cnt1].v+p2[cnt2].v,p1[cnt1].x,p1[cnt1].y,p2[cnt2].x,p2[cnt2].y);
}
