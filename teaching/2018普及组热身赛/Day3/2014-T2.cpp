#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,l;
	scanf("%d%d%d",&a,&b,&l);
	int a1,b1;
	double Min=1e60;
	for(int aa = 1 ; aa <= l ; ++ aa){
		for(int bb = 1 ; bb <= l ; ++ bb){
			if(__gcd(aa,bb)!=1)continue;
			if(aa*b<a*bb)continue;
			double tmp = aa*1.0/bb-a*1.0/b;
			if(tmp<Min){
				Min = tmp;
				a1 = aa;
				b1 = bb;
			}
		}
	}
	printf("%d %d\n",a1,b1);
	return 0;
}
