#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;
const int maxm=2e5+5;
const int INF=0x3f3f3f3f;

char s[maxn];
char t[26];
char a[2],b[2];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<26;++i)t[i]='a'+i;
	while(m--){
		scanf("%s%s",a,b);
		for(int i=0;i<26;++i){
			int t1=t[i];
			if(t1==a[0])t[i]=b[0];
			if(t1==b[0])t[i]=a[0];
		}
	}
	for(int i=0;i<n;++i)putchar(t[s[i]-'a']);
	printf("\n");
	return 0;
}
