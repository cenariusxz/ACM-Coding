#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
int cmp(const void*x,const void *y){
    return *(int *)x-*(int *)y;
}
int bsrch(long long a[],long long n,long long x)//a为正序数组，n为数组中数的个数，x为需要查找的数
{
    long long low=0,high=n,mid;
    if(x>a[high])return -1;
    while (low<=high){
        mid=(low+high)/2;
        if(x==a[mid])return a[mid];
        if(low==high&&x!=a[mid])return a[high];
        if(x<a[mid])high=mid;
        if(x>a[mid])low=mid+1;
    }
    return a[high];
}
long long x[100001];
using namespace std;
int main(){
    long long N,C;
    while (scanf("%I64d%I64d",&N,&C)!=EOF){
        long long i,m,m1,t;
        for(i=0;i<N;i++) scanf("%I64d",&x[i]);
        qsort(x,N,sizeof(long long),cmp);
        m1=m=(x[N-1]-x[0])/(C-1);
        while(1){
            t=x[0];
            for(i=1;i<C;i++){
                t=bsrch(x,N-1,t+m1);
                if(t==-1){
                    break;
                }
            }
            if(t!=-1){
                break;
            }
            else if(t==-1&&m>=m1){
                m1--;
            }
            else if(t==-1&&m<m1){
                m1--;
                break;
            }
        }
        printf("%I64d\n",m1);
    }
}

