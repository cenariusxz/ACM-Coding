#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=110000;

ll st[maxn<<2],add[maxn<<2],cha[maxn<<2],mi[maxn<<2],ma[maxn<<2];
int n,m;

namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
int sq[10000010];
const int NN=10000000;

inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}

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

inline ll Sqrt(ll a){
	if(a<NN)return sq[a];
	return trunc(sqrt(a)+1e-8);
}

inline void pushup(int o){
	st[o]=st[o<<1]+st[o<<1|1];
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
}

void build(int o,int l,int r){
	cha[o]=-1;add[o]=0;
	if(l==r){read(st[o]);ma[o]=mi[o]=st[o];return;}
	int m=l+((r-l)>>1);build(o<<1,l,m);build(o<<1|1,m+1,r);
	pushup(o);
}

inline void change(int o,int l,int r,ll c){
	add[o]=0;cha[o]=c;st[o]=c*(r-l+1);mi[o]=ma[o]=c;
}

inline void Plus(int o,int l,int r,ll c){
	if(cha[o]!=-1)cha[o]+=c;else add[o]+=c;
	st[o]+=c*(r-l+1);mi[o]+=c;ma[o]+=c;
}

inline void pushdown(int o,int l,int r){
	int m=l+((r-l)>>1);
	if(cha[o]!=-1){
		change(o<<1,l,m,cha[o]);change(o<<1|1,m+1,r,cha[o]);
		cha[o]=-1;
	}
	else if(add[o]){
		Plus(o<<1,l,m,add[o]);Plus(o<<1|1,m+1,r,add[o]);
		add[o]=0;
	}
}

void Add(int o,int l,int r,int ql,int qr,int c){
	if(r<ql||l>qr)return;
	if(ql<=l&&qr>=r){Plus(o,l,r,c);return;}
	int m=l+((r-l)>>1);pushdown(o,l,r);
	if(ql<=m)Add(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)Add(o<<1|1,m+1,r,ql,qr,c);
	pushup(o);
}

void solve(int o,int l,int r,int ql,int qr){
	ll k2=Sqrt(mi[o]);
	if(mi[o]==ma[o])change(o,l,r,k2);
	else{
		ll k3=Sqrt(ma[o]);
		if(k2==k3)change(o,l,r,k2);
		else Plus(o,l,r,k2-mi[o]);
	}
}

void Sq(int o,int l,int r,int ql,int qr){
	if(r<ql||l>qr)return;
	if(ql<=l&&qr>=r&&ma[o]-mi[o]<=1){solve(o,l,r,ql,qr);return;}
	int m=l+((r-l)>>1);pushdown(o,l,r);
	if(ql<=m)Sq(o<<1,l,m,ql,qr);
	if(qr>=m+1)Sq(o<<1|1,m+1,r,ql,qr);
	pushup(o);
}

ll query(int o,int l,int r,int ql,int qr){
	if(r<ql||l>qr)return 0;
	if(ql<=l&&qr>=r)return st[o];
	int m=l+((r-l)>>1);pushdown(o,l,r);
	return query(o<<1,l,m,ql,qr)+query(o<<1|1,m+1,r,ql,qr);
}

void run(){
	read(n);read(m);build(1,1,n);
	while(m--){
		int type,l,r;read(type);read(l);read(r);
		if(type==1){int c;read(c);Add(1,1,n,l,r,c);}
		else if(type==2)Sq(1,1,n,l,r);
		else if(type==3)println(query(1,1,n,l,r));
//		else if(type==3)printf("%lld\n",query(1,1,n,l,r));
	}
}

int main(){
	for (int i=1;i*i<=NN;i++){
		int l=i*i,r=min(NN,(i+1)*(i+1)-1);
		for (int j=l;j<=r;j++)sq[j]=i;
	}
	int T;read(T);
	while(T--)run();
	return 0;
}
