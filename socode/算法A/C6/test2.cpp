#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int cnt[1005];

int main(){
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	int anslen=214748005;
	int ansl,ansr;
	int num=0;
	int pos=0;
	for(int i=1;i<=n;++i){
		while(num<k&&pos+1<=n){
			pos++;
			cnt[s[pos]]++;
			if(cnt[s[pos]]==1){
				num++;
			}
		}
		if(num==k){
			if(pos-i+1<=anslen){
				anslen=pos-i+1;
				ansl=i;ansr=pos;
			}
		}
		cnt[s[i]]--;
		if(cnt[s[i]]==0){
			num--;
		}
	}
	if(anslen==214748005){
		printf("-1\n");
	}
	else{
		for(int i=ansl;i<=ansr;++i){
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}

