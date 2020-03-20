#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int pos[3][maxn];

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	int cnt = 0;
	for(int i = 1 ; i <= q ; ++ i){
		int r,c;
		scanf("%d%d",&r,&c);
		if(pos[r][c] == 0){
			pos[r][c] = 1;
			if(pos[3-r][c-1])cnt++;
			if(pos[3-r][c])cnt++;
			if(pos[3-r][c+1])cnt++;
		}
		else{
			pos[r][c] = 0;
			if(pos[3-r][c-1])cnt--;
			if(pos[3-r][c])cnt--;
			if(pos[3-r][c+1])cnt--;
		}
		if(cnt)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

