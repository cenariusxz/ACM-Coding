#include<stdio.h>
#include<String.h>
#include<vector>

vector<int>a[200001];
int b[200001],num[200001],p[200001];

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int s;
		scanf("%d",&s);
		q[s].push_back(i);
	}
	bool f=1;
	memset(num,0,sizeof(num));
	b[1]=q[0][0];
	p[1]=0;
	num[0]++;
	for(i=1;i<=n&&f;i++){
		if(num[p[i+1]]<=a[p[i+1]+1].size){
			b[i]=a[p[i+1]+1][num[p[i+1]+1]++];
			p[i]=p[i+1]+1;
		}
		else if(i-2>=0&&num[p[i-2]]<=a[p[i-2]+1].size){
			b[i]=a[p[i-2]+1][num[p[i-2]+1]++];
			p[i]=p[i-2]+1;
		}
		else f=0;
	}
	if(f){
		printf("Possible\n");

	}
	return 0;
}
