#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 10000;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

stack<int>s1;
stack<char>s2;

int main(){
	int num = 0;
	bool flag = 0;
	char c;
	while(c=getchar()){
		if(c == '\n')break;
		if(c >= '0' && c <= '9'){
			num = (num * 10 + c - '0') % mod;
			flag = 1;
			continue;
		}
		if(flag){
			s1.push(num);
			num = 0;
		}
		if(c == '+'){
			while(!s2.empty()){
				if(s2.top() == '+'){
					int a = s1.top();s1.pop();
					int b = s1.top();s1.pop();
					s1.push((b+a) % mod);
					s2.pop();
				}
				else if(s2.top() == '*'){
					int a = s1.top();s1.pop();
					int b = s1.top();s1.pop();
					s1.push((b*a) % mod);
					s2.pop();
				}
				else if(s2.top() == '(')break;
			}
			s2.push(c);
		}
		else if(c == '*'){
			while(!s2.empty()){
				if(s2.top() == '*'){
					int a = s1.top();s1.pop();
					int b = s1.top();s1.pop();
					s1.push((b*a) % mod);
					s2.pop();
				}
				else if(s2.top() == '+' || s2.top() == '(')break;
			}
			s2.push(c);
		}
		else if(c == '(')s2.push(c);
		else if(c == ')'){
			while(!s2.empty()){
				if(s2.top() == '+'){
					int a = s1.top();s1.pop();
					int b = s1.top();s1.pop();
					s1.push((b+a) % mod);
					s2.pop();
				}
				else if(s2.top() == '*'){
					int a = s1.top();s1.pop();
					int b = s1.top();s1.pop();
					s1.push((b*a) % mod);
					s2.pop();
				}
				else if(s2.top() == '('){
					s2.pop();
					break;
				}
			}
		}
	}
	if(flag)s1.push(num);
	while(!s2.empty()){
		if(s2.top() == '+'){
			int a = s1.top();s1.pop();
			int b = s1.top();s1.pop();
			s1.push((b+a) % mod);
			s2.pop();
		}
		else if(s2.top() == '*'){
			int a = s1.top();s1.pop();
			int b = s1.top();s1.pop();
			s1.push((b*a) % mod);
			s2.pop();
		}
	}
	printf("%d\n",s1.top());
	return 0;
}
