#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char s[10005];
int k;



int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s",s+1);
		scanf("%d",&k);
		int n = strlen( s + 1 );
		int ans=0;
		for(int i=1;i+k-1<=n;++i){
			if(s[i]=='-'){
				ans++;
				for(int j=1;j<=k;++j){
					if(s[i+j-1]=='-')s[i+j-1]='+';
					else s[i+j-1]='-';
				}
			}
		}
		bool f=1;
		for(int i=1;i<=n;++i){
			if(s[i]=='-')f=0;
		}
		printf("Case #%d: ",q);
		if(f)printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
