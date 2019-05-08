#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;

char s[50][50];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;++i){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=r;++i){
			int cnt=0;
			char tmp;
			for(int j=1;j<=c;++j){
				if(s[i][j]=='?'&&cnt){
					s[i][j]=tmp;
				}
				else if(s[i][j]!='?'){
					if(cnt){
						tmp=s[i][j];
						cnt++;
					}
					else{
						tmp=s[i][j];
						cnt++;
						for(int k=1;k<j;++k)s[i][k]=tmp;
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=r;++i){
			if(s[i][1]=='?'&&cnt){
				strcpy(s[i]+1,s[i-1]+1);
			}
			else if(cnt==0&&s[i][1]!='?'){
				cnt++;
				for(int j=1;j<i;++j){
					strcpy(s[j]+1,s[i]+1);
				}
			}
		}
		printf("Case #%d:\n",t);
		for(int i=1;i<=r;++i)printf("%s\n",s[i]+1);
	}
	return 0;
}
