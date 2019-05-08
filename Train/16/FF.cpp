#include <bits/stdc++.h>
using namespace std;
int n;
int g[1100][1100];
int num[1100],acnt;
bool beat1[1100];
pair<int,int> A[1100];
int ans[1100];
vector<int> fac[1100];

void fuck()
{
	int i,j;
	memset(num,0,sizeof(num));
	memset(beat1,0,sizeof(beat1));
	for(i=1;i<=n;++i) fac[i].clear();
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%1d",&g[i][j]);
	for(i=1;i<=n;i++)
		if(g[1][i]) beat1[i]=1;
	for(i=1;i<=n;i++){
		if(g[i][1]){
			for(j=1;j<=n;++j) if(beat1[j] && g[j][i]){
				fac[j].push_back(i);
				num[j]++;
				break;
			}
		}
	}
	acnt = 0;
	stack<int> N2;
	for(i = 1; i <= n; ++i){
		if(num[i]){
			A[++acnt].first = num[i];
			A[acnt].second = i;
		}
		else if(beat1[i]){
			N2.push(i);
		}
	}
	//for(i=1;i<=acnt;++i){
	//	printf("%d %d\n",A[i].first,A[i].second);
	//}
	sort(A + 1,A + acnt + 1);
	int p = acnt,L = n / 2,rem = n / 2 - 1;
	vector<int> G;
	for(; L; L /= 2){
		rem = L;
		while(rem){
			if(p > 0 && A[p].first < rem){
				rem -= 1 + A[p].first;
				G.push_back(A[p].second);
				for(i=0;i<fac[A[p].second].size();++i)
					G.push_back(fac[A[p].second][i]);
				p--;
			}
			else{
				while(rem){
					int tmp = N2.top(); N2.pop();
					G.push_back(tmp);
					rem--;
				}
			}
		}
	}
	G.push_back(1);
	while(1){
		vector<int> TG;
		for(i=0;i<G.size();i+=2){
			int a = G[i],b = G[i + 1];
			printf("%d %d\n",a,b);
			if(g[a][b]) TG.push_back(a);
			else TG.push_back(b);
		}
		G = TG;
		if(G.size() == 1) break;
	}
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}
