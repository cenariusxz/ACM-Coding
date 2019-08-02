# include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if(a == 0)x--;
		if(a == 1)x++;
		if(a == 2)y--;
		if(a == 3)y++;
	}
	printf("%d %d\n",x,y);
	return 0;
}
