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

void solve(){

}

int vis[100000];
vector<int>v;

int main(){
	for(int i = 1 ; i <= 30 ; ++ i){
		for(int j = 1 ; j <= 100000 ; ++ j){
			if(vis[j])continue;
			for(int k = 1 ; ; ++ k){
				if(vis[k] || j == k || j == (j ^k) || k == (j ^ k) || vis[j^k] )continue;
				v.PB(j);
				v.PB(k);
				v.PB(j^k);
				vis[j] = 1;
				vis[k] = 1;
				vis[j^k] = 1;
				break;
			}
			break;
		}
	}
	for(int i = 0 ; i < v.size(); ++ i){
		int bit[11];
		int s = v[i];
		for(int j = 10 ; j >= 1 ; -- j){
			bit[j] = s & 1;
			s >>= 1;
		}
		printf("%d ", v[i]);
		//for(int j = 1 ; j <= 10 ; ++ j)printf("%d",bit[j]);
		
		//printf("\n");
		/*for(int j = 1 ; j <= 10 ; j+=2){
			if(bit[j] == 0 && bit[j+1] == 0)putchar('0');
			if(bit[j] == 0 && bit[j+1] == 1)putchar('1');
			if(bit[j] == 1 && bit[j+1] == 0)putchar('2');
			if(bit[j] == 1 && bit[j+1] == 1)putchar('3');
		}*/
		printf("\n");
		//if(i % 3 == 2)printf("\n");
	}
	
	printf("\n");
	return 0;
}


