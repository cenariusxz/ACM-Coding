#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n, m, res; 

bool check(){
	for(int i = 0 ; i < n ; i += res){
		if(s1.substr(0, res) != s1.substr(i, res))return 0;
	}
	for(int i = 0 ; i < m ; i += res){
		if(s1.substr(0, res) != s2.substr(i, res))return 0;
	}
	return 1;
}

int main(){
	cin >> s1 >> s2;
	n = s1.length(), m = s2.length();
	res = __gcd(n, m);
	if(check())cout << s1.substr(0, res) << endl;
	else cout << "" << endl;
	return 0;
}

