#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int m,s,t;

int main(){
	while(scanf("%d%d%d",&m,&s,&t)!=EOF){
		int mtime = INF,mdis = 0;
		for(int i = 0 ; i <= s/60+1 ; ++i){
			int t1 = 10*i - m;
			if(t1 <= 0)t1 = 0;
			else t1 = t1/4 + (t1%4!=0);
			int t2 = i;
			int t3 = s - 60*i;
			if(t3 <= 0)t3 = 0;
			else t3 = t3/17 + (t3%17!=0);
			if(t1+t2+t3 <= t)mtime = min(mtime,t1+t2+t3);
			else{
				int tdis = 0;
				if(t>t1 && t<=t1+t2)tdis = (t-t1)*60;
				else if(t > t1+t2)tdis = t2*60 + (t-t1-t2)*17;
				mdis = max(mdis,tdis);
			}
		}
		if(mtime == INF)printf("No\n%d\n",mdis);
		else printf("Yes\n%d\n",mtime);
	}
	return 0;
}
