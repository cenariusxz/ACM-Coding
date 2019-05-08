#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int main(){
	int n;
	scanf("%d",&n);
	ll ans=(n-2)*(ll)(n-2);
	printf("%I64d\n",ans);
	return 0;
}
