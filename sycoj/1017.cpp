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

int main(){
	scanf("%s", s+1);
	int l = strlen(s+1);
	int eq = 1, plus = 1;
	int a = 0, b = 0, num = 0;
	char c;
	s[l+1] = '+';
	for(int i = 1 ; i <= l + 1 ; ++ i){
		if(s[i] >= '0' && s[i] <= '9'){
			num = num * 10 + s[i] - '0';
		}
		else{
			if(s[i] >= 'a' && s[i] <= 'z'){
				if(num == 0)a += eq * plus;
				else a += num * eq * plus;
				c = s[i];
			}
			else b += num * eq * plus;
			num = 0;
		}
		if(s[i] == '+')plus = 1;
		else if(s[i] == '-')plus = -1;
		else if(s[i] == '=')eq = -1, plus = 1;
	}
	printf("%c=%.3lf\n",c,-1.0*b/a+eps);
	return 0;
}


