#include<stdio.h>
#include<string.h>

char s[1005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int num=0,mul=0;
		int len=strlen(s);
		for(int i=0;i<len;++i){
			if(s[i]=='*')mul++;
			else{
				s[i]='1';
				num++;
			}
		}
		int ans=0;
		int cnt=0;
		if(num<mul+1){
			ans+=mul+1-num;
			cnt=ans;
		}
		int tail=len-1;
		for(int i=0;i<len;++i){
			if(s[i]=='1')cnt++;
			else if(cnt>=2){
				cnt--;
			}
			else{
				for(tail;tail>i;tail--){
					if(s[tail]=='1'){
						s[i]='1';
						s[tail--]='*';
						ans++;
						cnt++;
						break;
					}
				}
			}
		}
//		if(s[len-1]=='1')ans++;
		printf("%d\n",ans);
	}
	return 0;
}
