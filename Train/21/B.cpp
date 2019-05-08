#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

char s[1010];
int len;
vector<string> V;
vector<ll> VV;
map<string,ll> mp;

int main(){
	while(scanf("%s",s + 1) != EOF){
		mp.clear();
		V.clear();
		VV.clear();
		len = strlen(s + 1);
		for(int i = 1; i <= len; ++i){
			string tmp;
			if(s[i] == '(' || s[i] == ')'){
				tmp = s[i];
				V.PB(tmp);
			}
			else if(s[i] >= '0' && s[i] <= '9'){
				tmp += s[i];
				int j = i + 1;
				while(j <= len && s[j] >= '0' && s[j] <= '9'){
					tmp += s[j];
					j++;
				}
				V.PB(tmp);
				i = j - 1;
			}
			else if(s[i] >= 'A' && s[i] <= 'Z'){
				tmp += s[i];
				int j = i + 1;
				while(j <= len && s[j] >= 'a' && s[j] <= 'z'){
					tmp += s[j];
					j++;
				}
				V.PB(tmp);
				i = j - 1;
			}
		}
		for(int i = 0; i < V.size(); ++i) VV.PB(1);
		for(int i = 0; i < V.size(); ++i){
			if(V[i][0] >= '0' && V[i][0] <= '9'){
				ll v = 0;
				for(int j = 0; j < V[i].size(); ++j){
					v = v * 10 + V[i][j] - '0';
				}
				if(V[i - 1][0] == ')'){
					int cnt = 1;
					int j = i - 2;
					while(j >= 0 && cnt > 0){
						if(V[j][0] == '(') cnt--;
						if(V[j][0] == ')') cnt++;
						if(V[j][0] >= 'A' && V[j][0] <= 'Z'){
							VV[j] *= v;
						}
						j--;
					}
				}
				else{
					VV[i - 1] *= v;
				}
			}
		}
		vector<string> ans;
		for(int i = 0; i < V.size(); ++i){
			if(V[i][0] >= 'A' && V[i][0] <= 'Z'){
				ans.PB(V[i]);
				mp[V[i]] += VV[i];
			}
		}
		sort(ans.begin(),ans.end());
		int sz = unique(ans.begin(),ans.end()) - ans.begin();
		for(int i = 0; i < sz; ++i){
			ll num = mp[ans[i]];
			if(num > 1) printf("%lld",num);
			printf("%s",ans[i].c_str());
			if(i < sz - 1) printf("+");
			else printf("\n");
		}
	}
	return 0;
}

