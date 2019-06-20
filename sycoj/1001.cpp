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

char s[maxn];
int top = 0, st[maxm];
void push(int x){
	st[top++] = x;
}
int pop(){
	top--;
	return st[top];
}
int size(){
	return top;
}
int clear(){
	top = 0;
}

int main(){
	scanf("%s",s);
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == '(')push(1);
		if(s[i] == ')'){
			if(size() == 0){
				printf("NO\n");
				return 0;
			}
			pop();
		}
	}
	if(size())printf("NO\n");
	else printf("YES\n");
	return 0;
}


