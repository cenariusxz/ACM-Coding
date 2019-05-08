#include <bits/stdc++.h>
using namespace std;

char TreeNode[100];

void preDFS(int root){
	printf("%c",TreeNode[root]);
	if(TreeNode[root<<1])preDFS(root<<1);
	if(TreeNode[root<<1|1])preDFS(root<<1|1);
}

void inDFS(int root){
	if(TreeNode[root<<1])inDFS(root<<1);
	printf("%c",TreeNode[root]);
	if(TreeNode[root<<1|1])inDFS(root<<1|1);
}

void postDFS(int root){
	if(TreeNode[root<<1])postDFS(root<<1);
	if(TreeNode[root<<1|1])postDFS(root<<1|1);
	printf("%c",TreeNode[root]);
}

int main(){
	for(int i = 1 ; i <= 7 ; ++ i)TreeNode[i] = 'A'+i-1;
	preDFS(1);
	printf("\n");
	inDFS(1);
	printf("\n");
	postDFS(1);
	printf("\n");
	return 0;
}
