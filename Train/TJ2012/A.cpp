#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char name[50][10]={
	"","1m","2m","3m","4m","5m","6m","7m","8m","9m",
	"1s","2s","3s","4s","5s","6s","7s","8s","9s",
	"1p","2p","3p","4p","5p","6p","7p","8p","9p",
	"1c","2c","3c","4c","5c","6c","7c"

};
bool can[50]={
	0,1,1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0
};
int Check[15]={
	0,1,9,10,18,19,27,28,29,30,31,32,33,34
};

int num[50];
char s[10];
int ans[50];
int n=34;

void add(){
	int id=0;
	if(s[1]=='m')id=s[0]-'0';
	else if(s[1]=='s')id=s[0]-'0'+9;
	else if(s[1]=='p')id=s[0]-'0'+18;
	else if(s[1]=='c')id=s[0]-'0'+27;
	num[id]++;
//	printf("%d\n",id);
}

bool check(int t){
	if(t==0)return 1;
	bool f=0;
	int pos;
	for(int i=1;i<=n;++i){
		if(num[i]){
			pos=i;
			break;
		}
	}
	if(num[pos]>=3){
		num[pos]-=3;
		if(check(t-1)){
			num[pos]+=3;
			return 1;
		}
		num[pos]+=3;
	}
	if(can[pos]&&num[pos]&&num[pos+1]&&num[pos+2]){
		num[pos]--;num[pos+1]--;num[pos+2]--;
		if(check(t-1)){
			num[pos]++;num[pos+1]++;num[pos+2]++;
			return 1;
		}
		num[pos]++;num[pos+1]++;num[pos+2]++;
	}
	return 0;
}

bool check1(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(num[i]==2)cnt++;
		else if(num[i]!=0)break;
	}
	if(cnt==7)return 1;

	cnt=0;
	int cnt1=0;
	for(int i=1;i<=13;++i){
		if(num[Check[i]])cnt++;
		if(num[Check[i]]==2)cnt1++;
	}
	if(cnt==13&&cnt1)return 1;

	for(int i=1;i<=n;++i){
		if(num[i]>=2){
			num[i]-=2;
			if(check(4)){
				num[i]+=2;
				return 1;
			}
			num[i]+=2;
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=13;++i){
			scanf("%s",s);
			add();
		}
/*		for(int i=1;i<=9;++i)printf("%d ",num[i]);
		printf("\n");
		for(int i=10;i<=18;++i)printf("%d ",num[i]);
		printf("\n");
		for(int i=19;i<=27;++i)printf("%d ",num[i]);
		printf("\n");
		for(int i=28;i<=34;++i)printf("%d ",num[i]);
		printf("\n");
*/
		int cnt=0;
		for(int i=1;i<=34;++i){
			if(num[i]<4){
				num[i]++;
				if(check1()){
					ans[i]=1;
					cnt++;
				}
				num[i]--;
			}
		}
		if(cnt){
			printf("%d",cnt);
			for(int i=1;i<=34;++i){
				if(ans[i])printf(" %s",name[i]);
			}
			printf("\n");
		}
		else printf("Nooten\n");
	}
	return 0;
}
