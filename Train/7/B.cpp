#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int len[2][2][105];
// 0 L 1 R

int main(){
	int n,l;
	while(scanf("%d%d",&n,&l)!=EOF){
		if(n==0&&l==0)break;
		memset(len,0,sizeof(len));
		for(int i=1;i<=n;++i){
			int d;
			char s[5];
			scanf("%s%d",s,&d);
			if(s[0]=='L'){
				len[0][0][d]=i;
			}
			else len[0][1][d]=i;
		}
		int t=0;
		int ans=0;
		while(1){
			t++;
			int now=t%2;
			memset(len[now],0,sizeof(len[now]));
			ans=0;
			int pre=now^1;
	/*		for(int i=1;i<l;++i){
				printf("%d ",len[pre][0][i]);
			}
			printf("\n");
			for(int i=1;i<l;++i){
				printf("%d ",len[pre][1][i]);
			}
			printf("\n");
	*/		for(int i=1;i<l;++i){
				if(len[pre][0][i]){
					if(i==1)ans=len[pre][0][i];
					else if(i-2>=1&&len[pre][1][i-2]){
						len[now][1][i-1]=len[pre][0][i];
					}
					else{
						len[now][0][i-1]=len[pre][0][i];
					}
				}
				if(len[pre][1][i]){
					if(i==l-1&&!ans)ans=len[pre][1][i];
					else if(i+2<l&&len[pre][0][i+2]){
						len[now][0][i+1]=len[pre][1][i];
					}
					else{
						len[now][1][i+1]=len[pre][1][i];
					}
				}
			}
	/*		for(int i=1;i<l;++i){
				printf("%d ",len[now][0][i]);
			}
			printf("\n");
			for(int i=1;i<l;++i){
				printf("%d ",len[now][1][i]);
			}
			printf("\n");
	*/		bool f=1;
			for(int i=1;i<l;++i){
				if(len[now][0][i]||len[now][1][i])f=0;
			}
			if(f)break;
		}
		printf("%d %d\n",t,ans);
	}
	return 0;
}
