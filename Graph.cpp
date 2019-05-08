#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int head[maxn],point[maxm],nxt[maxm],size;

void init(){
	memset(head,-1,sizeof(head));
	size = 0;
}

void add(int a, int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

int main(){
	init();

	return 0;
}
