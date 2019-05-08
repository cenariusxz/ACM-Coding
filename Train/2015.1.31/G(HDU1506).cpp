#include<stdio.h>
#include<stack>
using namespace std;
struct node{
	int h,num;
};
int n,h[100002];

 void run()
 {
 	int i,count;
 	long long max=0;
 	node tmp;
 	stack<node> s;
 	h[n+1]=0;
 	for(i=1;i<=n+1;i++){
 		if(s.empty()||h[i]>=s.top().h){
 			tmp.h=h[i];
 			tmp.num=1;
 			s.push(tmp);
 			continue;
 		}
 		count=0;
 		while(!s.empty()&&s.top().h>h[i]){
 			count+=s.top().num;
 			if((long long)count*(long long)s.top().h>max) max=(long long)count*(long long)s.top().h;
 			s.pop();
 		}
 		if((long long)count*(long long)h[i]>max) max=(long long)count*(long long)h[i];
 		tmp.h=h[i];
 		tmp.num=count+1;
 		s.push(tmp);
 	}
 	printf("%I64d\n",max);
 }
int main()
{
	int i;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		run();
	}
 return 0;
}

