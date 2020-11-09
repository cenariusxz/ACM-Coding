#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

char s[30][30];
vector< pair<int, int> > ans;
//c1 x hei    x2 o bai
int xx[4] = {0, 1, 1, 1};
int yy[4] = {1, 0, 1, -1};

bool allboard(char c){
	for(int i = 1 ; i <= 25 ; ++ i){
		for(int j = 1 ; j <= 25 ; ++ j){
			for(int k = 0 ; k < 4 ; ++ k){
				int limx = i + 4 * xx[k], limy = j + 4 * yy[k];
				if(limx < 1 || limx > 25 || limy < 1 || limy > 25)continue;
				bool flag = 1;
				for(int t = 0 ; t <= 4 ; ++ t){
					int dx = i + t * xx[k], dy = j + t * yy[k];
					if(s[dx][dy] != c){
						flag = 0;
						break;
					}
				}
				if(flag)return 1;
			}
		}	
	}
	return 0;
}

bool check(int x, int y, char c){
	if(s[x][y] != '.')return 0;
	s[x][y] = c;
	bool flag = allboard(c);
	s[x][y] = '.';
	return flag;
}

void solve(char c){
	for(int i = 1 ; i <= 25 ; ++ i){
		for(int j = 1 ; j <= 25 ; ++ j){
			if(check(i, j, c))ans.PB(MP(i, j));
		}
	}
	if(ans.size() == 0)printf("tie\n");
	else{
		for(int i = 0 ; i < ans.size() ; ++ i){
			printf("%d %d\n", ans[i].first-1, ans[i].second-1);
		}
	}
}

int main(){
	for(int i = 1 ; i <= 25 ; ++ i)scanf("%s", s[i] + 1);
	int c1 = 0, c2 = 0;
	for(int i = 1 ; i <= 25 ; ++ i){
		for(int j = 1 ; j <= 25 ; ++ j){
			if(s[i][j] == 'x')c1 ++;
			if(s[i][j] == 'o')c2 ++;
		}
	}
	if(c1 == c2)solve('x');
	else solve('o');
	return 0;
}

