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
		int ans=0;
		int len=strlen(s);
		bool f=0;
		for(int i=0;i<len;++i){
			if(s[i]=='*')f=1;
			else s[i]='1';
		}
		if(!f){
			printf("0\n");
			continue;
		}
		if(s[len-1]=='1'){
			for(int i=0;i<len;++i){
				if(s[i]=='*'){
					s[i]='1';
					s[len-1]='*';
					ans++;
					break;
				}
			}
		}
		int numl=0,numr=0,pos=0;
		if(s[0]=='*'){
			int mul=0;
			while(pos<len&&s[pos]=='*'){
				mul++;
				pos++;
			}
			ans+=mul+1;
			numl=numr=1;
		}
		while(pos<len){
			int num=0,mul=0;
			while(pos<len&&s[pos]=='1'){
				num++;
				pos++;
			}
			numl++;
			numr+=num;
			while(pos<len&&s[pos]=='*'){
				mul++;
				pos++;
			}
			if(mul<=numr-1){
				numr-=mul;
				numl-=mul;
				if(numl<=0)numl=1;
			}
			else{
				ans+=mul+1-numr;
				numr=1;
				numl=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
