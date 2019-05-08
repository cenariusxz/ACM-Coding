#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int l[100005],r[100005],c[100005];

int main(){
	int n;
	scanf("%d",&n);
	map<int,int>num;
	int i,cnt=0;
	int ans=0,p=0;
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(!num[a]){
			num[a]=++cnt;
			l[cnt]=i;
			r[cnt]=i;
			c[cnt]++;
			if(c[cnt]>ans){
				ans=c[cnt];
				p=cnt;
			}
		}
		else{
			int nn=num[a];
			r[nn]=i;
			c[nn]++;
			if(c[nn]>ans){
				ans=c[nn];
				p=nn;
			}
			else if(c[nn]==ans){
				if(r[nn]-l[nn]<r[p]-l[p]){
					ans=c[nn];
					p=nn;
				}
			}
		}
	}
		printf("%d %d\n",l[p],r[p]);
	return 0;
}
