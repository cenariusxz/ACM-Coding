#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std ;
typedef long long ll;
const int maxn = 1e6 + 5;
const int maxm = 1e7 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int head[maxn];
int point[maxm],nxt[maxm],val[maxm],size;

void init(){
	memset(head,-1,sizeof(head));
	size = 0;	
}

void add(int a,int b,int v){
	point[size] = b;
	val[size] = v;
	nxt[size] = head[a];
	head[a] = size++;
}

ll dis[maxn];
bool vis[maxn];
int n,m,T,rxa,rxc,rya,ryc,rp;

struct node{
    int left,right,child;	//left�����׻���  right���ܵ� 
}ph[maxn];
int sta[maxn], top;
int root = 0 ;

int Merge(int v, int u){	// �� dis ֵ��Ϊ���ȼ�����С����Ϊ�Ѷ� 
    if(dis[v] < dis[u])swap(v,u);	// ��֤ u ��Ϊ v �ĸ��� 
    ph[v].left = u, ph[v].right = ph[u].child, ph[ ph[u].child ].left = v; 
    ph[u].child = v;
    return u;
}

void Push(int v){			// v��Ϊһ���Ѻϲ������� 
    if(!root)root = v;
	else root = Merge(root,v);
}

int Top(){					// ���ضѶ� 
    return root;
}

void Update(int v){			// �޸� v ��ֵ 
    if(v != root){
        if(ph[ ph[v].left ].child == v){	// �Ͽ� v ����ԭ�ȵ�left��right������ 
            ph[ ph[v].left ].child = ph[v].right;
        }
		else{
            ph[ ph[v].left ].right = ph[v].right;
        }
        if(ph[v].right)ph[ ph[v].right ].left = ph[v].left;
        ph[v].left = ph[v].right = 0;
        root = Merge(root,v);
    }
}

void Pop(){					// ɾ���Ѷ� 
    if(!ph[root].child)root = 0;
	else{
        top = 0;
        int t = ph[root].child;
        while(t){	// �����ϲ���ջ 
            if(ph[t].right){	// t �� t.right �ϲ� 
                int k = ph[ ph[t].right ].right;
                int v = ph[t].right;		// t - v - k 
                ph[t].left = ph[t].right = ph[v].left = ph[v].right = 0 ;
                sta[++top] = Merge(v,t);
                t = k;
            }
			else{
                sta[++top] = t;
                ph[t].left = ph[t].right = 0;
                break;
            }
        }
        root = sta[top];		// ��ջ�ڽ����кϲ� 
        for(int i = top - 1 ; i >= 1 ; -- i)root = Merge(root,sta[i]);
    }
}
 
void dij(int s,int t){
    memset(vis+1, 0, n*sizeof(bool));
    memset(dis+1, 0x3f, n*sizeof(ll));
    dis[s] = 0;
	Push(s),vis[s] = 1;
    for(int k = 1 ; k <= n ; ++ k){
        int u = Top(); Pop();
		vis[u] = 0;
        if(u == t)break;
        for(int i = head[u] ; ~ i ; i = nxt[i]){
        	int j = point[i];
			if(dis[j] > dis[u] + val[i]){
	            dis[j] = dis[u] + val[i];
	            if(!vis[j])Push(j),vis[j]=1;
				else Update(j);
	        }
	    }
    }
    printf("%lld\n",dis[t]);
}
 
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d%d%d",&T,&rxa,&rxc,&rya,&ryc,&rp);
    init();
    ll x=0, y=0, z=0;
    for(int i = 1 ; i <= T ; ++ i){
        x = (x * rxa + rxc) % rp;
        y = (y * rya + ryc) % rp;
        int a = min(x % n + 1, y % n + 1);
		int b = max(y % n + 1, y % n + 1);
        int d = 100000000 - 100 * a;
        add(a,b,d);
    }
    for (int i = T + 1 ; i <= m ; ++ i){
        int s,t,d; 
		scanf("%d%d%d",&s,&t,&d);
        add(s,t,d);
    }
    dij(1,n);
    return 0 ;
}
