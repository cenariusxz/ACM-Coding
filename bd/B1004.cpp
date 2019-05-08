#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[111];
int a[111];
vector<ll> pr;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
void solve(){
	int len=strlen(s);
	int p1=0,p2=0,is=0,mul=1;	//p1:整数，p2:小数，is:小数点分界，mul:记录几位小数
	for(int i=0;i<len;i++){
		if(s[i]!='.'){
			if(is)p2=p2*10+s[i]-'0',mul*=10;
			else p1=p1*10+s[i]-'0';
		}
		else{
			is=1;
		}
	}
	pr.clear();
	int up=p1*mul+p2,down=mul;	//转为分数
	int d=gcd(up,down);
	up/=d;down/=d;
	for(int i=1;i<=9;i++){		//枚举首末位
		for(int j=0;j<=9;j++){
			int cur=i*10+j;		//计算两位数情况
			if(cur%down==0&&cur/down*up==j*10+i){
				pr.push_back(cur);
			}
			int mul=10;
			for(int k=1;k<=8;k++){	//计算三位数到十位数的情况
				mul*=10;
				ll fk1=10ll*up-10ll*down;
				ll fk2=mul*(1ll*j*down-1ll*i*up)+(1ll*i*down-1ll*j*up);
				if(fk2%fk1==0&&fk2/fk1>=0&&fk2/fk1<mul/10){
					pr.push_back(1ll*i*mul+fk2/fk1*10+j);
				}
			}
		}
	}
	if(!pr.size())printf("0\n");
	else{
		printf("%d\n",pr.size());
		sort(pr.begin(),pr.end());
		for(int i=0;i<pr.size();i++)printf("%I64d%c",pr[i],i==pr.size()-1?'\n':' ');
	}
}
int main() {
	int t, cas = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		printf("Case #%d:\n",cas++);
		solve();
	}
	return 0;
}
