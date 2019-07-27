# include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		int dx = x, dy = y;
		if(a == 0)dx--;
		if(a == 1)dx++;
		if(a == 2)dy--;
		if(a == 3)dy++;
		if(dx >= 0 && dx <= 499 && dy >= 0 && dy <= 499){
			x = dx;
			y = dy;	
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}
