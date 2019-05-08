int lowbit(int x){return x&(-x);}

void init(int n){
	for(int i=1;i<=n;i++){
		ma[i]=a[i];
		for(int j=1;j<lowbit(i);j<<=1)
			ma[i]=max(ma[i],ma[i-j]);
	}
}

int query(int l,int r){
	int ans=a[r];
	while(1){
		ans=max(ans,a[r]);
		if(l==r)break;
		for(r-=1;r-l>=lowbit(r);r-=lowbit(r))
			ans=max(ans,ma[r]);
	}
	return ans;
}
