#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=5e5+5;
char s[maxn],t[maxn<<1];
int p[maxn<<1];
int a[maxn],v[26];

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
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<26;++i)scanf("%d",&v[i]);
		scanf("%s",s);
		int l=strlen(s);
		a[0]=v[s[0]-'a'];
		for(int i=1;i<l;++i){
			a[i]=a[i-1]+v[s[i]-'a'];
		}
		manacher();
		int ans=0;
		for(int i=0;i<l-1;++i){
			int tmp=0;
			int num=p[i+2]-1;
			if(num==i+1)tmp+=a[i];
			num=p[i+l+2]-1;
			if(num==l-i-1)tmp+=a[l-1]-a[i];
			if(tmp>ans)ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
