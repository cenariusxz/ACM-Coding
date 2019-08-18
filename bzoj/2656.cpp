#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1005 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
int a[maxn],lena,b[maxn],lenb,p[maxn],lenp;

int add(int a[],int lena,int b[],int lenb){
	// a += b;
	lena = max(lena, lenb);
	for(int i = 0 ; i < lena ; ++ i){
		a[i] += b[i];
		a[i+1] += a[i]/10;
		a[i] %= 10;
	}
	if(a[lena])lena++;
	return lena;
}

int div(int a[],int lena){
	// a /= 2;
	for(int i = lena - 1 ; i >= 0 ; -- i){
		if(i > 0)a[i-1] += (a[i]&1)*10;
		a[i] >>= 1;
	}
	if(a[lena-1] == 0)lena--;
	return lena;
}

void solve(){
	memset(p,0,sizeof(p));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	lenp = strlen(s);
	for(int i = 0 ; i < lenp ; ++ i)p[i] = s[lenp - i - 1] - '0';
	a[0] = 1; lena = 1;
	b[0] = 0; lenb = 1;
	while(1){
		// pp();
		if(lenp == 1 && p[0] == 1){
			lena = add(a,lena,b,lenb);
			for(int i = lena - 1 ; i >= 0 ; -- i)putchar(a[i] + '0');
			putchar('\n');
			return;
		}
		if(p[0] & 1)lenb = add(b,lenb,a,lena);
		else lena = add(a,lena,b,lenb);	
		lenp = div(p,lenp);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int lens = strlen(s);
		if(lens == 1 && s[0] == '0')printf("0\n");
		else if(lens == 1 && s[0] == '1')printf("1\n");
		else if(lens == 1 && s[0] == '2')printf("1\n");
		else solve();
	}
	return 0;
}

