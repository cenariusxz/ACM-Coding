#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int maxn = 1e5 + 5;

int n;
string str[maxn];
char s[10];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s);
		str[i] = string(s);	
	}
	sort(str+1, str+1+n);
	int cnt = unique(str+1, str+1+n) - (str+1);
	printf("%d\n",cnt);
    return 0;
}
