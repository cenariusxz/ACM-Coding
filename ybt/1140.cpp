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

string s,t;

int main(){
	cin >> s >> t;
	if(t.find(s) != string::npos){
		cout << s + " is substring of "	+ t << endl;
	}
	else if(s.find(t) != string::npos){
		cout << t + " is substring of "	+ s << endl;
	}
	else{
		cout << "No substring" << endl;	
	}
	return 0;
}

