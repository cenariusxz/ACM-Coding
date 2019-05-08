#include<stdio.h>
#include<algorithm>
using namespace std;
int x[502];

int main(){
    int M;
    while(scanf("%d",&M)!=EOF){
        for (int q=1;q<=M;q++){
            int N;
            scanf("%d",&N);
            for(int p=1;p<=N;p++){
                scanf("%d",&x[p]);
            }
            sort(x+1,x+N+1);
            int i,j,ans=0;
            for(i=1,j=N;i<=j;i++,j--){
                ans+=x[j]-x[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
