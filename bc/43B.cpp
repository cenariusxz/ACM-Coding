#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[100005];

int main(){
	int n,p;
	while(scanf("%d%d",&n,&p)!=EOF){
		map<int,int>m;
		int i;
		for(i=1;i<=n;i++){
			int num;
			scanf("%d",&num);
			a[i]=num%p;
		}
		sort(a+1,a+n+1);
		ll ans=0;
		for(i=1;i<=n;i++){
			int l=1,r=n;
			if(i>1&&a[i]==a[i-1])continue;
			while(l<=r){
				int mid=(l+r)>>1;
				if((ll)a[i]+(ll)a[mid]>=p){
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			if(r==0){
				if(i==n)r=n-1;
				else r=n;
			}
			if(r==i)r--;
			ans=max(ans,((ll)a[i]+(ll)a[r])%p);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
