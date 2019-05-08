#include<iostream>
#include<string>
#include<cstdio>
#include<set>
using namespace std;

int a[1005][4];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		printf("Case #%d:\n",q);
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j,k;
		for(i=1;i<=n;i++)scanf("%d.%d.%d.%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		for(i=1;i<=m;i++){
			int a1[4];
			scanf("%d.%d.%d.%d",&a1[0],&a1[1],&a1[2],&a1[3]);
			set<string>s;
			for(j=1;j<=n;j++){
				string tmp;
				int t;
				for(k=0;k<=3;k++){
					t=a1[k]&a[j][k];
					if(t==0)tmp+="000";
					else if(t<10){
						tmp+="00";
						tmp+=(t+'0');
					}
					else if(t<100){
						tmp+="0";
						tmp+=(t/10+'0');
						tmp+=(t%10+'0');
					}
					else{
						tmp+=(t/100+'0');
						tmp+=((t/10)%10+'0');
						tmp+=(t%100+'0');
					}
				}
				s.insert(tmp);
			}
			cout<<s.size()<<endl;
		}
	}
	return 0;
}
