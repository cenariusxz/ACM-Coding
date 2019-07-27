#include<stdio.h>
#include<string.h>
const int maxn = 3e4 + 5;
int fa[maxn],num[maxn],cnt[maxn];

void init(int n){
    for(int i = 0 ; i <= n ; i ++){
        fa[i] = i;
        num[i] = 0;
        cnt[i] = 1;
    }
}

int find(int x){
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

int main(){
	init(30000);
	int p;
	scanf("%d",&p);
	while(p--){
		char s[5];
		scanf("%s",s);
		if(s[0] == 'M'){
			int a, b;
			scanf("%d%d",&a,&b);
			int x = find(a), y = find(b);
			fa[x] = y;
    		num[x] = cnt[y];
    		cnt[y] += cnt[x];
    		cnt[x] = 0;
		}
		else{
			int a;
			scanf("%d",&a);
			find(a);
			printf("%d\n",num[a]);
		}
	}
	return 0;	
}

