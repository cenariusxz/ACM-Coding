#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<time.h>

using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

ll dp[5005][5005];
ll sum[5005][5005];
char s[5005];

const int MAXN=100010;

/*
 *suffix array
 *倍增算法  O(n*logn)
 *待排序数组长度为n,放在0~n-1中，在最后面补一个0
 *build_sa( ,n+1, );//注意是n+1;
 *getHeight(,n);
 *例如：
 *n   = 8;
 *num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
 *Rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };Rank[0~n-1]为有效值，Rank[n]必定为0无效值
 *sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值
 *height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
 *
 */

int sa[MAXN];//SA数组，表示将S的n个后缀从小到大排序后把排好序的
//的后缀的开头位置顺次放入SA中
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
int Rank[MAXN],height[MAXN];
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
void build_sa(int s[],int n,int m)
{
	int i,j,p,*x=t1,*y=t2;
	//第一轮基数排序，如果s的最大值很大，可改为快速排序
	for(i=0;i<m;i++)c[i]=0;
	for(i=0;i<n;i++)c[x[i]=s[i]]++;
	for(i=1;i<m;i++)c[i]+=c[i-1];
	for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
	for(j=1;j<=n;j<<=1)
	{
		p=0;
		//直接利用sa数组排序第二关键字
		for(i=n-j;i<n;i++)y[p++]=i;//后面的j个数第二关键字为空的最小
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		//这样数组y保存的就是按照第二关键字排序的结果
		//基数排序第一关键字
		for(i=0;i<m;i++)c[i]=0;
		for(i=0;i<n;i++)c[x[y[i]]]++;
		for(i=1;i<m;i++)c[i]+=c[i-1];
		for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
		//根据sa和x数组计算新的x数组
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
	for(i=0;i<=n;i++)Rank[sa[i]]=i;
	for(i=0;i<n;i++)
	{
		if(k)k--;
		j=sa[Rank[i]-1];
		while(s[i+k]==s[j+k])k++;
		height[Rank[i]]=k;
	}
}


struct Hash{
	ll B,mod,len,Has[5005],Base[5005];
	void init(char *s,ll _len,ll _B,ll _mod){
		B=_B; mod=_mod; len=_len;
		Base[0]=1; Has[0]=0; 
		for (ll i=1;i<=len;i++){
			Base[i]=Base[i-1]*B%mod;
			Has[i]=(Has[i-1]*B+s[i-1]-'0'+1)%mod;
		}
		return;
	}
	ll gethash(ll l,ll r){
		return ((Has[r]-Has[l-1]*Base[r-l+1])%mod+mod)%mod;
	}
};

Hash h1,h2;

int ss[5005];

int main(){
//	int begin=clock();
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)ss[i]=s[i]-'0';
	build_sa(ss+1,n+1,15);
	getHeight(ss+1,n);
//	for(int i=0;i<=n+1;++i)printf("%d ",Rank[i]);
//	printf("\n");
	s[0]='0';
	for(int i=1;i<=n;++i){
		dp[1][i]=1;
	}
	h1.init(s+1,n,171,mod);
	h2.init(s+1,n,191,mod+2);
	dp[0][0]=sum[0][0]=1;
	for(int j=1;j<=n;++j){
		for(int i=j;i>=2;--i){
			if(s[i]=='0'){
				dp[i][j]=0;
				continue;
			}
			int l=2*i-1-j;
			if(l<=0){
				l=0;
				dp[i][j]=sum[0][i-1];
			}
			else{
				dp[i][j]=sum[l+1][i-1];
				int pos1=l,pos2=i;
				if(!(h1.gethash(l,i-1)==h1.gethash(i,j)&&h2.gethash(l,i-1)==h2.gethash(i,j))){
					if(Rank[pos1-1]<Rank[pos2-1]){
						dp[i][j]+=dp[l][i-1];
					}
				}
			}
			if(dp[i][j]>=mod)dp[i][j]-=mod;
		}
		for(int i=j;i>=0;--i){
			sum[i][j]=sum[i+1][j]+dp[i][j];
			if(sum[i][j]>=mod)sum[i][j]-=mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=dp[i][n];
		if(ans>=mod)ans-=mod;
	}
	printf("%lld\n",ans);
//	printf("%lf\n",(clock()-begin)/1e3);
	return 0;
}
