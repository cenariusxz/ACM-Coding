#include<stdio.h>

int MMAX(int a[],int i,int j)//i,j为需要查找最大值的区间
{
    int gmax,hmax,g,h;
    if(i==j) return i;
    else if(i+1==j) return a[i]>=a[j]?i:j;
    else{
        g=(i+j)/2;
        h=g+1;
        gmax=MMAX(a,i,g);
        hmax=MMAX(a,h,j);
        return a[gmax]>=a[hmax]?gmax:hmax;
    }
}

int main(){
    int n;
    while((scanf("%d",&n))!=EOF){
        int a[101],i,max,min,m=32676,b[100];
        bool f=0;
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        for (i=1;i<n;i++) b[i]=a[i+1]-a[i];
        max=b[MMAX(b,1,n-1)];
        for (i=1;i<n-1;i++) {
            if(b[i]+b[i+1]<=max){
                min=max;
                f=1;
                break;
            }
            else {
                if(b[i]+b[i+1]<m) m=b[i]+b[i+1];
            }
        }
        if(f) printf("%d\n",max);
        else printf("%d\n",m);
    }
    return 0;
}
