#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 5e3 + 5;

char s[maxn];
int dp[maxn][maxn];
int len,k;
map<string,int>M;
map<string,int>::iterator it;

int main(){
	scanf("%s%d",s+1,&k);
	string ss(s+1);
	ss = "0" + ss;
	len = strlen(s + 1);
	for(int l = 1 ; l <= len ; ++ l){
		for(int i = 1 ; i <= len ; ++ i){
			int j = i + l - 1;
			if(j > len)break;
			if(s[i] != s[j])continue;
			if(l >= 6 && !dp[i+2][j-2])continue;
			dp[i][j] = 1;
			M[ss.substr(i,l)]++;
		}
	}
	for(it = M.begin() ; it != M.end() ; ++ it){
		if((*it).second >= k){
			printf("%s\n",(*it).first.c_str());
			break;
		}
		else k -= (*it).second;
	}
	return 0;
}
