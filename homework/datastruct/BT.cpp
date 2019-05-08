#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

const int maxdep=5;

struct TreeNode{
	TreeNode *lson,*rson;
	int num;
	char data;
	TreeNode(int n,char c):lson(NULL),rson(NULL),num(n),data(c){}
};

int cnt=0;

void dfs(TreeNode *root){
	printf("%d: date:%c\n",root->num,root->data);
	if(root->lson==NULL)printf("lson:NULL\n");
	else printf("lson:%d\n",root->lson->num);
	if(root->rson==NULL)printf("rson:NULL\n");
	else printf("rson:%d\n",root->rson->num);
	printf("\n");
	if(root->lson!=NULL)dfs(root->lson);
	if(root->rson!=NULL)dfs(root->rson);
}

void build(TreeNode *root,int dep){
	if(dep>=maxdep)return;
	if(rand()%2){
		root->lson=new TreeNode(++cnt,(char)(rand()%26+'a'));
		build(root->lson,dep+1);
	}
	if(rand()%2){
		root->rson=new TreeNode(++cnt,(char)(rand()%26+'a'));
		build(root->rson,dep+1);
	}
}

void preorder(TreeNode *root){
	printf("%c",root->data);
	if(root->lson!=NULL)preorder(root->lson);
	if(root->rson!=NULL)preorder(root->rson);
}

void midorder(TreeNode *root){
	if(root->lson!=NULL)midorder(root->lson);
	printf("%c",root->data);
	if(root->rson!=NULL)midorder(root->rson);
}

void posorder(TreeNode *root){
	if(root->lson!=NULL)posorder(root->lson);
	if(root->rson!=NULL)posorder(root->rson);
	printf("%c",root->data);
}

int getdep(TreeNode *root,int dep){
	if(root->lson==NULL&&root->rson==NULL)return dep;
	if(root->lson==NULL)return getdep(root->rson,dep+1);
	if(root->rson==NULL)return getdep(root->lson,dep+1);
	return max(getdep(root->lson,dep+1),getdep(root->rson,dep+1));
}

int getleaf(TreeNode *root){
	if(root->lson==NULL&&root->rson==NULL)return 1;
	if(root->lson==NULL)return getleaf(root->rson);
	if(root->rson==NULL)return getleaf(root->lson);
	return getleaf(root->lson)+getleaf(root->rson);
}

int main(){
	srand(time(NULL));
	TreeNode *root=new TreeNode(++cnt,(char)(rand()%26+'a'));
	build(root,1);
	dfs(root);
	preorder(root);
	printf("\n");
	midorder(root);
	printf("\n");
	posorder(root);
	printf("\n");
	int dep=getdep(root,1);
	int leaf=getleaf(root);
	printf("dep=%d\nleaves=%d\n",dep,leaf);
	return 0;
}