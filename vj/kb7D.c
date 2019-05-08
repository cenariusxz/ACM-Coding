#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXM=20002;

int ql[(MAXM<<2)+5],qr[(MAXM<<2)+5],y[(MAXM<<2)+5];
bool f[(MAXM<<2)+5],fl;

void update(int o,int l,int r,int a){
	if(f[o])return;
	if(ql[a]<=y[l]&&qr[a]>=y[r]){
		f[o]=1;
		fl=1;
		return;
	}
	int m=l+((r-l)>>1);
	if(ql[a]<=y[m])update(o<<1,l,m,a);
	if(qr[a]>=y[m+1])update(o<<1|1,m+1,r,a);
	f[o]=f[o<<1]&&f[o<<1|1];
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int n;
			scanf("%d",&n);
			int i,m=0;
			for(i=n;i>=1;i--){
				scanf("%d%d",&ql[i],&qr[i]);
				y[++m]=ql[i];
				y[++m]=qr[i];
			}
			sort(y+1,y+m+1);
			int cnt=0,ans=0;
			for(i=2;i<=m;i++){
				if(y[i]!=y[i-1]){
					y[++cnt]=y[i-1];
				}
			}
			if(y[m]!=y[cnt])y[++cnt]=y[m];
			memset(f,0,sizeof(f));
			for(i=1;i<=m;i++){
				fl=0;
				update(1,1,cnt,i);
				if(fl)ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
