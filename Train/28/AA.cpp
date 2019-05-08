#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
set<int>st;
char op[MAXN][2];
int pp[MAXN];
int c,p;

void fuck1()
{
	vector<int> v,v1;
	int i,j,x;
	for(i=1;i<=min(1000,p);i++) st.insert(i);
	for(i=1;i<=c;i++){
		scanf("%s",op[i]);
		if(op[i][0]=='E'){
			scanf("%d",&pp[i]);
			if(pp[i]>min(1000,p)) st.insert(pp[i]);
		}
	}
	for(auto it:st) v.push_back(it);
	for(i=1;i<=c;i++){
		if(op[i][0]=='N'){
			x=v[0];
			printf("%d\n",x);
			v.erase(v.begin());
			v.push_back(x);
		}
		else{
			x=pp[i];
			vector<int>::iterator it;
			for(it=v.begin();it!=v.end();it++){
				if(*it==x) break;
			}
			v.erase(it);
			v1=v;
			v.clear();
			v.push_back(x);
			for(it=v1.begin();it!=v1.end();it++){
				v.push_back(*it);
			}
		}
	}
}



int main()
{
	int t=0;
	while(~scanf("%d%d",&p,&c)&&(p||c)){
		printf("Case %d:\n",++t);
		fuck1();
	}
	return 0;
}
