#include<stdio.h>
#define ll long long

const int MAXM=100000007;

struct{
	int next[MAXM],head[MAXM],size;
	ll state[MAXM];

	void init(){
		size=0;
		memset(head,-1,sizeof(head));
	}

	bool check(ll val){
		int h=(val%MAXM+MAXM)%MAXM;
		for(int i=head[h];~i;i=next[i]){
			if(state[i]==val)return 1;
		}
		return 0;
	}

	bool insert(ll val){
		int h=(val%MAXM+MAXM)%MAXM;
		for(int i=head[h];~i;i=next[i]){
			if(state[i]==val)return 1;
		}
		state[size]=val;
		next[size]=head[h];
		head[h]=size++;
		return 0;
	}
}H1,H2;
