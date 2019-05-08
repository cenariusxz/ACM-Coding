#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,k,cnt = 0;
	scanf("%d%d",&m,&k);
	if(m%19){
		printf("NO\n");
		return 0;
	}
	while(m){
		if(m%10 == 3)cnt++;
		m/=10;
	}
	if(cnt == k)printf("YES\n");
	else printf("NO\n");
	return 0;
}
