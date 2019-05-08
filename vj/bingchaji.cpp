#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
int fa[maxn],num[maxn];

void init(int n){
	for(int i=0;i<=n;i++){
		fa[i]=i;
		num[i]=0;        //此处表示和父亲节点的大小差距，初始化0
	}
}

int find(int x){                //这里压缩路径并更新结点权值的思想是先循环加每个结点到父节点的权值，再次循环时每次减去之前更新完的权值再更新
	int r=x,t1,t2,c=0;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=c-num[x];
		num[x]=c;
		fa[x]=r;
		c=t2;
		x=t1;
	}
	return r;
}

int x=find(a),y=find(b);
if(x!=y){            //合并时的操作
	fa[x]=y;
	num[x]=num[b]+v-num[a];
}
