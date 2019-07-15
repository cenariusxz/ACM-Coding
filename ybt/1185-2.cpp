#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

string t;
string s[105];

int main(){
	int n = 0;
	while(cin >> t){
		s[++n] = t;
	}
	for(int i = 1 ; i <= n ; ++ i){
		int id = i;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(s[id] > s[j])id = j;	
		}
		t = s[id];
		s[id] = s[i];
		s[i] = t;
	}
	cout << s[1] << endl;
	for(int i = 2 ; i <= n ; ++ i){
		if(s[i-1] == s[i])continue;
		cout << s[i] << endl;	
	}
	return 0;
}

