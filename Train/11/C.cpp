#include<bits/stdc++.h>
using namespace std;
char s[1010];
char t[1010];

void fuck()
{
	vector<int> ans;
	int i,j,l=strlen(s+1);
	for(i=1;i<=l;i++)
		s[i]-='0';
	memset(t,0,sizeof(t));
	for(i=2;i<=l;i++){
		if(s[i]==t[i]) continue;
		ans.push_back(i-1);
		for(j=i;j<=l;j+=i-1) t[j]^=1;
	}
	for(i=0;i<ans.size()-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[i]);
}

int main()
{
	while(~scanf("%s",s+1)&&strcmp(s+1,"0"))
		fuck();
 return 0;
}
