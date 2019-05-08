#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=2e5+5;
char s[maxn],t[maxn<<1];
char res[maxn];
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
	char c[2];
	while(scanf("%s%s",c,s)!=EOF){
		int l=strlen(s);
		for(int i=0;i<l;++i){
			s[i]='a'+(s[i]-c[0]+26)%26;
		}
		manacher();
		int pos=0,ans=0;
		for(int i=1;i<2*l+2;++i){
			if(p[i]-1>ans){
				pos=i;ans=p[i]-1;
			}
		}
		int ans1=0x3f3f3f3f,ans2=0,cnt=0;
		for(int i=pos-p[pos]+1;i<=pos+p[pos]-1;++i){
			if(t[i]!='#'){
				res[cnt++]=t[i];
				if(i<ans1)ans1=i;
				if(i>ans2)ans2=i;
			}
		}
		res[cnt]=0;
		if(p[pos]-1>1){
			printf("%d %d\n",(ans1-2)/2,(ans2-2)/2);
			printf("%s\n",res);
		}
		else printf("No solution!\n");
	}
	return 0;
}
