#include<stdio.h>
#include<string.h>
long long fa[1000001],s[1000001],max;

void init(long long n){
    for (long long i=1;i<=n;i++) {
        fa[i]=i;
        s[i]=1;
    }
}

long long Find(long long x){
    if(fa[x]==x) return x;
    fa[x]=Find(fa[x]);
    return fa[x];
}

void Union(long long x,long long y){
    long long fx=Find(x),fy=Find(y);
    if(fx!=fy){
        fa[fx]=fy;
        s[fy]+=s[fx];
    }
    max=max>s[fy]?max:s[fy];
}

int main(){
    long long n;
    while(scanf("%I64d",&n)!=EOF){
        memset(fa,0,sizeof(fa));
        memset(s,0,sizeof(s));
        max=1;
        init(2*n);
        for(long long i=1;i<=n;i++){
            long long a,b;
            scanf("%I64d%I64d",&a,&b);
            Union(a,b);
        }
        printf("%I64d\n",max);
    }
}
