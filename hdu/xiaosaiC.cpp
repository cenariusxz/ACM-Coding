#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int j[maxn],b[maxn];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&j[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		sort(j+1,j+n+1);
		sort(b+1,b+m+1);
		int pos=1;
		ll ans=0;
		for(int i=1;i<=n;++i){
			int l=1,r=m;
			bool f=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(b[mid]==j[i]){
					f=1;
					break;
				}
				else if(b[mid]<j[i])l=mid+1;
				else r=mid-1;
			}
			if(f)continue;
			else{
				int mm=0x3f3f3f3f;
				if(l+1<=m&&l+1>=1&&abs(j[i]-b[l+1])<mm)mm=abs(j[i]-b[l+1]);
				if(l<=m&&l>=1&&abs(j[i]-b[l])<mm)mm=abs(j[i]-b[l]);
				if(l-1<=m&&l-1>=1&&abs(j[i]-b[l-1])<mm)mm=abs(j[i]-b[l-1]);
				if(r+1<=m&&r+1>=1&&abs(j[i]-b[r+1])<mm)mm=abs(j[i]-b[r+1]);
				if(r<=m&&r>=1&&abs(j[i]-b[r])<mm)mm=abs(j[i]-b[r]);
				if(r-1<=m&&r-1>=1&&abs(j[i]-b[r-1])<mm)mm=abs(j[i]-b[r-1]);
				ans+=mm;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
