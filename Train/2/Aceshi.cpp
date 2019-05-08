#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int num[105][105],num1[105][105];
int n,m;
int vis[105][105];
vector<char>ans1;
vector<int>ans2;
void print(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%2d ",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void re_r(int r){
	for(int i=1;i<=m/2;++i){
		swap(num[r][i],num[r][m-i+1]);
	}
	ans1.push_back('R');
	ans2.push_back(r);
}

void re_c(int c){
	for(int i=1;i<=n/2;++i){
		swap(num[i][c],num[n-i+1][c]);
	}
	ans1.push_back('C');
	ans2.push_back(c);
}

void reset(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			num1[i][j]=++cnt;
		}
	}
}

inline void get(int &x,int &y){
	if(x>n/2)x=n-x+1;
	if(y>m/2)y=m-y+1;
}

bool check1(int r,int c){
	int x[4],y[4];
	x[0]=r,y[0]=c;
	x[1]=r,y[1]=m-c+1;
	x[2]=n-r+1,y[2]=c;
	x[3]=n-r+1,y[3]=m-c+1;
	int res[2][4];
	for(int i=0;i<4;++i){
		res[0][i]=num[x[i]][y[i]];
		res[1][i]=num1[x[i]][y[i]];
	}
	sort(res[0],res[0]+4);
	for(int i=0;i<4;++i)if(res[0][i]!=res[1][i])return 1;
	return 0;
}

bool init(){
	ans1.clear();
	ans2.clear();
	scanf("%d%d",&m,&n);
	reset();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&num[i][j]);
		}
	}
	if(n%2){
		int row=(n+1)/2;
		if(num[row][1]!=num1[row][1])re_r(row);
		for(int i=1;i<=m;++i)if(num[row][i]!=num1[row][i])return 1;
	}
	if(m%2){
		int col=(m+1)/2;
		if(num[1][col]!=num1[1][col])re_c(col);
		for(int i=1;i<=n;++i)if(num[i][col]!=num1[i][col])return 1;
	}
	for(int i=1;i<=n/2;++i){
		for(int j=1;j<=m/2;++j){
			if(check1(i,j))return 1;
		}
	}
	return 0;
}

int check2(int r,int c){
	int x[4],y[4];
	x[0]=r,y[0]=c;
	x[1]=r,y[1]=m-c+1;
	x[2]=n-r+1,y[2]=c;
	x[3]=n-r+1,y[3]=m-c+1;
	int tmp=0;	
	for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]])tmp++;
	if(tmp==1||tmp==2||tmp==4)return tmp;

	re_r(r);re_c(c);re_r(r);re_c(c);
	tmp=0;
	for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]])tmp++;
	if(tmp==1||tmp==2||tmp==4)return tmp;

	re_r(r);re_c(c);re_r(r);re_c(c);
	tmp=0;
	for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]])tmp++;
	if(tmp==1||tmp==2||tmp==4)return tmp;
}

bool Pre1(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n/2;++i){
		for(int j=1;j<=m/2;++j){
			int tmp=check2(i,j);
			if(tmp==2)vis[i][j]=1;
		}
	}

/*	print();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",vis[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	for(int i=1;i<=m/2;++i){
		if(vis[1][i]){
			re_c(i);
			for(int j=1;j<=n/2;++j){
				vis[j][i]^=1;
			}
		}
	}
	for(int i=2;i<=n/2;++i){
		if(vis[i][1]){
			re_r(i);
			for(int j=1;j<=m/2;++j){
				vis[i][j]^=1;
			}
		}
	}
	for(int i=1;i<=n/2;++i){
		for(int j=1;j<=m/2;++j){
			if(vis[i][j]==1)return 1;
		}
	}
	return 0;
}

void check3(int r,int c){
	int x[4],y[4];
	x[0]=r,y[0]=c;
	x[1]=r,y[1]=m-c+1;
	x[2]=n-r+1,y[2]=c;
	x[3]=n-r+1,y[3]=m-c+1;
	int tmp=0,pos=0;
	for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]]){
		tmp++;
		pos=i;
	}
	if(tmp==4)return;

	while(!tmp){
		re_r(r);re_c(c);re_r(r);re_c(c);
		for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]]){
			tmp++;
			pos=i;
		}
		if(tmp==4)return;
	}

	pos=3-pos;
	while(1){
		tmp=0;
		re_r(x[pos]);re_c(y[pos]);re_r(x[pos]);re_c(y[pos]);
		for(int i=0;i<4;++i)if(num[x[i]][y[i]]==num1[x[i]][y[i]])tmp++;
		if(tmp==4)return;
	}

}
void solve(){
	for(int i=1;i<=n/2;++i){
		for(int j=1;j<=m/2;++j){
			check3(i,j);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		if(init()){
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(Pre1()){
			printf("IMPOSSIBLE\n");
			continue;
		}
		solve();
		printf("POSSIBLE %d",(int)ans1.size());
		for(int i=0;i<ans1.size();++i){
			printf(" %c%d",ans1[i],ans2[i]);
		}
		printf("\n");
	}
	return 0;
}
