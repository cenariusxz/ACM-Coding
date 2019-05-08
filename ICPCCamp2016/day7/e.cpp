#include <stdio.h>
#include <set>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int a,b,A,B;
set<int> st;
vector<int> ans;

void Dfs(int p){
	if(st.find(p) == st.end()){
		ans.push_back(p);
		return;
	}
	Dfs(p + p);
	Dfs(p + p + 1);
}

int main(){
	scanf("%d%d",&A,&B);
	if(A == B){
		printf("-1\n");
		return 0;
	}
	if(A > B){
		int t = A;
		A = B;
		B = t;
	}
	a = A;
	b = B;
	bool f = true;
	while(a < b){
		b /= 2;
		if(a == b){
			f = false;
			break;
		}
	}
	if(!f){
		printf("-1\n");
		return 0;
	}
	// a < b
	a = A / 2;
	b = B / 2;
	while(a){
		st.insert(a);
		a /= 2;
	}
	while(b){
		st.insert(b);
		b /= 2;
	}
	Dfs(1);
	sort(ans.begin(),ans.end());
	for(int i = 0; i < ans.size(); ++i){
		printf("%d",ans[i]);
		if(i == ans.size() - 1) printf("\n");
		else printf(" ");
	}
	return 0;
}
