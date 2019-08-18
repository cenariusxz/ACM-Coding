#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int maxn = 1e5 + 5;

int n;
string str;
char s[10];
map<string,bool>vis;

int main(){
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s);
		str = string(s);
		if(vis[str] == 0){
			ans ++;
			vis[str] = 1;	
		}
	}
	printf("%d\n",ans);
    return 0;
}
