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
int preM[maxn],nxtM[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(preM,0,sizeof(preM));
		memset(nxtM,0,sizeof(nxtM));
		preM[1]=-INF;
		nxtM[n+1]=-INF;
		preM[2]=a[2]-a[1];
		if(preM[2]<0)preM[2]=a[1]-a[2];
		for(int i=3;i<=n;++i){
			if(a[i]>a[i-1])preM[i]=a[i]-a[i-1];
			else preM[i]=a[i-1]-a[i];
			if(preM[i-1]>preM[i])preM[i]=preM[i-1];
		}
		nxtM[n]=a[n]-a[n-1];
		if(nxtM[n]<0)nxtM[n]=a[n-1]-a[n];
		for(int i=n-1;i>=2;--i){
			if(a[i]>a[i-1])nxtM[i]=a[i]-a[i-1];
			else nxtM[i]=a[i-1]-a[i];
			if(nxtM[i+1]>nxtM[i])nxtM[i]=nxtM[i+1];
		}
		ll sum=0;
		sum+=nxtM[3];
		sum+=preM[n-1];
		for(int i=2;i<n;++i){
			int M=max(nxtM[i+2],preM[i-1]);
			int b=a[i+1]-a[i-1];
			if(b<0)b=-b;
			M=max(M,b);
			sum+=M;
		}
		printf("%lld\n",sum);
	}	
	return 0;
}
