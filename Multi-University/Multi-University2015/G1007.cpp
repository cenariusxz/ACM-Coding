#include<stdio.h>
#include<string.h>

char s[200005];
int a[200005];
int sum1[200005],sum2[200005];
int ss[200005];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s",s);
		int n=strlen(s);
		int i;
		sum1[0]=0;
		sum2[0]=0;
		ss[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i%2){
				sum1[i]=sum1[i-1]+a[i];
				sum2[i]=sum2[i-1];
			}
			else{
				sum1[i]=sum1[i-1];
				sum2[i]=sum2[i-1]+a[i];
			}
			ss[i]=ss[i-1]+a[i];
		}
		int pos=-1;
		for(i=0;i<n;i++){
			if(s[i]=='0'||s[i]=='1'){
				pos=i;
				break;
			}
		}
		int f=-1;
		int num=0;
		int sum=0;
		int pre=0;
		if(pos==-1)sum=ss[n];
		else{
			for(i=0;i<=n;i++){
				int p=(pos+i)%n;
				if(s[p]=='?'){
					num++;
				}
				else if(s[p]=='0'){
					if(num==0){
						if(f==1)sum+=a[p+1];
						f=0;
						pre=p;
					}
					else{
						if(((num%2)&&f==0)||(num%2==0&&f==1)){
							if(pre>p||pre==p){
								sum+=ss[p+1]+ss[n]-ss[pre+1];
							}
							else{
								sum+=ss[p+1]-ss[pre+1];
							}
						}
						else if(((num%2)&&f==1)||(num%2==0&&f==0)){
							if(pre>p||pre==p){
								if(n%2){
									sum+=max(sum1[p+1]+sum2[n]-sum2[pre+1],sum2[p+1]+sum1[n]-sum1[pre+1]);
								}
								else sum+=max(sum1[p+1]+sum1[n]-sum1[pre+1],sum2[p+1]+sum2[n]-sum2[pre+1]);
							}
							else{
								sum+=max(sum1[p+1]-sum1[pre+1],sum2[p+1]-sum2[pre+1]);
							}
						}
						f=0;
						num=0;
						pre=p;
					}
				}
				else if(s[p]=='1'){
					if(num==0){
						if(f==0)sum+=a[p+1];
						f=1;
						pre=p;
					}
					else{
						if(((num%2)&&f==1)||(num%2==0&&f==0)){
							if(pre>p){
								sum+=ss[p+1]+ss[n+1]-ss[pre+1];
							}
							else sum+=ss[p+1]-ss[pre+1];
						}
						else if(((num%2)&&f==0)||(num%2==0&&f==1)){
							if(pre>p){
								if(n%2){
									sum+=max(sum1[p+1+1]+sum2[n]-sum2[pre+1],sum2[p+1]+sum1[n+1]-sum1[pre+1]);
								}
								else sum+=max(sum1[p+1]+sum1[n+1]-sum1[pre+1],sum2[p+1]+sum2[n+1]-sum2[pre+1]);
							}
							else{
								sum+=max(sum1[p+1]-sum1[pre+1],sum2[p+1]-sum2[pre+1]);
							}
						}
						f=1;
						num=0;
						pre=p;
					}
				}
			}
		}
		printf("Case #%d: %d\n",q,sum);
	}
	return 0;
}
