#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define PI pair<int,int>

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
const int N = 1000010;

const int dir[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//const int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


ll a,b,c,n,order[100001],ans;

int main(){
    freopen("T1-6.in","r",stdin);
    freopen("debug.out","w",stdout);
    IOS;
    cin>>a>>b>>c>>n;//Èí£¬Ó²£¬×ù£»2£¬2£¬1£¬4
    for(int i=1; i<=n; i++){
        cin>>order[i];//1£¬3£¬3£¬2
        ll p = order[i];
        if(i%2==1){
            if(c==0&&a==0&&b==0){ans+=order[i];}
            else if(a>0){
                if(a-order[i]>=0){a-=order[i];}
                else if(a+b-order[i]>=0){b=a+b-order[i];a=0;}
                else if(a+b+c-order[i]>=0){c=a+b+c-order[i];a=b=0;}
                else{ans+=order[i]-a-b-c;a=b=c=0;}
            }
            else if(a==0&&b>0){
                if(a+b-order[i]>=0){b=a+b-order[i];a=0;}
                else if(a+b+c-order[i]>=0){c=a+b+c-order[i];a=b=0;}
                else{ans+=order[i]-a-b-c;a=b=c=0;}
            }
            else if(a==0&&b==0&&c>0){
                if(a+b+c-order[i]>=0){c=a+b+c-order[i];a=b=0;}
                else{ans+=order[i]-a-b-c;a=b=c=0;}
            }
        }
        if(i%2==0){
            if(c-order[i]>=0){c-=order[i];}
            else if(c-order[i]<0){
                order[i]-=c;
                c=0;
                ll now=0,now2=0;
                now=order[i]/3;
                now2=order[i]%3;
                if(now*3+now2>b*3){
                    ans+=(now-b)*3+now2;
                    b=0;
                }
                else{
                    if(now2==0){b-=now;}
                    else{b-=now+1;c+=3-now2;}
                }
            }
        }
        cout<<i<<" "<<p<<" "<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
