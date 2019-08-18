#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int maxn = 1e5 + 5;

int n;
string str;
char s[10];
set<string> Set;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s);
		str = string(s);
		Set.insert(str);	
	}
	printf("%d\n",Set.size());
    return 0;
}
