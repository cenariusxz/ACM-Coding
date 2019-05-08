#include<stdio.h>
#include<string.h>

int num[15]={0,0,1,3,6,8,11,14,17,20,23,26};
char s[15];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		int l=strlen(s);
		int cnt=0;
		for(int i=0;i<l;++i)if(s[i]=='1')cnt++;
		int ans=num[cnt];
		for(int i=1;i<l;++i){
			if(s[i]=='1'&&s[i-1]=='1')ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
