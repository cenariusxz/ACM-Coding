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

stack<int>s;
char str[maxn];
int n;

void solve(){
	scanf("%s",str);
	while(!s.empty())s.pop();
	int id;
	for(int i = 0 ; str[i] ; ++ i){
		if(str[i] == '<' || str[i] == '>')id = 0;
		if(str[i] == '(' || str[i] == ')')id = 1;
		if(str[i] == '[' || str[i] == ']')id = 2;
		if(str[i] == '{' || str[i] == '}')id = 3;
		if(str[i] == '<' || str[i] == '(' || str[i] == '[' || str[i] == '{'){
			if(!s.empty() && s.top() < id){
				printf("NO\n");
				return;
			}
			s.push(id);
		}
		else{
			if(s.empty() || s.top() != id){
				printf("NO\n");
				return;
			}
			s.pop();
		}
	}
	if(s.empty())printf("YES\n");
	else printf("NO\n");
}

int main(){
	scanf("%d",&n);
	while(n--)solve();
	return 0;
}


