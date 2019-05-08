#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

void hanno(int n, char A, char B, char C){
	if(n == 0)return;
	hanno(n-1,A,C,B);
	printf("%c -> %c\n",A,C);
	//  cout<<A<<"->"<<C<<endl;
	hanno(n-1,B,A,C);
}

int main(){
	int n;
	scanf("%d",&n);
	hanno(n,'A','B','C');
	return 0;
}

