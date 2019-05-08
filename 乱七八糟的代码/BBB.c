#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
char s1[200005],s2[200005];
int a[30][30],c1[30],c2[30];
/*
struct P{
	char a,b;
	int num;
}p[200005];
*/
int main(){
	int n,i,j;
	scanf("%d%s%s",&n,s1,s2);
	memset(a,-1,sizeof(a));
	memset(c1,-1,sizeof(c1));
	memset(c2,-1,sizeof(c2));
	int cnt=0,ans=0;
	bool f1=0,f2=0;int a1=-1,b1=-1,a2=-1,b2=-1;
	for(i=0;i<n;i++){
		if(s1[i]==s2[i])ans++;
		else if(s1[i]!=s2[i]){
			if(a[s1[i]-'a'][s2[i]-'a']==-1){
				a[s1[i]-'a'][s2[i]-'a']=i;
			}
			if((~c2[s1[i]-'a'])&&!f2){
				f2=1;
				a2=i;
				b2=c2[s1[i]-'a'];
			}
			if((~c1[s2[i]-'a'])&&!f2){
				f2=1;
				a2=i;
				b2=c1[s2[i]-'a'];
			}
			if(c1[s1[i]-'a']==-1){
				c1[s1[i]-'a']=i;
			}
			if(c2[s2[i]-'a']==-1){
				c2[s2[i]-'a']=i;
			}
			if((~a[s1[i]-'a'][s2[i]-'a'])&&(~a[s2[i]-'a'][s1[i]-'a'])&&!f1){
				a1=a[s2[i]-'a'][s1[i]-'a'];
				b1=a[s1[i]-'a'][s2[i]-'a'];
				f1=1;
			}
		}
	}
		if(f1){
			printf("%d\n%d %d\n",n-(ans+2),a1+1,b1+1);
		}
		else if(f2){
			printf("%d\n%d %d\n",n-(ans+1),a2+1,b2+1);
		}
		else{
			printf("%d\n-1 -1\n",n-ans);
		}

}
