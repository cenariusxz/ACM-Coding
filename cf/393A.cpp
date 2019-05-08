#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

char s[100005];
int vis[256];

int main(){
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		vis[(int)s[i]]++;
	}
	int ans=min((vis['n']-1)/2,(min(vis['i'],min(vis['e']/3,vis['t']))));
	printf("%d\n",ans);
	return 0;
}
