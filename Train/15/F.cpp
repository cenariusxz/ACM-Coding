#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum[610][10010];
double a[10010]={0};

double xie(int x,int y)
{
	return (a[x]-a[y])/(x-y);
}

double cal(int lim)
{
	if(lim>m) return 0;
	int i,tmp1,tmp2;
	double res=0,k1,k2;
	stack<int> st;
	stack<int> st2;
	for(i=0;i+lim<=m;i++)
		res=max(res,xie(i,i+lim));
	st.push(0);
	for(i=1;i<=m;i++){
		//printf(" %d\n",st.size());
		//st.push(i-1);
		if(xie())
		while(!st.empty()){
			tmp1=st.top();
			st.pop();
			if(!st.empty())	tmp2=st.top();
			else break;
			k1=xie(tmp1,i);
			k2=xie(tmp2,i);
			//if(i-tmp1>=lim) res=max(res,k1);
			if(k1<       k2) break;
		}
		st.push(tmp1);
		res=max(res,xie(tmp1,i+lim));
	}
	queue<int> qu;
	int l,r=m;
	while(!st.empty()){
		l=st.top();
		printf("  %d",l);
		st.pop();
		qu.push(l);
		if(r-l<lim) continue;
		res=max(res,xie(l,r));
		r=qu.front();
		qu.pop();
	}
	printf("\n");
	return res;
}

void fuck()
{
	int i,j,l,tmp;
	double ans=0;
	memset(sum,0,sizeof(sum));
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&tmp);
			sum[i][j]=sum[i-1][j]+tmp;
		}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++){
			for(l=1;l<=m;l++)
				a[l]=(double)(sum[j][l]-sum[i-1][l])/(j-i+1)+a[l-1];
			ans=max(cal((k-1)/(j-i+1)+1),ans);
			printf(" %d %d %.3f\n",i,j,ans);
		}
	printf("%.3f\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}

