#include<stdio.h>
#include<string.h>
int c[5001],a[5001],s[5001];
int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int cnt=0;
    while(x>0){
        cnt+=c[x];
        x-=lowbit(x);
    }
    return cnt;
}
void add(int x,int d,int n){
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
    return;
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        memset(c,0,sizeof(c));
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        int i,a1,min;s[1]=0;
        for(i=1;i<=n;i++){
            int l;
            scanf("%d",&a1);
            a[i]=a1+1;
            add(a[i],1,n);
            l=a[i]-sum(a[i]);
            s[1]+=l;
        }
        min=s[1];
        memset(c,0,sizeof(c));
        for(i=2;i<=n;i++){
            int l=a[i]-1;
            s[i]=s[i-1]-l+(n-l);
            if(s[i]<min)min=s[i];
        }
        printf("%d\n",min);
    }
}
