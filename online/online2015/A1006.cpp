#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=40010;

int sa[MAXN];//SA数组，表示将S的n个后缀从小到大排序后把排好序的
//的后缀的开头位置顺次放入SA中
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
int rk[MAXN],height[MAXN];
void build_sa(int s[],int n,int m)
{
	int i,j,p,*x=t1,*y=t2;
	for(i=0;i<m;i++)c[i]=0;
	for(i=0;i<n;i++)c[x[i]=s[i]]++;
	for(i=1;i<m;i++)c[i]+=c[i-1];
	for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
	for(j=1;j<=n;j<<=1)
	{
		p=0;
		for(i=n-j;i<n;i++)y[p++]=i;//后面的j个数第二关键字为空的最小
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)c[i]=0;
		for(i=0;i<n;i++)c[x[y[i]]]++;
		for(i=1;i<m;i++)c[i]+=c[i-1];
		for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(i=1;i<n;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
		if(p>=n)break;
		m=p;//下次基数排序的最大值
	}
}

void getHeight(int s[],int n)
{
	int i,j,k=0;
	for(i=0;i<=n;i++)rk[sa[i]]=i;
	for(i=0;i<n;i++)
	{
		if(k)k--;
		j=sa[rk[i]-1];
		while(s[i+k]==s[j+k])k++;
		height[rk[i]]=k;
	}
}

char str[MAXN];
int s0[MAXN];
int s1[MAXN];
int ans0[MAXN];
int ans1[MAXN];
int pp1[MAXN],pp0[MAXN];

int check(int n){
	for(int i=0;i<n;++i){
		if(ans0[i]<ans1[i])return 1;
		else if(ans0[i]>ans1[i])return 0;
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",str);
		for(int i=0;i<=n;i++)s0[i]=str[i]-'a'+1;
		for(int i=0;i<=n;i++)s0[n+i]=str[i]-'a'+1;
		s0[2*n]=0;
/*		for(int i=0;i<=2*n;++i)printf("%d ",s0[i]);
		printf("\n");*/
		build_sa(s0,2*n+1,28);
/*		for(int i=0;i<=2*n;++i)printf("%d ",sa[i]);
		printf("\n");*/
		int p0,p1;
		for(int i=2*n;i>=1;--i){
			if(sa[i]<n){p0=sa[i];break;}
		}
		for(int i=0;i<n;++i){
			ans0[i]=s0[p0+i];
//			printf("%d ",ans0[i]);
		}
/*		printf("\n");
		printf("\n");*/

		for(int i=0,j=n-1;i<n;i++,j--)s1[j]=str[i]-'a'+1;
		for(int i=0,j=n-1;i<n;i++,j--)s1[n+i]=str[j]-'a'+1;
		s1[2*n]=0;
/*		for(int i=0;i<=2*n;++i)printf("%d ",s1[i]);
		printf("\n");*/
		build_sa(s1,2*n+1,28);
/*		for(int i=0;i<=2*n;++i)printf("%d ",sa[i]);
		printf("\n");*/
		for(int i=2*n;i>=1;--i){
			if(sa[i]<n){p1=sa[i];break;}
		}
		for(int i=0;i<n;++i){
			ans1[i]=s1[p1+i];
//			printf("%d ",ans1[i]);
		}

/*		printf("\n");
		printf("\n");
*/
		int cc=check(n);
//		printf("c%d\n",cc);
		if(cc==-1){
			int i,j;
			pp0[0]=pp0[1]=0;
			for(i=1;i<n;++i){
				j=pp0[i];
				while(j&&ans0[i]!=ans0[j])j=pp0[j];
				pp0[i+1]=ans0[i]==ans0[j]?j+1:0;
			}
			j=0;
			for(int i=0;i<2*n;++i){
				while(j&&s0[i]!=ans0[j])j=pp0[j];
				if(s0[i]==ans0[j])j++;
				if(j==n){
					p0=i-n+1;
					break;
				}
			}
			pp1[0]=pp1[1]=0;
			for(i=1;i<n;++i){
				j=pp1[i];
				while(j&&ans1[i]!=ans1[j])j=pp1[j];
				pp1[i+1]=ans1[i]==ans1[j]?j+1:0;
			}
			j=0;
			for(int i=0;i<2*n;++i){
				while(j&&s1[i]!=ans1[j])j=pp1[j];
				if(s1[i]==ans1[j])j++;
				if(j==n){
					if(i-n+1<n)p1=i-n+1;
				}
			}
			p1=n-(p1+1);
		//	printf("p0:%d p1:%d\n",p0,p1);
			if(p0<p1){
				printf("%d 0\n",p0+1);
			}
			else if(p0>p1){
				printf("%d 1\n",p1+1);
			}
			else printf("%d 0\n",p0+1);

		}
		else if(cc==0){
			int i,j;
			pp0[0]=pp0[1]=0;
			for(i=1;i<n;++i){
				j=pp0[i];
				while(j&&ans0[i]!=ans0[j])j=pp0[j];
				pp0[i+1]=ans0[i]==ans0[j]?j+1:0;
			}
			j=0;
			for(int i=0;i<2*n;++i){
				while(j&&s0[i]!=ans0[j])j=pp0[j];
				if(s0[i]==ans0[j])j++;
				if(j==n){
					p0=i-n+1;
					break;
				}
			}
			printf("%d 0\n",p0+1);
		}
		else if(cc==1){
			int i,j;
			pp1[0]=pp1[1]=0;
			for(i=1;i<n;++i){
				j=pp1[i];
				while(j&&ans1[i]!=ans1[j])j=pp1[j];
				pp1[i+1]=ans1[i]==ans1[j]?j+1:0;
			}
			j=0;
			for(int i=0;i<2*n;++i){
				while(j&&s1[i]!=ans1[j])j=pp1[j];
				if(s1[i]==ans1[j])j++;
				if(j==n){
					if(i-n+1<n)p1=i-n+1;
			//		p0=i-n+1;
				}
			}
			p1=n-(p1+1);
			printf("%d 1\n",p1+1);
		}
	}
	return 0;
}
