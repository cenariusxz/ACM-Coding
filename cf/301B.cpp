#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[1000];

int main(){
	int n,k,p,x,y,i;
	scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
	int cnt=0,sum=0;
	for(i=1;i<=k;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>=y){
			cnt++;
		}
	}
	sort(a+1,a+k+1);
	int num=n-k;
	vector<int>ans;
	ans.clear();
	if(cnt>=(n+1)/2){
		sum+=n-k;
		for(i=1;i<=n-k;i++)ans.push_back(1);
	}
	else{
		if(n-k<(n+1)/2-cnt)sum=0x7fffffff;
		else{
			sum+=((n+1)/2-cnt)*y;
			int tmp=((n+1)/2-cnt);
			sum+=n-k-tmp;
			for(i=1;i<=(n+1)/2-cnt;i++)ans.push_back(y);
			for(i=1;i<=n-k-tmp;i++)ans.push_back(1);
		}
	}
	if(sum>x)printf("-1\n");
	else{
		for(i=0;i<ans.size();i++){
			printf("%d",ans[i]);
			if(i==ans.size()-1)printf("\n");
			else printf(" ");
		}
	}
}
