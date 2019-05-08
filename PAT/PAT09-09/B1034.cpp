#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

char s1[50],s2[50];

ll gcd(ll a, ll b){
	return b ? gcd( b, a % b ) : a;
}

void print(int d, ll a, ll b){
	if(a == 0)printf("0");
	else{
		ll g = gcd(a, b);
		a /= g;
		b /= g;
		if(d == -1)printf("(-");
		if(a % b == 0)printf("%lld",a/b);
		else{
			if(a > b)printf("%lld %lld/%lld",a/b,a%b,b);
			else printf("%lld/%lld",a,b);
		}
		if(d == -1)printf(")");
	}
}

int main(){
	int d1 = 1, d2 = 1;
	int a1, b1, a2, b2;
	scanf("%d/%d%d/%d",&a1,&b1,&a2,&b2);
	if(a1 < 0)d1 = -1, a1 = -a1;
	if(a2 < 0)d2 = -1, a2 = -a2;
//	if(b1 >= 100000 || b2 >= 100000
//			|| a1 >= 100000 || a2 >= 100000)while(1);

	int signal;
	ll ans;

	print(d1, a1, b1);
	printf(" + ");
	print(d2, a2, b2);
	printf(" = ");
	ans = d1*a1*(ll)b2 + d2*a2*(ll)b1;
	if(ans < 0){
		signal = -1;
		ans = -ans;
	}
	else signal = 1;
	print(signal,ans,b1*(ll)b2);
	printf("\n");

	print(d1, a1, b1);
	printf(" - ");
	print(d2, a2, b2);
	printf(" = ");
	ans = d1*a1*(ll)b2 - d2*a2*(ll)b1;
	if(ans < 0){
		signal = -1;
		ans = -ans;
	}
	else signal = 1;
	print(signal,ans,b1*(ll)b2);
	printf("\n");

	print(d1, a1, b1);
	printf(" * ");
	print(d2, a2, b2);
	printf(" = ");
	ans = a1*(ll)a2;
	print(d1*d2,ans,b1*(ll)b2);
	printf("\n");

	print(d1, a1, b1);
	printf(" / ");
	print(d2, a2, b2);
	printf(" = ");
	if(a2 == 0)printf("Inf");
	else{
		ans = a1*(ll)b2;
		print(d1*d2,ans,b1*(ll)a2);
	}
	printf("\n");

	return 0;
}
