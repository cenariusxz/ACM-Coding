#include <stdio.h>

int n;
int a[10],b[10];

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

void Solve(int &a,int &b){
	int g = gcd(a,b);
	a /= g;
	b /= g;
}

void Add(int a,int &A,int &B){
	A += a * B;
	Solve(A,B);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		for(int i = 1; i <= n; ++i) scanf("%d",&b[i]);
		int A = b[n],B = a[n];
		Solve(A,B);
		for(int i = n - 1; i >= 1; --i){
			Add(a[i],A,B);
			int t = A;
			A = B;
			B = t;
			A *= b[i];
			Solve(A,B);
		}
		printf("Case #%d: %d %d\n",tt,A,B);
	}
	return 0;
}
