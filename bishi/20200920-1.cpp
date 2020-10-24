#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e6 + 5;

string t;
int p[maxm];

int main(){
    cin >> t;
    int m = t.length(), i, j;
    p[0] = p[1] = 0;
    for(i = 1 ; i < m ; ++ i){
        j = p[i];
        while(j && t[i] != t[j])j = p[j];
        p[i+1] = t[i] == t[j] ? j+1 : 0;
    }
    int tmp = m, ans = m;
	while(p[tmp]){
		if(m % (m - p[tmp]) == 0)ans = min(ans, m - p[tmp]);
		tmp = p[tmp];
	}
    cout << t.substr(0, ans) << endl;
    return 0;
}
