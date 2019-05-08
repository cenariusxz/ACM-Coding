#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
char s[maxn<<1],ss[maxn<<1];
char tmp[maxn];
int p[maxn<<1];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int KMP(char s[],char t[]){
	int i,j,ans=0;    //ans记录字符串出现次数
	int n=strlen(s),m=strlen(t);    //在题目中遇到过，其实strlen很慢，所以如果不先存起来可能有TLE的风险
	p[0]=p[1]=0;    //初始化自匹配数组
	for(i=1;i<m;i++){    //自匹配
		j=p[i];
		while(j&&t[i]!=t[j])j=p[j];
		p[i+1]=t[i]==t[j]?j+1:0;
	}
	j=0;            //注意 j=0
	for(i=0;i<n-1;i++){    //串匹配
		while(j&&s[i]!=t[j])j=p[j];
		if(s[i]==t[j])j++;
		if(j==m){
			ans++;        //此处记录出现次数（模板串在待匹配串中可重叠），或改为直接break表示是否出现过
		}
	}
	return ans;
}

int MINR(char s[],int l){
	for(int i=0;i<l;++i)s[l+i]=s[i];
	s[2*l]=0;
	int i=0,j=1;
	while(i<l&&j<l){
		int k=0;
		while(s[i+k]==s[j+k]&&k<l)++k;
		if(k==l)return min(i,j);
		if(s[i+k]>s[j+k])i=max(i+k+1,j+1);
		else j=max(j+k+1,i+1);
	}
	return min(i,j);
}

int MAXR(char s[],int l){
	for(int i=0;i<l;++i)s[l+i]=s[i];
	s[2*l]=0;
	int i=0,j=1;
	while(i<l&&j<l){
		int k=0;
		while(s[i+k]==s[j+k]&&k<l)++k;
		if(k==l)return min(i,j);
		if(s[i+k]<s[j+k])i=max(i+k+1,j+1);
		else j=max(j+k+1,i+1);
	}
	return min(i,j);
}

int main(){
	while(scanf("%s",s)!=EOF){
		int l=strlen(s);
		strcpy(ss,s);
		int pos=MINR(ss,l);
		for(int i=0;i<l;++i)tmp[i]=ss[i+pos];
		tmp[l]=0;
		printf("%d %d ",pos+1,KMP(ss,tmp));
		strcpy(ss,s);
		pos=MAXR(ss,l);
		for(int i=0;i<l;++i)tmp[i]=ss[i+pos];
		tmp[l]=0;
		printf("%d %d\n",pos+1,KMP(ss,tmp));
	}
	return 0;
}
