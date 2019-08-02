#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int a,b,n,num1[maxn][maxn],num2[maxn][maxn],maxnum[maxn][maxn],minnum[maxn][maxn];

int main(){
	scanf("%d%d%d",&a,&b,&n);
	for(int i = 1 ; i <= a ; ++ i){
		for(int j = 1 ; j <= b ; ++ j){
			scanf("%d",&num1[i][j]);
			num2[i][j] = num1[i][j];
		}
	}
	for(int i = 1 ; i <= a ; ++ i){
		deque<int>qmax,qmin;
		for(int j = 1 ; j <= b ; ++ j){
			while(!qmax.empty() && qmax.back() < j - n + 1)qmax.pop_back();
			while(!qmax.empty() && num1[i][qmax.front()] <= num1[i][j])qmax.pop_front();
			qmax.push_front(j);
			while(!qmin.empty() && qmin.back() < j - n + 1)qmin.pop_back();
			while(!qmin.empty() && num2[i][qmin.front()] >= num2[i][j])qmin.pop_front();
			qmin.push_front(j);
			if(j >= n)maxnum[i][j] = num1[i][qmax.back()], minnum[i][j] = num2[i][qmin.back()];
		}
		for(int j = 1 ; j <= b ; ++ j)num1[i][j] = maxnum[i][j], num2[i][j] = minnum[i][j];
	}
	for(int j = n ; j <= b ; ++ j){
		deque<int>qmax,qmin;
		for(int i = 1 ; i <= a ; ++ i){
			while(!qmax.empty() && qmax.back() < i - n + 1)qmax.pop_back();
			while(!qmax.empty() && num1[qmax.front()][j] <= num1[i][j])qmax.pop_front();
			qmax.push_front(i);
			while(!qmin.empty() && qmin.back() < i - n + 1)qmin.pop_back();
			while(!qmin.empty() && num2[qmin.front()][j] >= num2[i][j])qmin.pop_front();
			qmin.push_front(i);
			if(i >= n)maxnum[i][j] = num1[qmax.back()][j], minnum[i][j] = num2[qmin.back()][j];
		}
	}
	int ans = 0x7fffffff;
	for(int i = n ; i <= a ; ++ i){
		for(int j = n ; j <= b ; ++ j){
			ans = min(ans, maxnum[i][j] - minnum[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
