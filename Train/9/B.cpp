#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n[2],m;
map<int,int> mp[2];
map<int,int>::iterator it;

int main(){
	int tt = 0;
	while(scanf("%d%d%d",&n[0],&n[1],&m) != EOF){
		if(n[0] == 0 && n[1] == 0 && m == 0) break;
		printf("Case %d:\n",++tt);
		mp[0].clear();
		mp[1].clear();
		for(int i = 1; i <= m; ++i){
			int v;
			scanf("%d",&v);
			int id = 0;
			int pos = v % n[0];
			while(1){
				pos = v % n[id];
				if(mp[id][pos] == 0){
					mp[id][pos] = v;
					break;
				}
				else{
					int tv = mp[id][pos];
					mp[id][pos] = v;
					v = tv;
				}
				id ^= 1;
			}
		}
		if(!mp[0].empty()){
			printf("Table 1\n");
			for(it = mp[0].begin(); it != mp[0].end(); ++it){
				printf("%d:%d\n",(*it).first,(*it).second);
			}
		}
		if(!mp[1].empty()){
			printf("Table 2\n");
			for(it = mp[1].begin(); it != mp[1].end(); ++it){
				printf("%d:%d\n",(*it).first,(*it).second);
			}
		}
	}
	return 0;
}
