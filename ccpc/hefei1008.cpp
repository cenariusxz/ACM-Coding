#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=5050;    //maxm是所有单词的总长度

struct point{
	int s,l;
	bool operator <(const point a)const{
		if(s==a.s)return l>a.l;
		return s<a.s;
	}
}s[1000003];

int a[105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		a[0]=0;
		for(int i=1;i<=n;++i){
			a[i]^=a[i-1];
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				int tmp=a[i-1]^a[j];
				++cnt;
				s[cnt].s=tmp;
				s[cnt].l=j-i+1;
	//			printf("%d %d\n",s[cnt].s,s[cnt].l);
			}
		}
		sort(s+1,s+cnt+1);
		n=1;
		for(int i=2;i<=cnt;++i){
			if(s[i].s!=s[i-1].s)s[++n]=s[i];
		}
		scanf("%d",&m);
		for(int i=1;i<=m;++i){
			int num;
			scanf("%d",&num);
			if(num<0)num=0;
			int tmp=0x3f3f3f3f;
			int ans=0;
			for(int j=1;j<=n;++j){
				if(abs(num-s[j].s)<tmp){
					tmp=abs(num-s[j].s);
					ans=s[j].l;
				}
				else if(abs(num-s[j].s)==tmp){
					ans=max(ans,s[j].l);
				}
				if(s[j].s>num)break;
			}
			printf("%d\n",ans);
		}
		printf("\n");
	}
	return 0;
}
