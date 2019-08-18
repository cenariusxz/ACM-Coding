#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int id, score;
	bool operator< (const node a)const{
		
		if(score > a.score)return 1;
		if(score == a.score && id < a.id)return 1;
		return 0;
		//-------------------------------------------------------
		if(score == a.score)return id < a.id;
		return score > a.score;
	}
};

node a[maxn];

int n;
vector<int> v;

int main(){
	n = 7;
	for(int i = 1 ; i <= n ; ++ i){
		v.PB(i);
	}
	int len = v.size();
	printf("%d\n",len);
	for(int i = 0 ; i < len ; ++ i){
		printf("%d ",v[i]);	
	}
	printf("\n");
	
	sort(v.begin(),v.end(),greater<int>() );
	for(int i = 0 ; i < len ; ++ i){
		printf("%d ",v[i]);	
	}
	printf("\n");
	
	sort(v.begin(),v.end());
	for(int i = 0 ; i < len ; ++ i){
		printf("%d ",v[i]);	
	}
	printf("\n");
	return 0;
}
