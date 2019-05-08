#include<stdio.h>

struct Node{
	int x;
	Node *son;
};

int main(){
	Node *a;
	Node *b=new Node();
	a=new Node();
	if(a->son==NULL)printf("aaaa\n");
	a->son=b;
	Node *c=new Node();
	delete a->son;
	if(a->son==NULL)printf("aaaaaa\n");
	if(b==NULL)printf("bbbbbb\n");
}
