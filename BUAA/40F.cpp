#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=700000;

int s[maxn<<1];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		n*=2;
		for(int i=1;i<=n;++i)scanf("%d",&s[i]);
		int num=0;
		int ans=0;
		for(int i=n;i>=1;--i){
			if(s[i]==6)num++;
			else if(s[i]==1)num--;
			if(num>ans)ans=num;
		}
		printf("%d\n",(ans+1)/2);
	}
	return 0;
}
