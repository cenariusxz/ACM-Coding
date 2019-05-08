#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
char s[maxn],t[maxn<<1];
int p[maxn<<1];

void manacher(){
	int len=strlen(s),l=0;
	t[l++]='$';
	t[l++]='#';
	for(int i=0;i<len;++i){
		t[l++]=s[i];
		t[l++]='#';
	}
	t[l]=0;
	int maxx=0,num=0;
	for(int i=0;i<l;++i){
		p[i]=maxx>i?min(p[2*num-i],maxx-i):1;
		while(t[i+p[i]]==t[i-p[i]])p[i]++;
		if(i+p[i]>maxx){
			maxx=i+p[i];
			num=i;
		}
	}
}

int main(){
	int c=0;
	while(scanf("%s",s)!=EOF){
		if(s[0]=='E')break;
		manacher();
		int ans=0;
		int l=strlen(s);
		for(int i=0;i<2*l+2;++i){
			if(p[i]-1>ans)ans=p[i]-1;
		}
		printf("Case %d: %d\n",++c,ans);
	}
	return 0;
}
