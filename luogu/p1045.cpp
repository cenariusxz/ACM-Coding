#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

struct Num{
	int d[maxn];
	int len;
	Num(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

Num mulNumEx(Num a,Num b){
	Num ans;
	int len = min(500, a.len+b.len-1);
	for(int i = 0 ; i < a.len ; ++ i){
		for(int j = 0 ; j < b.len ; ++ j){
			if(i+j>500)break;
			ans.d[i+j] += a.d[i] * b.d[j];
			if(ans.d[i+j] >= 10){
				ans.d[i+j+1] += ans.d[i+j]/10;
				ans.d[i+j] %= 10;
			}
		}
	}
	while(len < 500 && ans.d[len])++len;
	ans.len = len;
	return ans;
}

Num QP(Num a,int n){
	Num ans,tmp=a;
	ans.len = 1;
	ans.d[0] = 1;
	while(n){
		if(n&1)ans = mulNumEx(ans,tmp);
		tmp = mulNumEx(tmp,tmp);
		n >>= 1;
	}
	return ans;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",(int)(n*log(2)/log(10))+1);
		Num ans;
		ans.len = 1;
		ans.d[0] = 2;
		ans = QP(ans,n);
		ans.d[0]--;
		int cnt = 0;
		for(int i = 500-1; i >=0; --i){
			printf("%d",ans.d[i]);
			cnt++;
			if(cnt%50 == 0)printf("\n");
		}
	}
	return 0;
}
