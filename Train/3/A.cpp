#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long  gcd(long long a,long long b){
	return b == 0 ? a : gcd(b,a % b);
}

int H,W;
long long h[10],w[10];
int p[10];

int main(){
	h[1] = 1024; w[1] = 768; p[1] = 319;
	h[2] = 1024; w[2] = 600; p[2] = 419;
	h[3] = 960;  w[3] = 640; p[3] = 450;
	h[4] = 2048; w[4] = 1536;p[4] = 519;
	h[5] = 1136; w[5] = 640; p[5] = 599;
	h[6] = 1280; w[6] = 800; p[6] = 600;
	h[7] = 1920; w[7] = 1080;p[7] = 630;
	h[8] = 1136; w[8] = 640; p[8] = 719;
	while(scanf("%d%d",&H,&W) != EOF){
		if(H == 0 && W == 0) break;
		int ans = 1000;
		long long t1=-1,t2=1;
		for(int i = 1; i <= 8; ++i){
			double tt = 1.0 * w[i] * H / W;
			long long th=tt;
			if(tt <= h[i]){
				if(th * t2 > h[i] * t1){
					t1 = th;
					t2 = h[i];
					ans = p[i];
					long long g=gcd(t1,t2);
					t1/=g;
					t2/=g;
				}
				else if(th * t2 == h[i] * t1){
					ans = min(ans,p[i]);
				}
			}
			tt = 1.0*h[i] * W / H;
			long long tw=tt;
			if(tt <= w[i]){
				if(tw * t2 > w[i] * t1){
					t1 = tw;
					t2 = w[i];
					ans = p[i];
					long long g = gcd(t1,t2);
					t1/=g;
					t2/=g;
				}
				else if(tw * t2 == w[i] * t1){
					ans = min(ans,p[i]);
				}
			}
			swap(h[i],w[i]);
		}
		for(int i = 1; i <= 8; ++i){
			double tt = 1.0 * w[i] * H / W;
			long long th=tt;
			if(tt <= h[i]){
				if(th * t2 > h[i] * t1){
					t1 = th;
					t2 = h[i];
					ans = p[i];
					long long g=gcd(t1,t2);
					t1/=g;
					t2/=g;
				}
				else if(th * t2 == h[i] * t1){
					ans = min(ans,p[i]);
				}
			}
			tt = 1.0*h[i] * W / H;
			long long tw=tt;
			if(tt <= w[i]){
				if(tw * t2 > w[i] * t1){
					t1 = tw;
					t2 = w[i];
					ans = p[i];
					long long g = gcd(t1,t2);
					t1/=g;
					t2/=g;
				}
				else if(tw * t2 == w[i] * t1){
					ans = min(ans,p[i]);
				}
			}
			swap(h[i],w[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
