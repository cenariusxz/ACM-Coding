#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int maxl=20;

int ma[maxn][maxl];
int st[maxn][maxl];
int a[maxn],prelog[maxn];

void initRMQ(int n){
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((i&(-i))==i)prelog[i]++;
	}
	for(int i=1;i<=n;++i)ma[i][0]=a[i];
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<j-1)][j-1]);
		}
	}
}

int askRMQ(int l,int r){
	if(l>r)swap(l,r);
	int k=prelog[r-l+1];
	return max(ma[l][k],ma[r-(1<<k)+1][k]);
}


void initST(int n){
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((1<<prelog[i]+1)==i)++prelog[i];
	}
	for(int i=0;i<n;++i)st[i][0]=a[i];
	for(int i=n-1;i>=0;--i){
		for(int j=1;i+(1<<j)-1<n;++j){
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
}

int askST(int l,int r){
	if(l>r)swap(l,r);
	int k=prelog[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main(){
	for(int i=0;i<10;++i)scanf("%d",&a[i]);
	initST(10);
	while(1){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",askST(l,r));
	}
	return 0;
}
