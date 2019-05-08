#include<stdio.h>
int v[6]={0,50,25,10,5,1};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0,ans1=0;
        for(int i=n/50;i>=0;i--){
            for(int j=(n-50*i)/25;j>=0;j--){
                for(int k=(n-50*i-25*j)/10;k>=0;k--){
                    for(int q=(n-50*i-25*j-10*k)/5;q>=0;q--){
                        ans1=i+j+k+q+n-i*50-j*25-k*10-q*5;
                        if(ans1<=100)ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
