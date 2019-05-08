#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N,M,T,sum;
int V[2][1010],avg[2];
char g[1010][1010];

int Solve(int id,int top){
	int res = 0x3f3f3f3f;
	for(int i = 1; i <= top; ++i){
		//起点
		int ans = 0,cur = 0,cnt = 0;
		for(int j = i; ; ++j){
			++cnt;
			if(j > top) j = 1;
			cur += V[id][j] - avg[id];
			ans += abs(cur);
			if(cnt == top) break;
		}
		res = min(res,ans);
	}
	return res;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= N; ++i){
			scanf("%s",g[i] + 1);
		}
		memset(V,0,sizeof(V));
		sum = 0;
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= M; ++j){
				if(g[i][j] == '1'){
					sum++;
					V[0][i]++;
					V[1][j]++;
				}
			}
		}
		avg[0] = sum / N;
		avg[1] = sum / M;
		printf("Case %d: ",tt);
		int ans0 = Solve(0,N);
		int ans1 = Solve(1,M);
		if(sum % N == 0 && sum % M == 0){
			printf("both ");
			printf("%d\n",ans0 + ans1);
		}
		else if(sum % N == 0){
			printf("row ");
			printf("%d\n",ans0);
		}
		else if(sum % M == 0){
			printf("column ");
			printf("%d\n",ans1);
		}
		else{
			printf("impossible\n");
		}
	}
	return 0;
}
