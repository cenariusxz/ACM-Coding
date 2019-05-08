#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans1 = 0, ans2 = 0;
	for(int a = 1 ; a <= 1000 ; ++ a){
		int tmp1 = 0, tmp0 = 0, tmp = a;
		while(tmp){
			if(tmp&1)tmp1++;
			else tmp0++;
			tmp>>=1;
		}
		if(tmp1>tmp0)ans1++;
		else ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
