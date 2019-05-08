#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int d[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

//5\6\7  1\2\3\4\5\6

char s1[15],s[15];

int main(){
	int num1;
	int ans=0;
	scanf("%d%s%s",&num1,s1,s);
	if(s[0]=='w'){
		ans=51;
		if(num1==5||num1==6)ans+=2;
		else ans+=1;
	}
	else{
		for(int i=1;i<=12;++i){
			if(num1<=d[i])ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
