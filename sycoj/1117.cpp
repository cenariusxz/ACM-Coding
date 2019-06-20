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
char c;

int main(){
	int num = 0;
	while(1){
		c = getchar();
		if(c == '@')break;
		else if(c == '+'){
			int a = s.top();s.pop();
			int b = s.top();s.pop();
			s.push(b+a);
		}
		else if(c == '-'){
			int a = s.top();s.pop();
			int b = s.top();s.pop();
			s.push(b-a);
		}
		else if(c == '*'){
			int a = s.top();s.pop();
			int b = s.top();s.pop();
			s.push(b*a);
		}
		else if(c == '/'){
			int a = s.top();s.pop();
			int b = s.top();s.pop();
			s.push(b/a);
		}
		else if(c == ' '){
			s.push(num);
			num = 0;
		}
		else num = num * 10 + c - '0';
	}
	printf("%d\n",s.top());
	return 0;
}


