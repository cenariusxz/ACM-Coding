#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,a,b,c,cnt=0;
  scanf("%d",&T);
  for(int j=1;j<=T;++j){
    scanf("%d%d%d",&a,&b,&c);
    if(b%a==0)cnt=c/a-b/a+1;
    else cnt=c/a-b/a;
    printf("%d\n",cnt);
    cnt=0;
  }
	return 0;
}

