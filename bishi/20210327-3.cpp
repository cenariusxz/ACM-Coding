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

stack<int> sta;

string solution(string &S){
	while(!sta.empty())sta.pop();
	int n = S.size();
	for(int i = 0 ; i < n ; ++ i){
		int now = 0;
		if(S[i] == 'A') now = 1;
		if(S[i] == 'B') now = -1;
		if(S[i] == 'C') now = 2;
		if(S[i] == 'D') now = -2;
		if(!sta.empty() && sta.top() + now == 0)sta.pop();
		else sta.push(now);
	}
	string res = "";
	while(!sta.empty()){
		char now;
		if(sta.top() == 1) now = 'A';
		if(sta.top() == -1) now = 'B';
		if(sta.top() == 2) now = 'C';
		if(sta.top() == -2) now = 'D';
		res += now;
		sta.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

char now[15] = "ACBDACBD";

int main(){
	string s = string(now);
	printf("%s\n", solution(s).c_str());
	return 0;
}

