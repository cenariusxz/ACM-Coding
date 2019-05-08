#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 110;

int N,M;
int A[MAXN],B[MAXN],P[MAXN];
int p1[MAXN],p2[MAXN];

int Solve(){
	int res = 0;
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1; i <= N; ++i) if(A[i]){
		cnt1++;
		p1[cnt1] = i;
	}
	for(int i = 1; i <= N; ++i) if(B[i]){
		cnt2++;
		p2[cnt2] = i;
	}
	if(cnt1 != cnt2) return 0x3f3f3f3f;
	for(int i = 1; i <= cnt1; ++i){
		int t = p1[i] - p2[i];
		if(t < 0) t = -t;
		res += t;
	}
	return res;
}

int main(){
	while(scanf("%d%d",&N,&M) != EOF){
		for(int i = 1; i <= N; ++i) scanf("%d",A + i);
		for(int i = 1; i <= M; ++i) scanf("%d",P + i);
		// 1
		int cur = 0;
		int sta = 1;
		for(int o = 1; o <= M; ++o){
			for(int i = cur + 1; i <= cur + P[o]; ++i){
				B[i] = sta;
			}
			cur += P[o];
			sta ^= 1;
		}
		int ans = Solve();
		cur = 0;
		sta = 0;
		for(int o = 1; o <= M; ++o){
			for(int i = cur + 1; i <= cur + P[o]; ++i){
				B[i] = sta;
			}
			cur += P[o];
			sta ^= 1;
		}
		ans = min(ans,Solve());
		printf("%d\n",ans);
	}
	return 0;
}
