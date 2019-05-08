#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int d,n,b;
int pos[11],hei[11];

void fuck()
{
	int i,j,z;
	double in,a,p,q,h,vx,vy,w,v=100000000000000.0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&pos[i],&hei[i]);
	for(i=0;i<=b;i++){
		in=(double)d/(i+1);
		w=1.0;
		for(j=1;j<=n;j++){
			z=pos[j]/in;
			p=z*in;
			q=(z+1)*in;
			if(fabs(p-pos[j])<eps) break;
			a=(double)hei[j]/(pos[j]-q)/(pos[j]-p);
			h=(-a)*(p-q)*(p-q)/4;
			w=max(w,a*(p-q));
		}
		if(j<=n) continue;
		vx=sqrt(in/2/w);
		vy=vx*w;
		v=min(v,sqrt(vx*vx+vy*vy));
	}
	printf("%.5f\n",v);
}

int main()
{
	while(~scanf("%d%d%d",&d,&n,&b))
		fuck();
 return 0;
}
