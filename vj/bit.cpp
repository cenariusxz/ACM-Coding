#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;        //数组大小

int c[maxn];

inline int lowbit(int x){return x&(-x);}

void change(int x,int v,int n){
	while(x<=n){
		c[x]+=v;
		x+=lowbit(x);
	}
}

int sum(int x){						//求x单点值
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}

void update(int l,int r,int v){		//将区间[l,r]加v
	change(l,v);
	change(r+1,-v);
}
