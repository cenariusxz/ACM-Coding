#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
char s[maxn<<1];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int MINR(char s[],int l){		//s是原串（未加倍过），l是原串长
	for(int i=0;i<l;++i)s[l+i]=s[i];	//将s串加倍
	s[2*l]=0;
	int i=0,j=1;					//利用i，j指针移动
	while(i<l&&j<l){
		int k=0;
		while(s[i+k]==s[j+k]&&k<l)++k;	//不断比较直到比较完长度为l的串或两个子串不相等
		if(k==l)return min(i,j);		//若比较出长度为l则直接返回靠前的那个串的开始位置
		if(s[i+k]>s[j+k])i=max(i+k+1,j+1);	//i串比j串大，那么i到i+k中的串都比j串大，i可以直接移动到i+k+1位置，而起始位置比j小的肯定都在j移动过程中比较过，所以i可以直接移动到j+1位置，因此取这两值的最大值
		else j=max(j+k+1,i+1);	//同上
	}
	return min(i,j);			//返回位置靠前的下标
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
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		strcpy(tmp,s);
		strcpy(tmp1,s);
		printf("%d %d %d\n",MINR(s,strlen(s)),Minr(tmp),minP(tmp1));
	}
	return 0;
}
