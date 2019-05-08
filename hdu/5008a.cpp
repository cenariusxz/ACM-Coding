#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
/*
 *`suffix array`
 *`倍增算法  O(n*logn)`
 *`待排序数组长度为n,放在0~n-1中，在最后面补一个0`
 *`da(str ,sa,rank,height, n ,   );//注意是n;`
 *`例如：`
 *`n   = 8;`
 * num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ }; `注意num最后一位为0，其他大于0`
 *`rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值，rank[n]必定为0无效值`
 *`sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值`
 *`height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值`
 *
 */
const int MAXN=100010;
int t1[MAXN],t2[MAXN],c[MAXN];//`求SA数组需要的中间变量，不需要赋值`
//`待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,`
//`除s[n-1]外的所有s[i]都大于0，r[n-1]=0`
//`函数结束以后结果放在sa数组中`
bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m){
	n++;
	int i, j, p, *x = t1, *y = t2;
	//`第一轮基数排序，如果s的最大值很大，可改为快速排序`
	for(i = 0;i < m;i++)c[i] = 0;
	for(i = 0;i < n;i++)c[x[i] = str[i]]++;
	for(i = 1;i < m;i++)c[i] += c[i-1];
	for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
	for(j = 1;j <= n; j <<= 1){
		p = 0;
		//`直接利用sa数组排序第二关键字`
		for(i = n-j; i < n; i++)y[p++] = i;//`后面的j个数第二关键字为空的最小`
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
		//`这样数组y保存的就是按照第二关键字排序的结果`
		//`基数排序第一关键字`
		for(i = 0; i < m; i++)c[i] = 0;
		for(i = 0; i < n; i++)c[x[y[i]]]++;
		for(i = 1; i < m;i++)c[i] += c[i-1];
		for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
		//`根据sa和x数组计算新的x数组`
		swap(x,y);
		p = 1; x[sa[0]] = 0;
		for(i = 1;i < n;i++)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n)break;
		m = p;//`下次基数排序的最大值`
	}
	int k = 0;
	n--;
	for(i = 0;i <= n;i++)rank[sa[i]] = i;
	for(i = 0;i < n;i++){
		if(k)k--;
		j = sa[rank[i]-1];
		while(str[i+k] == str[j+k])k++;
		height[rank[i]] = k;
	}
}
int rank[MAXN],height[MAXN];
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n){
	mm[0]=-1;
	for(int i=1;i<=n;i++)
		mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1;i<=n;i++)best[0][i]=i;
	for(int i=1;i<=mm[n];i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			int a=best[i-1][j];
			int b=best[i-1][j+(1<<(i-1))];
			if(RMQ[a]<RMQ[b])best[i][j]=a;
			else best[i][j]=b;
		}
}
int askRMQ(int a,int b){
	int t;
	t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[t][a];b=best[t][b];
	return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b){
	a=rank[a];b=rank[b];
	if(a>b)swap(a,b);
	return height[askRMQ(a+1,b)];
}
char str[MAXN];
int r[MAXN];
int sa[MAXN];
int dp[20][MAXN];
void init(int n){
	for(int i = 1;i <= n;i++){
		dp[0][i] = sa[i];
	}
	for(int j = 1;j <= mm[n];j++)
		for(int i = 1;i + (1<<j) - 1 <= n;i++)
			dp[j][i] = min(dp[j-1][i],dp[j-1][i+(1<<(j-1))]);
}
int rmq(int x,int y){
	int k = mm[y-x+1];
	return min(dp[k][x],dp[k][y-(1<<k)+1]);
}

long long b[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%s",str) == 1){
		int n = strlen(str);
		for(int i = 0;i < n;i++)r[i] = str[i];
		r[n] = 0;
		da(r,sa,rank,height,n,128);
		for(int i = 1;i <= n;i++)RMQ[i] = height[i];
		initRMQ(n);
		init(n);
		b[0] = 0;
		for(int i = 1;i <= n;i++)
			b[i] = b[i-1] + n - sa[i] - height[i];
		int m;
		scanf("%d",&m);
		long long k;
		int lastl = 0, lastr = 0;
		while(m--){
			scanf("%lld",&k);//提交记得修改========
			k = (k^lastl^lastr) + 1;
			if(k > b[n]){
				printf("0 0\n");
				lastl = 0;
				lastr = 0;
				continue;
			}
			int id = lower_bound(b+1,b+n+1,k) - b;
			k -= b[id-1];
			int len = height[id] + k;
			int ll = id;
			int rr = id;
			int l = id, r = n;
			while(l <= r){
				int mid = (l+r)/2;
				if(sa[id] == sa[mid] || lcp(sa[id],sa[mid]) >= len){
					rr = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			int ansl = rmq(ll,rr);
			int ansr = ansl + len - 1;
			ansl++; ansr++;
			printf("%d %d\n",ansl,ansr);
			lastl = ansl;
			lastr = ansr;
		}
	}
	return 0;
}
