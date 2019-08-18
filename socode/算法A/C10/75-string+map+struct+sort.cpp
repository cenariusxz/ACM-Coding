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

struct stu{
	string name;
	int cnt;
	bool operator < (const stu a)const{
		if(cnt == a.cnt)return name < a.name;
		return cnt < a.cnt;	
	}
}nd[maxn];

char s[105];
map<string,int> M;
int m,n;

int main(){
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%s",s);
		nd[i].name = string(s);
		nd[i].cnt = 0;
		M[s] = i;	
	}
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int num;
		scanf("%d",&num);
		for(int j = 1 ; j <= num ; ++ j){
			scanf("%s",s);
			string tmp = string(s);
			int id = M[tmp];
			nd[id].cnt++;
		}
	}
	sort(nd+1,nd+1+m);
	printf("%s\n",nd[1].name.c_str());
	return 0;
}

