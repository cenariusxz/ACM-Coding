#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

struct peo{
	int l,r,num;/*
	bool operator > (const peo a)const{
		return r<a.r;
	}*/
	bool operator < (const peo a)const{
		return r>a.r;
	}
}p[100005];

bool cmp(peo a,peo b){
	return a.l<b.l;
}

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int ans[100005];

int main(){
	int T=read();
	while(T--){
		int n=read();
		int i;
		for(i=1;i<=n;i++){
			p[i].l=read();
			p[i].num=i;
		}
		for(i=1;i<=n;i++){
			p[i].r=read();
		}
		sort(p+1,p+n+1,cmp);
		int pos=1;
		int num=0;
		int cnt=0;
		int anss=0;
		priority_queue<peo>q;
		bool f=1;
		while(f){
			for(pos;pos<=n;pos++){
				if(p[pos].l<=num){
					q.push(p[pos]);
				}
				else break;
			}
			f=0;
			while(!q.empty()){
				f=1;
				peo u=q.top();
				q.pop();
				ans[++cnt]=u.num;
				if(u.r>=num){
					num++;
					anss++;
				}
				break;
			}
		}
		for(pos;pos<=n;pos++){
			ans[++cnt]=p[pos].num;
		}
		printf("%d\n",anss);
		for(i=1;i<=n;i++){
			printf("%d",ans[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
