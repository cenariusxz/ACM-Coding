#include <bits/stdc++.h>
using namespace std;
int s[1000005];
int MLB(int s[],int start,int end,int x){
  int l=start;
  int r=end;
  int cnt=INT_MAX;
  while(l<=r){
    int c=(l+r)/2;
    if(s[c]>=x){
    	if(c<cnt)cnt=c;
    	r=c-1;
	}
    else l=c+1;
  }
  if(cnt==INT_MAX)return -1;
  else return cnt;
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i=0;i<a;++i)scanf("%d",&s[i]);
	sort(s,s+a);
	for(int i=0;i<b;++i){
		int x;
		scanf("%d",&x);
		printf("%d\n",MLB(s,0,a-1,x));
	}
	return 0;
}

