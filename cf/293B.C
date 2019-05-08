#include<stdio.h>
#include<string.h>
#include<algorithm>
#define min(a,b) a<b?a:b
using namespace std;
char s[200010],t[200010];
int s1[60],t1[60];

int main(){
	scanf("%s%s",s,t);
	int l1=strlen(s),l2=strlen(t);
	memset(s1,0,sizeof(s1));
	int i;
	for(i=0;i<l1;i++){
		if(s[i]>='a'&&s[i]<='z'){
			s1[s[i]-'a']++;
		}
		else s1[s[i]-'A'+30]++;
	}
	int ans1=0,ans2=0;
	for(i=0;i<l2;i++){
		if(t[i]>='a'&&t[i]<='z'){
			t1[t[i]-'a']++;
		}
		else t1[t[i]-'A'+30]++;
	}
	for(i=0;i<26;i++){
		int m=min(s1[i],t1[i]);
		ans1+=m;
		s1[i]-=m;
		t1[i]-=m;
		m=min(s1[i+30],t1[i+30]);
		ans1+=m;
		s1[i+30]-=m;
		t1[i+30]-=m;
		m=min(s1[i],t1[i+30]);
		ans2+=m;
		s1[i]-=m;
		t1[i+30]-=m;
		m=min(s1[i+30],t1[i]);
		ans2+=m;
		s1[i+30]-=m;
		t1[i]-=m;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
