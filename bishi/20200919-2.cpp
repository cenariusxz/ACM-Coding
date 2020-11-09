#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;

string s;
int ed[maxn], nb[maxn];
map<string, int> M;
stack<int> sta;

int solve(int l, int r){
	if(s[l] == '('){
		l ++, r --;
		if(s[l] == 'l'){
			map<string, int> Mtmp = M;
			int ans = 0, st = nb[l];
			while(st < r){
				string v;
				int e, flag, ednow;
				if(s[st+1] == '(')ednow = ed[st+1], flag = 0;	// expr
				else if(s[st+1] >= '0' && s[st+1] <= '9')ednow = nb[st+1] - 1, flag = 0;	// expr
				else ednow = nb[st+1] - 1, flag = 1;	// var
				if(ednow > r)ednow = r;
				if(flag == 0){
					ans = solve(st+1, ednow);
					break;
				}
				v = s.substr(st+1, ednow - st);
				st = ednow + 1;
				if(st >= r){
					ans = M[v];
					break;
				}
				if(s[st+1] == '(')ednow = ed[st+1];
				else ednow = nb[st+1] - 1;
				if(ednow > r)ednow = r;
				e = solve(st+1, ednow);
				M[v] = e;
				st = ednow + 1;
			}
			M = Mtmp;
			return ans;
		}
		else{
			int st = nb[l], ednow = 0, e1 = 0, e2 = 0;
			if(s[st + 1] == '(')ednow = ed[st+1];
			else ednow = nb[st+1]-1;
			if(ednow > r)ednow = r;
			e1 = solve(st+1, ednow);
			st = ednow + 1;
			if(s[st + 1] == '(')ednow = ed[st+1];
			else ednow = nb[st+1]-1;
			if(ednow > r)ednow = r;
			e2 = solve(st+1, ednow);
			st = ednow + 1;
			if(s[l] == 'm')return e1 * e2;
			else return e1 + e2;
		}
	}
	else if(s[l] >= '0' && s[l] <= '9'){
		int res = 0;
		for(int i = l ; i <= r ; ++ i)res = res * 10 + s[l] - '0';
		return res;
	}
	else return M[s.substr(l, r-l+1)];
}

int main(){
	getline(cin, s);
	while(s.find("  ") != s.npos)s.replace(s.find("  "), 2, " ");
	int n = s.length();
	for(int i = 0 ; i < n ; ++ i){
		if(s[i] == '(')sta.push(i);
		if(s[i] == ')'){
			ed[sta.top()] = i;
			sta.pop();
		}
	}
	int bp = n;
	for(int i = n-1 ; i >= 0 ; -- i){
		nb[i] = bp;
		if(s[i] == ' ')bp = i;
	}
	cout << solve(0, n-1) << endl;
	return 0;
}

