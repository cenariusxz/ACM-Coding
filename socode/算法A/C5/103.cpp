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

char s[1005],t[1005],tmp[1005];
int a[1005],b[1005],c[1005];

bool bijiao(char s[], char t[]){	// 返回s是否大于等于t 
	int lens = strlen(s);
	int lent = strlen(t);
	if(lens > lent)return 1;
	if(lens < lent)return 0;
	if(strcmp(s,t) >= 0)return 1;
	return 0;
}

int sub(char s[], char t[]){		// s - t , 返回答案的位数 
	int lena = strlen(s);
	int lenb = strlen(t);
	int lenc = max(lena, lenb);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i = 0 ; s[i] ; ++ i)a[lena - i - 1] = s[i] - '0';
	for(int i = 0 ; t[i] ; ++ i)b[lenb - i - 1] = t[i] - '0';
	for(int i = 0 ; i < lenc ; ++ i){
		c[i] += a[i]-b[i];
		if(c[i] < 0){
			c[i] += 10;
			c[i+1] --;
		}
	}
	while(!c[lenc-1] && lenc > 1)lenc--;
	return lenc;
}

int main(){
	scanf("%s%s",s,t);
	int lenc = 0;
	if(bijiao(s,t))lenc = sub(s,t);
	else lenc = sub(t,s);
	if(!bijiao(s,t))printf("-");
	for(int i = lenc - 1 ; i >= 0 ; -- i)printf("%d",c[i]);
	printf("\n");
	return 0;
}

