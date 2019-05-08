#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll m[2005][2005];
struct row{
	int num;
	ll v;
	bool operator<(const row a)const{
		return v<a.v;
	}
}a[4005];
struct col{
	int num;
	ll v;
	bool operator<(const col a)const{
		return v<a.v;
	}
}b[4005];

int x[4005],y[4005];

int main(){
	int n,i,j;
	ll v;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=1;i<=2*n-1;i++){
		a[i].num=b[i].num=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lld",&v);
			m[i][j]=v;
			a[n-i+j].v+=v;
			b[i+j-1].v+=v;
		}
	}
	ll ans1=-1,ans2=-1;
	int x1,y1,x2,y2;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i+j)%2){
				if(a[n-i+j].v+b[i+j-1].v-m[i][j]>ans1){
					ans1=a[n-i+j].v+b[i+j-1].v-m[i][j];
					x1=i;y1=j;
				}
			}
			else{
				if(a[n-i+j].v+b[i+j-1].v-m[i][j]>ans2){
					ans2=a[n-i+j].v+b[i+j-1].v-m[i][j];
					x2=i;y2=j;
				}
			}
		}
	}
	printf("%lld\n%d %d %d %d\n",ans1+ans2,x1,y1,x2,y2);
}
