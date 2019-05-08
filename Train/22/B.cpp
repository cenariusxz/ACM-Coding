#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;


char s[15][15];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		int x[2],y[2];
		int c1=0,c2=0;
		int cnt=0;
		int xx1,yy1,xx2,yy2;
		int ans=0;
		for(int i=1;i<=n;++i){
			cnt++;
			if(s[1][i]=='1'){
				x[c1++]=cnt;
				if(c1==1){
					xx1=1;xx2=i;
				}
				else ans+=abs(1-xx1)+abs(i-xx2);
			}
			if(s[1][i]=='2'){
				y[c2++]=cnt;
				if(c2==1){
					yy1=1;yy2=i;
				}
				else ans+=abs(1-yy1)+abs(i-yy2);
			}
		}
		for(int i=2;i<=n;++i){
			cnt++;
			if(s[i][n]=='1'){
				x[c1++]=cnt;
				if(c1==1){
					xx1=i;xx2=n;
				}
				else ans+=abs(i-xx1)+abs(n-xx2);
			}
			if(s[i][n]=='2'){
				y[c2++]=cnt;
				if(c2==1){
					yy1=i;yy2=n;
				}
				else ans+=abs(i-yy1)+abs(n-yy2);
			}
		}
		for(int i=n-1;i>=1;--i){
			cnt++;
			if(s[n][i]=='1'){
				x[c1++]=cnt;
				if(c1==1){
					xx1=n;xx2=i;
				}
				else ans+=abs(n-xx1)+abs(i-xx2);
			}
			if(s[n][i]=='2'){
				y[c2++]=cnt;
				if(c2==1){
					yy1=n;yy2=i;
				}
				else ans+=abs(n-yy1)+abs(i-yy2);
			}
		}
		for(int i=n-1;i>=2;--i){
			cnt++;
			if(s[i][1]=='1'){
				x[c1++]=cnt;
				if(c1==1){
					xx1=i;xx2=1;
				}
				else ans+=abs(i-xx1)+abs(1-xx2);
			}
			if(s[i][1]=='2'){
				y[c2++]=cnt;
				if(c2==1){
					yy1=i;yy2=1;
				}
				else ans+=abs(i-yy1)+abs(1-yy2);
			}
		}
//		printf("%d %d %d %d\n",x[0],x[1],y[0],y[1]);
		if((x[0]<y[0]&&y[0]<x[1]&&x[1]<y[1])||(y[0]<x[0]&&x[0]<y[1]&&y[1]<x[1]))printf("-1\n");
		else printf("%d\n",ans+2);
	}
	return 0;
}
