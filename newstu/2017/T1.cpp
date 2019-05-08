#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
const int maxm = 2e4 + 5;

int a[maxn],l[maxm],r[maxm],n,m,cnt;
ll sum[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	while(m--){
		int type,ql,qr;
		scanf("%d%d%d",&type,&ql,&qr);
		if(type == 1){
			cnt++;
			l[cnt] = ql,r[cnt] = qr;
		}
		else{
			ll ans = sum[qr] - sum[ql-1];
			for(int i = 1 ; i <= cnt ; ++ i){
				if(l[i] <= ql && r[i] >= ql)ans += min(qr,r[i]) - ql + 1;
				else if(l[i] <= qr)ans += min(qr,r[i]) - l[i] + 1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
