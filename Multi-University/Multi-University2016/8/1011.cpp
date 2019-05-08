#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

char s[maxn];
int num[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int pos1=0,pos2=0;
		bool f=1;
		num[0]=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='('){
				pos1=i;
			}
			else if(pos2==0){
				pos2=i;
			}
			if(s[i]=='('){
				num[i]=num[i-1]+1;
			}
			else num[i]=num[i-1]-1;
			if(num[i]<0)f=0;
		}
		if(num[n]!=0)f=0;
		if(num[n]!=0){
			printf("No\n");
			continue;
		}
		if(n==2&&f==1){
			printf("No\n");
			continue;
		}
		if(f){
			printf("Yes\n");
			continue;
		}
		swap(s[pos1],s[pos2]);
		f=1;
		for(int i=1;i<=n;++i){
			if(s[i]=='(')num[i]=num[i-1]+1;
			else num[i]=num[i-1]-1;
			if(num[i]<0)f=0;
		}
		if(num[n]!=0)f=0;
		if(f)printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
