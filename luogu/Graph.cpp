#include <bits/stdc++.h>
using namespace std;

vector<int>V[maxn];

//i -> j
V[i].push_back(j);


vector<pair<int,int> >V[maxn];

//i --10-> j
V[i].push_back(make_pair(j,10));


struct edge{
	int to,val;
};
vector<edge>V[maxn];

//i --10-> j
edge e;
e.to = j;
e.val = 10;
V[i].push_back(e);


for(int j = 1 ; j <= n ; ++ j){
	M[i][j];
}

for(int k = 0 ; k < V[i].size() ; ++ k){
	int j = V[i][k];
}

for(int k = 0 ; k < V[i].size() ; ++ k){
	pair<int,int> e = V[i][k];
	int j = e.first;
	int val = e.second;
}

for(int k = 0 ; k < V[i].size() ; ++ k){
	edge e = V[i][k];
	int j = e.to;
	int val = e.val;
}
