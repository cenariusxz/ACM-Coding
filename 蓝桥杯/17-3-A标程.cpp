#include<stdio.h>

int grid[10][10],ans;

void dfs(int x,int y,int s){
	if(x==6&&y==6){
		if(s==3||s==4)ans++;
		return;
	}
	if(grid[x][y])++s;
	if(x<6)dfs(x+1,y,s);
	if(y<6)dfs(x,y+1,s);
}

int main(){
	grid[1][1]=grid[2][2]=grid[4][3]=grid[5][5]=1;
	dfs(0,0,0);
	printf("%d\r\n",ans);
	return 0;
}
