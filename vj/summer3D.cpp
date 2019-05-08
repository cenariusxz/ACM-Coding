#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

struct ques{
	int i,p,num;
	bool operator < (const ques a)const{
		return i>a.i;
	}
}q[200005];

int ans[200005];
int a[200005];
int pos[200005];

int main(){
	int n;
	int i,cnt=0;
	map<int,int>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!m[a[i]])m[a[i]]=++cnt;
		a[i]=m[a[i]];
	}
	
	return 0;
}
