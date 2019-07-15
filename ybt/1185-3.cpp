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
set<string>s;
set<string>::iterator it;

int main(){
	while(cin >> t){
		s.insert(t);
	}
	for(it = s.begin() ; it != s.end() ; it ++){
		cout << (*it) << endl;	
	}
	return 0;
}

