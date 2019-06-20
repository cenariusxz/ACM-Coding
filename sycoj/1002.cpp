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

int main(){
	scanf("%s",str);
	for(int i = 0 ; str[i] ; ++ i){
		if(str[i] == '(')s.push(0);
		if(str[i] == '[')s.push(1);
		if(str[i] == ')'){
			if(s.empty() || s.top() == 1){
				printf("Wrong\n");
				return 0;
			}
			s.pop();
		}
		if(str[i] == ']'){
			if(s.empty() || s.top() == 0){
				printf("Wrong\n");
				return 0;
			}
			s.pop();
		}
	}
	if(!s.empty())printf("Wrong\n");
	else printf("OK\n");
	return 0;
}


