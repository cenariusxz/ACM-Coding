#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxm=100005;

int a[maxm],ans1[maxm<<1],ans2[maxm<<1];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int n,p1,p2;
ll ave;

bool judge(){
	int ff=0;
	for(int i=1;i<=n;i++){
		if(ff==1){
			if(a[i]>ave||a[i]<ave-2)return 0;
			else if(a[i]==ave-1)ff=0;
			else if(a[i]==ave-2)ff=-1;
			ans1[p1]=i-1;
			ans2[p1++]=i;
		}
		else if(ff==-1){
			if(a[i]<ave||a[i]>ave+2)return 0;
			else if(a[i]==ave+1)ff=0;
			else if(a[i]==ave+2)ff=1;
			ans1[p2]=i;
			ans2[p2--]=i-1;
		}
		else{
			if(a[i]<ave-1||a[i]>ave+1)return 0;
			else if(a[i]==ave+1)ff=1;
			else if(a[i]==ave-1)ff=-1;
		}
	}
	return 1;
}

int main(){
	int T=read();
	while(T--){
		n=read();
		int i;
		ll sum=0;
		for(i=1;i<=n;i++){
			a[i]=read();
			sum+=a[i];
		}
		ave=sum/n;
		if(ave*n!=sum){
			printf("NO\n");
			continue;
		}
		bool f=1;
		for(i=1;i<=n;i++){
			if(a[i]>ave+2||a[i]<ave-2)f=0;
			else if((a[i]==ave+2||a[i]==ave-2)&&n==2)f=0;
		}
		if(!f){printf("NO\n");continue;}
		p1=1;p2=2*n;
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		if(!judge()){
		//	printf("aaa\n");
			a[1]++;a[n]--;p1=1;p2=2*n;
			memset(ans1,0,sizeof(ans1));
			memset(ans2,0,sizeof(ans2));
			if(a[n]<0){
				ans1[p2]=n;
				ans2[p2--]=1;
			}
			else{
				ans1[p1]=n;
				ans2[p1++]=1;
			}
			if(!judge()){
		//		printf("bbb\n");
				p1=1;p2=2*n;a[1]-=2;a[n]+=2;
				memset(ans1,0,sizeof(ans1));
				memset(ans2,0,sizeof(ans2));
				if(a[1]<0){
					ans1[p2]=1;
					ans2[p2--]=n;
				}
				else{
					ans1[p1]=1;
					ans2[p1++]=n;
				}
				if(!judge()){
					printf("NO\n");
					continue;
				}
			}
		}
		printf("YES\n%d\n",p1+(2*n-p2-1));
		for(i=1;i<=2*n;i++){
			if(ans1[i]==0&&ans2[i]==0)continue;
			printf("%d %d\n",ans1[i],ans2[i]);
		}
	}
	return 0;
}
