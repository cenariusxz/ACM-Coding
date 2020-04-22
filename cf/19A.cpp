#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct team{
	string name;
	int point, score, miss;
	bool operator < (const team a)const{
		if(point == a.point && score - miss == a.score - a.miss)return score > a.score;
		if(point == a.point)return score - miss > a.score - a.miss;
		return point > a.point;
	}
}t[105];
int n;
char s[maxn];
string names[105];

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", s);
		t[i].name = string(s);
	}
	for(int i = 1 ; i <= n * (n-1) / 2 ; ++ i){
		string t1, t2;
		int id1, id2, sc1, sc2;
		scanf("%s%d:%d", s, &sc1, &sc2);
		for(int j = 0 ; s[j] ; ++ j){
			if(s[j] == '-'){
				s[j] = 0;
				t1 = string(s);
				t2 = string(s+(j+1));
				break;
			}
		}
		for(int j = 1 ; j <= n ; ++ j){
			if(t[j].name == t1)id1 = j;
			if(t[j].name == t2)id2 = j;
		}
		t[id1].score += sc1; t[id1].miss += sc2;
		t[id2].score += sc2; t[id2].miss += sc1;
		if(sc1 > sc2)t[id1].point += 3;
		else if(sc1 == sc2)t[id1].point += 1, t[id2].point += 1;
		else t[id2].point += 3;
	}
	sort(t + 1, t + 1 + n);
	for(int i = 1 ; i <= n / 2 ; ++ i)names[i] = t[i].name;
	sort(names + 1, names + 1 + n/2);
	for(int i = 1 ; i <= n / 2 ; ++ i)printf("%s\n", names[i].c_str());
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

