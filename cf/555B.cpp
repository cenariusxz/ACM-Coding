#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

struct bri{
	ll l;
	int num;
	bool operator < (bri a)const{
		return l<a.l;
	}
}b[200005];

struct pa{
	ll l,r;
	int num;
	bool operator < (pa a)const{
		if(r==a.r)return l<a.l;
		return r<=a.r;
	}
}p[200005];

bool vis[200010];
int ans[200005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	ll pl,pr,l,r;
	scanf("%I64d%I64d",&pl,&pr);
	for(i=2;i<=n;i++){
		scanf("%I64d%I64d",&l,&r);
		p[i-1].num=i-1;
		p[i-1].l=l-pr;
		p[i-1].r=r-pl;
		pl=l;
		pr=r;
	}
	for(i=1;i<=m;i++){
		scanf("%I64d",&b[i].l);
		b[i].num=i;
	}
	if(m<n-1){
		printf("No\n");
		return 0;
	}
	memset(vis,0,sizeof(vis));
	sort(p+1,p+n);
	sort(b+1,b+m+1);
	bool f=1;
	for(i=1;i<n&&f;i++){
		int ll=1,rr=m;
		while(ll<=rr){
			int mid=(ll+((rr-ll)>>1));
			if(b[mid].l==p[i].l){
				ll=mid;
				break;
			}
			else if(b[mid].l<p[i].l){
				ll=mid+1;
			}
			else rr=mid-1;
		}
		while(vis[ll])ll++;
		if(ll>=n||b[ll].l>p[i].r)f=0;
		else{
			ans[p[i].num]=b[ll].num;
			vis[ll]=1;
		}
	}
	if(f){
		printf("Yes\n");
		for(i=1;i<n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	else printf("No\n");
	return 0;
}
