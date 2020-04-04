#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
char t[maxn];

int main(){
	scanf("%s", s);
	int len = 0, b = 0, posdot = 1, pose;
	
	// 确定底数指数分割位置 
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == 'e')pose = i;
	}
	
	// 确定有效数位长度、末尾补备用'0' 
	for(int i = 0 ; i < pose ; ++ i){
		if(s[i] != '.')t[++len] = s[i];
	}
	if(t[len] == '0')len --;
	for(int i = len + 1 ; i <= 205 ; ++ i)t[i] = '0';
	
	// 确定指数，移动小数点 
	for(int i = pose+1 ; s[i] ; ++ i){
		b = b * 10 + s[i] - '0';
	}
	posdot += b;
	
	// 输出整数部分 0~pos，不输出前导0，记录输出多少数字，如果未输出数字，则输出一个'0' 
	int cnt = 0;
	for(int i = 1 ; i <= posdot ; ++ i){
		if(t[i] == '0' && cnt == 0)continue;
		cnt++;
		putchar(t[i]);
	}
	if(cnt == 0)putchar('0');
	
	// 输出小数点 如果len>pos输出小数点 
	if(len > posdot)putchar('.');
	
	// 输出小数部分 如果数字len>pos，输出pos+1~len，否则不输出 
	for(int i = posdot + 1 ; i <= len ; ++ i)putchar(t[i]);
	
	putchar('\n'); 
	return 0;
}

