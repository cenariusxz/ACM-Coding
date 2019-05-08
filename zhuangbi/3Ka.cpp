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
		int num=0,pos=0,tail=len-1;
		for(pos;pos>=1;pos++){
			if(s[pos]=='*'&&num<2){
				bool f=0,ff=0;
				while(tail>pos){
					if(f){
						if(s[tail]=='1'){
							ff=1;
							break;
						}
						else f=0;
					}
					if(s[tail]=='1'&&!f){
						f=1;
					}
				}
				if(ff){
					ans++;
					s[pos]='1';
					s[tail]='*';
					num++;
				}
				if(num<2){
					ans+=2-num;
					num=1;
				}
			}
			else num++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
