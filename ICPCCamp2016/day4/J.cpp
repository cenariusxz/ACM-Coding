#include<bits/stdc++.h>
using namespace std;
int mark[7000]={0};
int mark2[7000]={0};//fa
int a[7000],ans[100];
vector<int> a32[40],a9[11],a7[10];//index
vector<int> num,num2;//value
bool f=0;

void DFS(int n,int sum,int p)
{
	if(f) return;
	if(p>num2.size()) return;
	if(n==7){
		if(sum%7==0){
			f=1;
			//cout<<sum<<endl;
		}
		return;
	}
	ans[n+1]=p+1;
	DFS(n+1,sum+num2[p],p+1);
	DFS(n,sum,p+1);
}

int main()
{
	int x;
	int cnt=0;
	for(int i=1;i<=6666;i++){
		scanf("%d",&a[i]);
		a[i]%=2016;
		a32[a[i]%32].push_back(i);
		if(a32[a[i]%32].size()==32){
			int sum=0;
			cnt++;
			for(auto it:a32[a[i]%32]){
				sum+=a[it];
				mark[it]=cnt;
			}
			num.push_back(sum);
			//cout<<sum%32<<endl;
			a32[a[i]%32].clear();
		}
	}
	for(int i=1;i<=15;i++){
		vector<int> aa;
		if(min(a32[i].size(),a32[32-i].size())<16) continue;
		for(int j=0;j<16;j++){
			aa.push_back(a32[i][j]);
			aa.push_back(a32[32-i][j]);
		}
		int sum=0;
		cnt++;
		for(auto it:aa){
			sum+=a[it];
			mark[it]=cnt;
		}
		num.push_back(sum);
	}

	cnt=0;
	for(int i=0;i<num.size();i++){
		a9[num[i]%9].push_back(i+1);
		if(a9[num[i]%9].size()==9){
			++cnt;
			int sum=0;
			for(auto it:a9[num[i]%9]){
				sum+=num[it-1];
				mark2[it]=cnt;
			}
			num2.push_back(sum);
			a9[num[i]%9].clear();
			//cout<<sum%9<<" "<<sum%16<<endl;
		}
	}
	/*vector<int> ans;
	for(int i=0;i<num2.size();i++){
		a7[num2[i]%7].push_back(i+1);
		if(a7[num2[i]%7].size()==7){
			for(auto it:a7[num2[i]%7]){
				for(int j=1;j<=6666;j++){
					if(mark2[mark[j]]==it) ans.push_back(j);
				}
			}
			break;
		}
	}*/
	vector<int> res;
	DFS(0,0,0);
	for(int i=1;i<=6666;i++){
		for(int j=1;j<=7;j++)
			if(mark2[mark[i]]==ans[j]){
				res.push_back(i);
				break;
			}
	}
	int sum=0;
	//for(int i=1;i<=6666;i++){
	//	printf("%d %d %d\n",a[i],mark[i],mark2[mark[i]]);
	//}
	//cout<<num.size()<<endl<<num2.size()<<endl;
	for(auto it:res){
		//cout<<it<<" "<< mark[it]<<" "<<mark2[mark[it]]<<endl;
		cout<<it<<endl;
		//sum+=a[it];
	}
	//cout<<" "<<sum<<endl;
 return 0;
}
