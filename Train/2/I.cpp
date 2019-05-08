#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e4+5;

int a[maxn];
int pos[maxn];
int l[maxn<<1],r[maxn<<1];
int cnt;

void Swap(int ll,int rr){
	++cnt;
	l[cnt]=ll;
	r[cnt]=rr;
	int i1=ll;
	int i2=(ll+rr)/2+1;
	int len=i2-i1;
	for(int j=0;j<len;++j){
		int t=a[i1+j];
		a[i1+j]=a[i2+j];
		a[i2+j]=t;
		pos[a[i1+j]]=i1+j;
		pos[a[i2+j]]=i2+j;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		cnt=0;
		for(int i=1;i<=n;++i){
			if(pos[i]==i)continue;
			else{
				int a=i;
				int b=pos[i];
				if(b==a+1){
					Swap(a,b);
				}
				else if((b-a)%2==0){
					Swap(a+1,b);
					Swap(a,b-1);
				}
				else{
					Swap(a,b);
					Swap(a,b-2);
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d %d\n",l[i],r[i]);
		}
	}
	return 0;
}
