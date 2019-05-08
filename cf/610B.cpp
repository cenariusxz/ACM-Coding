#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;

int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int minn=INF;
	int pre=0;
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(a[i]<minn){
			minn=a[i];
			pre=i;
		}
	}
	int cnt=0;
	int maxx=0;
	for(int i=(pre+1)%n;i!=pre;i=(i+1)%n){
		if(a[i]==minn){
			if(cnt>maxx)maxx=cnt;
			cnt=0;
		}
		else cnt++;
	}
	if(cnt>maxx)maxx=cnt;
	printf("%I64d\n",minn*(ll)n+maxx);
	return 0;
}
