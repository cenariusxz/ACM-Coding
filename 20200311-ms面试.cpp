#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;


struct treenode{
	//num
	//left, right;
};

struct dlistnode{
	//num
	//prex, nxt;
};

typedef pair<*treenode, *treenode> pii;

pair<*treenode, *treenode> trans(treenode *root){
	treenode* first = root;
	treenode* last = root;
	if(root -> left != null){
		pii leftlist = trans(root -> left);
		first = leftlist.first;
		leftlist.second -> right = root;
		root -> left = leftlist.second;
	}
	if(root -> right != null){
		pii rightlist = trans(root -> right);
		last = rightlist.second;
		rightlist.first	-> left = root;
		root -> right = rightlist.first;
	}
	return make_pair(first, last);
}

int main(){

	return 0;
}

