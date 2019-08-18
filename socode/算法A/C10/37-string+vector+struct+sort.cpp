#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct stu{
	string name, id;
	int score2;
	bool operator < (const stu a)const{
		if(score2 == a.score2)return id<a.id;
		return score2 > a.score2;	
	}
};

vector<stu> phy, che, bio;
char name[105], id[15], sub[15];
int n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		stu tmp;
		double a,b,c,d,e;
		scanf("%s%s%lf%lf%lf%lf%s%lf", name, id, &a, &b, &c, &d, sub, &e);
		double sum = (a+b+c+d+e) * 2;
		tmp.name = string(name);
		tmp.id = string(id);
		tmp.score2 = (int)(sum + eps);
		if(sub[0] == 'p')phy.PB(tmp);
		if(sub[0] == 'c')che.PB(tmp);
		if(sub[0] == 'b')bio.PB(tmp);
	}
	sort(phy.begin(),phy.end());
	sort(che.begin(),che.end());
	sort(bio.begin(),bio.end());
	
	printf("%s %s ",phy[0].name.c_str(),phy[0].id.c_str());
	if(phy[0].score2 % 2)printf("%.1lf\n",phy[0].score2/2.0);
	else printf("%d\n",phy[0].score2/2);
	
	printf("%s %s ",che[0].name.c_str(),che[0].id.c_str());
	if(che[0].score2 % 2)printf("%.1lf\n",che[0].score2/2.0);
	else printf("%d\n",che[0].score2/2);
	
	printf("%s %s ",bio[0].name.c_str(),bio[0].id.c_str());
	if(bio[0].score2 % 2)printf("%.1lf\n",bio[0].score2/2.0);
	else printf("%d\n",bio[0].score2/2);
	return 0;
}

