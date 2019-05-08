#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;

struct mat{
	int r,c;
	double m[55][55];        //经测试最大开成590*590的 ll 型矩阵
	mat(){}
	mat(int r,int c):r(r),c(c){}
	void clear(){
		memset(m,0,sizeof(m));
	}

	mat operator+(mat a)const{
		mat ans(r,c);
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				ans.m[i][j]=(m[i][j]+a.m[i][j]);
			}
		}
		return ans;
	}

	mat operator*(mat a)const{
		mat tmp(r,a.c);
		int i,j,k;
		for(i=1;i<=tmp.r;i++){
			for(j=1;j<=tmp.c;j++){
				tmp.m[i][j]=0;
				for(k=1;k<=c;k++){
					tmp.m[i][j]=(tmp.m[i][j]+(m[i][k]*a.m[k][j]));
				}
			}
			tmp.m[i][i]=0;
		}
		return tmp;
	}

	mat operator^(int n)const{        //需要时可以用 ll n，注意运算符优先级比较低，多用括号；
		mat ans(r,r),tmp(r,r);
		memcpy(tmp.m,m,sizeof(tmp.m));
		ans.clear();
		for(int i=1;i<=ans.r;i++){
			ans.m[i][i]=1;
		}
		while(n){
			if(n&1)ans=ans*tmp;
			n>>=1;
			tmp=tmp*tmp;
		}
		return ans;
	}

	void print()const{
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				printf("%lf",m[i][j]);
				if(j==c)printf("\n");
				else printf(" ");
			}
		}
	}

};

int head[55],nxt[2550],point[2550],size;
int num[55];
double ans[55];
void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	num[a]++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
	num[b]++;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,d;
		scanf("%d%d%d",&n,&m,&d);
		memset(head,-1,sizeof(head));
		memset(num,0,sizeof(num));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		mat ma(n,n);
		ma.clear();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j)ma.m[i][j]=1.0/n;
				else ma.m[i][j]=0;
			}
		}
		mat b(n,n);
		b.clear();
		for(int i=1;i<=n;++i){
			for(int j=head[i];~j;j=nxt[j]){
				int k=point[j];
				b.m[i][k]=1.0/num[i];
			}
		}
//		mat aa=ma*(b^d);
		mat aa=b;
		for(int i=1;i<d;++i){
			aa=aa*b;
		}
		aa=ma*aa;
		for(int i=1;i<=n;++i){
			ans[i]=0;
			for(int j=1;j<=n;++j)ans[i]+=aa.m[j][i];
		}
		for(int i=1;i<=n;++i)printf("%.10lf\n",ans[i]);
	}
	return 0;
}
