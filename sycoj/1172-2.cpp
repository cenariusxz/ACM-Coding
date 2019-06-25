#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

string s;
char ss[maxn];
int k;
int a[20],b[20];
queue<string>q;
map<string, int>M;

int main(){
	scanf("%s%d",ss,&k);
	s = string(ss);
	for(int i = 1 ; i <= k ; ++ i)scanf("%d%d",&a[i],&b[i]);
	M[s] = 1;
	int ans = 1;
	q.push(s);
	while(!q.empty()){
		string u = q.front();q.pop();
		for(int i = 1 ; i <= k ; ++ i){
			int len = u.length();
			for(int j = 0 ; j < len ; ++ j){
				if(a[i] == u[j] - '0'){
					string tmp = u;
					tmp[j] = b[i] + '0';
					if(!M[tmp]){
						M[tmp] = 1;
						ans ++;
						q.push(tmp);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}


