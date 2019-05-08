#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char s[1000005],t[1000005];
int s1[50],s2[50];
int ans[50];

int check(){
	for(int i=9;i>=0;--i){
		for(int j=1;j<i;++j){
			if(s1[j]&&s2[i-j]){
				s1[j]--;
				s2[i-j]--;
				return i;
			}
		}
		for(int j=1;j<=9;++j){
			if(s1[j]&&s2[i+10-j]){
				s1[j]--;
				s2[i+10-j]--;
				return i;
			}
		}
	}
}

inline void get(int i,int a,int b){
	int tmp=min(s1[a],s2[b]);
	ans[i]+=tmp;
	s1[a]-=tmp;
	s2[b]-=tmp;
}

void solve(){
	for(int i=9;i>=0;--i){
		for(int j=0;j<=i;++j)get(i,j,i-j);
		for(int j=0;j<=9;++j)get(i,j,i+10-j);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(ans,0,sizeof(ans));
		scanf("%s%s",s,t);
		printf("Case #%d: ",q);
		int len=strlen(s);
		if(len==1){
			int num1=s[0]-'0';
			int num2=t[0]-'0';
			int res=num1+num2%10;
			printf("%d\n",res);
			continue;
		}
		for(int i=0;i<len;++i)s1[s[i]-'0']++;
		for(int i=0;i<len;++i)s2[t[i]-'0']++;
		int num=check();
		if(num==0)printf("0\n");
		else{
			printf("%d",num);
			solve();
			for(int i=9;i>=0;--i){
				for(int j=1;j<=ans[i];++j)printf("%d",i);
			}
			printf("\n");
		}
	}
	return 0;
}
