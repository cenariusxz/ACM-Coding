#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct row{
	int y;
	int x1,x2;
	bool operator<(row a)const{
		return y<a.y;
	}
}a[26];

struct col{
	int x;
	int y1,y2;
	bool operator<(col a)const{
		return x<a.x;
	}
}b[26];

bool judge(int i,int j,int k,int p){
	if(a[i].y==a[j].y||b[k].x==b[p].x)return 0;
	if(a[i].x1>=a[j].x2||a[i].x2<=a[j].x1||b[k].y1>=b[p].y2||b[k].y2<=b[p].y1)return 0;
	if(max(b[k].y1,b[p].y1)<=a[i].y && min(b[k].y2,b[p].y2)>=a[j].y && max(a[i].x1,a[j].x1)<=b[k].x && min(a[i].x2,a[j].x2)>=b[p].x)return 1;
	return 0;
}

int main(){
	int T,n,i,j;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		scanf("%d",&n);
		int cnta=0,cntb=0;
		for(i=1;i<=n;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2){
				++cntb;
				b[cntb].x=x1;
				if(y1>y2){
					b[cntb].y1=y2;
					b[cntb].y2=y1;
				}
				else{
					b[cntb].y2=y2;
					b[cntb].y1=y1;
				}
			}
			else{
				++cnta;
				a[cnta].y=y1;
				if(x1>x2){
					a[cnta].x1=x2;
					a[cnta].x2=x1;
				}
				else{
					a[cnta].x2=x2;
					a[cnta].x1=x1;
				}
			}
		}
		sort(a+1,a+cnta+1);
		sort(b+1,b+cntb+1);
		int k,p;
		int ans=0;
		for(i=1;i<cnta;i++){
			for(j=i+1;j<=cnta;j++){
				for(k=1;k<cntb;k++){
					for(p=1;p<=cntb;p++){
						if(judge(i,j,k,p))ans++;
					}
				}
			}
		}
		printf("Case #%d:\n%d\n",q,ans);
	}
	return 0;
}
