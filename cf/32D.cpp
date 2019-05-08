#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[305][305];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int i;
	for(i=1;i<=n;i++)scanf("%s",s[i]+1);
	int d=3;
	int prex=1,prey=0;
	int lim=min(n,m);
	while(k){
		prey++;
		if(prey==m-d+2){
			prex++;
			prey=1;
		}
		if(prex==n-d+2){
			prex=1;
			prey=1;
			d+=2;
		}
		if(d>lim){
			printf("-1\n");
			return 0;
		}
		if(s[prex][prey+d/2]=='*' && s[prex+d/2][prey]=='*' && s[prex+d/2][prey+d/2]=='*' && s[prex+d/2][prey+d-1]=='*' && s[prex+d-1][prey+d/2]=='*' )k--;
	}
	printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",prex+d/2,prey+d/2,prex,prey+d/2,prex+d-1,prey+d/2,prex+d/2,prey,prex+d/2,prey+d-1);
	return 0;
}
