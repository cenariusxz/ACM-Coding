#include<stdio.h>
#include<string.h>
#include<bitset>
using namespace std;

const int maxn=5e6+5;
const int maxm=1e3+5;

char s[maxn];
bitset<maxm>B[10],D;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=9;++i)B[i].reset();
		D.reset();
		for(int i=0;i<n;++i){
			int cnt,a;
			scanf("%d",&cnt);
			for(int k=1;k<=cnt;++k){
				scanf("%d",&a);
				B[a][i]=1;
			}
		}
		scanf("%s",s);
		int m=strlen(s);
		for(int i=0;i<m;++i){
			D=D<<1;
			D[0]=1;
			D=D&B[s[i]-'0'];
			if(D[n-1]){
				char c=s[i+1];
				s[i+1]=0;
				printf("%s\n",s+i-n+1);
				s[i+1]=c;
			}
		}
	}
	return 0;
}
