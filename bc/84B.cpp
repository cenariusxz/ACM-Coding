#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int a[maxn];
int num[maxn];
int dp[maxn];
int res[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=0;
		dp[++ans]=a[1];
		res[1]=ans;
		for(int i=2;i<=n;++i){
			int low,high,mid;
			low=1;high=ans;
			int r=1;
			while(low<=high){
				mid=(low+high)/2;
				if(dp[mid]<a[i]){
					low=mid+1;
					if(low>r)r=low;
				}
				else high=mid-1;
			}
			dp[r]=a[i];
			if(r>ans)ans++;
			res[i]=r;
		}
		for(int i=1;i<=n;++i){
			printf("%d",res[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
