#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int n,k[10],r[10][10],res[10];
map<string,int> mp1;
string mp2[10];

bool check()
{
	int i,j,now;
	int b[10],x=1;
	for(i=1;i<=n;i++){
		b[i]=i;
		x*=i;
	}
	while(x--){
		now=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=k[b[i]];j++){
				if(r[b[i]][j]==res[now]){
					now++;
					if(now>n) return 0;
					i--;
					break;
				}
			}
		}
		next_permutation(b+1,b+n+1);
	}
	return 1;
}

void fuck()
{
	int i,j;
	string s;
	mp1.clear();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cin>>mp2[i];
	}
	sort(mp2+1,mp2+n+1);
	for(i=1;i<=n;i++)
		mp1[mp2[i]]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(j=1;j<=k[i];j++){
			cin>>s;
			r[i][j]=mp1[s];
		}
	}
	//for(i=1;i<=n;i++)
	//	cout<<" "<<mp2[i]<<endl;
	for(i=1;i<=n;i++){
		res[i]=i;
	}
	int x=1;
	for(i=1;i<=n;i++) x*=i;
	while(x--){
		if(check()) break;
		//for(i=1;i<=n;i++)
		//	cout<<mp2[res[i]]<<" ";
		//cout<<mp2[res[i]]<<endl;
		next_permutation(res+1,res+1+n);
	}
	//res[1]=1;res[2]=3;res[3]=2;res[4]=4;
	//check();
	if(x<=0){
		printf("No\n");
		return;
	}
	printf("Yes\n");
	for(i=1;i<n;i++){
		cout<<mp2[res[i]]<<" ";
	}
	cout<<mp2[res[n]]<<endl;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
