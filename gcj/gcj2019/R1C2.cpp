#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

vector<int> V[6],res;
int len[6] = {0,23,5,1};
char ans[10];
char s[3];

int main(){
	int T,f;
	scanf("%d%d",&T,&f);
	for(int q = 1 ; q <= T ; ++ q){
		res.clear();
		for(int i = 0 ; i < 119 ; ++ i)res.PB(i);
		int vis[100] = {0};
		int cnt = 0;
		for(int p = 1 ; p <= 3 ; ++ p){
			for(int i = 1 ; i <= 5 ; ++ i)V[i].clear();
			for(int i = 0 ; i < res.size() ; ++ i){
				printf("%d\n",res[i]*5 + p);
				fflush(stdout);
				scanf("%s",s);
				cnt++;
				V[ s[0]- 'A' + 1 ].PB(res[i]);
			}
			for(int i = 'A' ; i <= 'E' ; ++ i){
				if(vis[i])continue;
				if(V[ i - 'A' + 1 ].size() == len[p]){
					res = V[ i-'A'+1 ];
					ans[p] = i;
					vis[i] = 1;
				}
			}
		}
		int stx = res[0]*5+4;
		printf("%d\n",stx);
		fflush(stdout);
		scanf("%s",s);
		cnt++;
		ans[5] = s[0];

		printf("%d\n",stx+1);
		fflush(stdout);
		scanf("%s",s);
		cnt++;
		ans[4] = s[0];

		while(cnt < f){
			printf("%d\n",stx+1);
			fflush(stdout);
			scanf("%s",s);
			cnt++;
		}
		for(int i = 1 ; i <= 5 ;++ i)printf("%c",ans[i]);
		printf("\n");
		fflush(stdout);
		scanf("%s",s);
	}

	return 0;
}
