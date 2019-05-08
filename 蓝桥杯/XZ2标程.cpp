#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

char s[30],a[maxn],b[maxn],ans[maxn];
int num[30];

int Cmp(int l1,int l2){
	if(l1<l2){
		strcpy(ans,a);
		for(int i=0;i<l2-l1;++i)a[i]=s[0];
		a[l2-l1]=0;
		strcat(a,ans);
		return -1;
	}
	if(l1>l2){
		strcpy(ans,b);
		for(int i=0;i<l1-l2;++i)b[i]=s[0];
		b[l1-l2]=0;
		strcat(b,ans);
		return 1;
	}
	if(strcmp(a,b)==0)return 0;
	for(int i=0;i<l1;++i){
		if(num[a[i]-'a']!=num[b[i]-'a'])return num[a[i]-'a']-num[b[i]-'a'];
	}
}

void Sub(char s1[],char s2[],int l){
	int need=0;
	for(int i=l-1;i>=0;--i){
		int tmp=num[s1[i]-'a']-num[s2[i]-'a']-need;
		if(tmp<0){
			need=1;
			tmp+=26;
		}
		else need=0;
		ans[i]=s[tmp];
	}
	ans[l]=0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s%s",s,a,b);
		for(int i=0;i<26;++i)num[s[i]-'a']=i;
		int f=Cmp(strlen(a),strlen(b));
		if(!f)printf("%c\n",s[0]);
		else{
			if(f<0)Sub(b,a,strlen(a));
			else Sub(a,b,strlen(a));
			f=0;
			for(int i=0;i<strlen(a);++i){
				if(!f&&ans[i]!=s[0])f=1;
				if(f)putchar(ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
