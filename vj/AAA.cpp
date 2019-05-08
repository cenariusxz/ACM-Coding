#include<stdio.h>
#include<string.h>
typedef long long ll;

char ss[150][5];
bool vis[1005];

void init(){
	strcpy(ss['0'],"0000");
	strcpy(ss['1'],"1000");
	strcpy(ss['2'],"0100");
	strcpy(ss['3'],"1100");
	strcpy(ss['4'],"0010");
	strcpy(ss['5'],"1010");
	strcpy(ss['6'],"0110");
	strcpy(ss['7'],"1110");
	strcpy(ss['8'],"0001");
	strcpy(ss['9'],"1001");
	strcpy(ss['a'],"0101");
	strcpy(ss['b'],"1101");
	strcpy(ss['c'],"0011");
	strcpy(ss['d'],"1011");
	strcpy(ss['e'],"0111");
	strcpy(ss['f'],"1111");
	memset(vis,0,sizeof(vis));
}

int a[105];
char s[1005][255];
int m,f,n,ans=0;

void judge(int b){
	int i;
	for(int k=0;k<n;k++){
		if(vis[k])continue;
		for(i=1;i<=f;i++){
			int j=((((ll)a[i])%m)*(((ll)b)%m))%m;
			int x=j/4;
			int y=j%4;
			if(ss[s[k][x]][y]!='1')break;
			if(i==f){
				vis[k]=1;
				ans++;
			}
		}
	}
}

int main(){
	freopen("filter.in","r",stdin);
	freopen("filter.out","w",stdout);
	init();
	scanf("%d%d",&m,&f);
	int i;
	for(i=1;i<=f;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		int b;
		scanf("%d",&b);
		judge(b);
	}
	int cnt=0;
	printf("%d",ans);
	for(i=0;i<n;i++){
		if(vis[i])printf(" %d",i);
	}
	printf("\n");
	return 0;
}
