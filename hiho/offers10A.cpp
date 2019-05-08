#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char s[1005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int l=strlen(s);
		int sum=0;
		for(int i=0;i<l;++i)if(s[i]=='A')sum++;
		if(sum>1)printf("NO\n");
		else{
			sum=0;
			for(int i=0;i+2<l;++i){
				if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')sum++;
			}
			if(sum)printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}
