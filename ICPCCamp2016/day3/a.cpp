#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;

const int maxn=1e5+5;

char a[maxn],b[maxn];
char c[maxn];
int num[maxn][3];

int main(){
	scanf("%s%s",a,b);
	int l1=strlen(a);
	int l2=strlen(b);
	bool f=0;
	if(l1<l2){
		f=1;
		strcpy(c,a);
		strcpy(a,b);
		strcpy(b,c);
		int t=l1;
		l1=l2;
		l2=t;
	}
	int g=gcd(l1,l2);
	memset(num,0,sizeof(num));
	for(int i=0;i<l1;++i){
		int id=i%g;
		if(a[i]=='R')num[id][0]++;
		if(a[i]=='S')num[id][1]++;
		if(a[i]=='P')num[id][2]++;
	}
	ll ans=0;
	for(int i=0;i<l2;++i){
		int id=i%g;
		if(b[i]=='R')ans+=num[id][1]-num[id][2];
		if(b[i]=='S')ans+=num[id][2]-num[id][0];
		if(b[i]=='P')ans+=num[id][0]-num[id][1];
	}
	if(f){
		ans=-ans;
	}
	if(ans>0)printf("AngryBacon\n");
	else if(ans==0)printf("Rowdark\n");
	else printf("TankEngineer\n");
	return 0;
}
