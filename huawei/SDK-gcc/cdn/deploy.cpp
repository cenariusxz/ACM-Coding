#include "deploy.h"
#include <stdio.h>
#include <bitset>
#include <algorithm>
#include <stdio.h>      
#include <string.h>
#include <vector>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <map>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;


const int maxNum = 20; // 遗传群大小
const int maxEdge = 50010;
const int maxNetPoint = 1010;
const int maxConsumePoint = 510;
const int INF = 0x3f3f3f3f;

struct edge {        //边：起点、终点、容量、流量、单位费用
    int from, to, c, f, cost;
    edge(int a, int b, int m, int n, int p): from(a), to(b), c(m), f(n), cost(p) {}
} ;

struct save_edge{
    int a, b, c, v;

    save_edge() {}
    save_edge(int _a, int _b, int _c, int _v): a(_a), b(_b), c(_c), v(_v) {}
    bool operator < (const save_edge x) const {
        return v > x.v;
    }
} saveEdge[maxEdge * 4];

struct save_link{
    int id, a, c;

    save_link() {}
    save_link(int _id, int _a, int _c): id(_id), a(_a), c(_c) {}
} saveLink[maxConsumePoint];

int netNum, netEdgeNum, consumptionNum;
int perCost, sumNeedCost;

vector<int> directLink[maxNetPoint];
vector <vector <int> > route;
map<int,int> Map;

class minCostFlow {
public:
    vector<edge> e;
    vector<int> g[maxNetPoint];
    int dis[maxNetPoint], a[maxNetPoint], p[maxNetPoint];
    bool vis[maxNetPoint] ;

    bool spfa(int& flow,int& cost, int startPoint, int endPoint,int flag = 0){
        for (int i = 0; i <= netNum + 1; ++i) {
            dis[i] = INF, vis[i] = 0;
        }
        // memset(dis, 0x3f,sizeof(dis));
        // memset(vis, 0,sizeof(vis));

        queue<int> q;
        q.push(startPoint);
        vis[startPoint] = 1, dis[startPoint] = 0;
        p[startPoint] = 0, a[startPoint] = INF;

        while (!q.empty()){
            int u = q.front(); q.pop();
            vis[u] = 1;

            for (int i = 0; i < g[u].size(); i++) {
                edge tmp = e[g[u][i]];

                if (dis[tmp.to] > dis[u] + tmp.cost && tmp.c > tmp.f) {
                    dis[tmp.to] = dis[u] + tmp.cost;
                    p[tmp.to] = g[u][i];
                    a[tmp.to] = min(a[u], tmp.c - tmp.f);

                    if (!vis[tmp.to]) {
                        q.push(tmp.to);
                        vis[tmp.to] = 1;
                    }
                }
            }
        }   

        if (dis[endPoint] == INF) return 0;
        flow += a[endPoint], cost += dis[endPoint] * a[endPoint];

        vector<int> tmp_route;
        int u = endPoint;
        while (u != startPoint) {
            e[p[u]].f += a[startPoint];
            e[p[u] ^ 1].f -= a[startPoint];
            u = e[p[u]].from;
            if( flag == 1 && u != startPoint )tmp_route.push_back(u);
        }

        if( flag == 1 ){
            reverse(tmp_route.begin() , tmp_route.end() );
            tmp_route.push_back(Map[tmp_route[ tmp_route.size()-1 ]]);
            tmp_route.push_back(a[endPoint]);
         //   printf("aaaa %d\n",a[endPoint]);
            route.push_back(tmp_route);
        }
        return 1;
    }

    pair<int,int> MF(int startPoint, int endPoint, int serverNum, int ans ,int flag = 0) {
        int flow = 0, cost = 0;
        int step = 0;
        while(spfa(flow, cost, startPoint, endPoint ,flag)) {
        //    printf("cost = %d\n", cost);
        //    if(cost + serverNum * perCost > ans) return make_pair(0,0);
        }
        return make_pair(flow,cost);
    }   

    void init(int n) {        //初始化函数
        for (int i = 0;i < n; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int c, int v) {    //加边函数
        e.push_back(edge(a,b,c,0,v));
        e.push_back(edge(b,a,0,0,-v));
        int m = e.size();
        g[a].push_back(m - 2);
        g[b].push_back(m - 1);
    }

    int solve(vector<int> choose, int ans,bool flag = 0) {
        init(netNum + 5);
        int serverNum = choose.size();
    //    printf("severNum = %d\n", serverNum);

        Map.clear();
        for (int i = 0; i < serverNum; ++i) {
            addEdge(0, choose[i], INF, 0);
        }
        for (int i = 1; i <= netEdgeNum; ++i) {
            addEdge(saveEdge[i].a, saveEdge[i].b, saveEdge[i].c, saveEdge[i].v);
            addEdge(saveEdge[i].b, saveEdge[i].a, saveEdge[i].c, saveEdge[i].v);
        }
        for (int i = 1; i <= consumptionNum; ++i) {
            addEdge(saveLink[i].a, netNum + 1, saveLink[i].c, 0);
            Map[saveLink[i].a ] = saveLink[i].id;
        }

        pair<int, int> result = MF(0, netNum + 1, serverNum, ans ,flag );
        if (result.fi == sumNeedCost){
            
            return result.se + perCost * serverNum;
        }
        else return INF;
    }
} ;

struct Bit {
    bitset<maxNetPoint> choose;
    int cost;

    bool operator < (const Bit& rhs) const {
        return cost < rhs.cost;
    }
} bit[maxNum],bit_ans;

class GeneticAlgorithm {
public:
    int Adjust() {
        sort(bit, bit + maxNum);

        // change suddenly !!!!!
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++j) {
                    int t = rand() % netNum;
                    bit[i + 5].choose[t] = 1 - bit[i].choose[t];
            }
        }

        // cross-change and one seperate line
        int st = 10;
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                
                int mid = rand() % netNum;
                for (int k=0; k <= mid; ++k) bit[st].choose[k] = bit[i].choose[k];
                for (int k=mid+1;k<netNum;++k) bit[st].choose[k]=bit[j].choose[k];
                st++;
            }
        }
        return bit[0].cost;
    }

    vector< vector <int > > Get_Res(){
        route.clear();
        minCostFlow MCMF;
        vector<int> choose;
        for (int i = 0; i <= netNum; ++i) {
            if (bit_ans.choose[i] == 1) {
                choose.pb(i);
            }
        }
        MCMF.solve(choose , INF , 1);
        return route;
    }

    void generate() {
        for (int i = 1; i < maxNum; ++i) {
            bit[i] = bit[0];
            int k = rand() % netNum;
            bit[i].choose[k] = 1 - bit[i].choose[k];
        }
    }

    vector< vector <int > > selectPoint(clock_t startTime) {
        for (int i = 0; i < maxNum; ++i) bit[i].choose.reset();
        // initialize server points

        // firstly, choose all the neighbor netpoint
        for (int i = 1; i <= consumptionNum; ++i) {
            bit[0].choose[saveLink[i].a] = 1;     
        }

        srand(time(NULL));
        generate();
/*
        for (int i = 1; i < maxNum; ++i) {
            // choose the number of server points randomly
            int one;
            if (i & 1) one = rand() % (netNum / 9);
            else one = rand() % (consumptionNum / 3);

            for (int j = 0; j < one ; ++j) {
                int id = rand() % consumptionNum + 1;
                int p = saveLink[id].a;

                int size = directLink[p].size();
                int k = rand() % size;

                bit[i].choose[p] = 0;
                bit[i].choose[directLink[p][k]] = 1;
            }
        }
*/
        int iteratorTime = 100;
        int ans = consumptionNum * perCost;
        int step = 0;

        while (1) {

            for (int i = 0; i < maxNum; ++i) {
                vector<int> can;
                for (int j = 0; j < netNum; ++j) {
                    if (bit[i].choose[j]) can.pb(j);
                }
                minCostFlow test;
                bit[i].cost = test.solve(can, ans);
            //    if (i == 0 && step++ < 20) printf("i = %d cost = %d\n", i, bit[i].cost);
                // bit[i].cost = MaxFlow(can);
            }

            int tmp_ans = Adjust();
            if (tmp_ans < ans) {
                ans = tmp_ans;
                bit_ans.choose = bit[0].choose;
               // printf("%d\n", tmp_ans);
            }
         ///   printf("ans = %d\n", tmp_ans);
            double used = double((clock() - startTime) / CLOCKS_PER_SEC);
        //    if (used > 85) return ans;
            if(used > 85) break;
        }
      //  printf("******%d\n", consumptionNum * perCost);
      //  return ans;
		printf("ans = %d\n", ans);
        return Get_Res();
    }
} ;


void loadParameter(int line_num, char * topo[MAX_EDGE_NUM]) {
    sscanf(topo[0], "%d%d%d", &netNum, &netEdgeNum, &consumptionNum);
    sscanf(topo[2], "%d", &perCost);

    // read net edge information
    int tot = 0, st = 4;
    for (int i = 1; i <= netEdgeNum; ++i) {
        int u, v, a, b;
        sscanf(topo[st++], "%d %d %d %d", &u, &v, &a, &b);

        directLink[u].pb(v);
        directLink[v].pb(u);

        saveEdge[i] = save_edge(u, v, a, b);
    }
    sort(saveEdge + 1, saveEdge + netEdgeNum + 1);
    sumNeedCost = 0;

    st++;

    // read consumption information
    for (int i = 1; i <= consumptionNum; ++i) {
        int a, b, c;
        sscanf(topo[st++], "%d%d%d", &a, &b, &c);

        sumNeedCost += c;
        saveLink[i] = save_link(a, b, c);
    }
}


//你要完成的功能总入口
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
    clock_t startTime = clock();
    loadParameter(line_num, topo);
    for (int j = 0; j < maxNetPoint; ++j) directLink[j].clear();
    GeneticAlgorithm test;
    vector< vector<int> > route = test.selectPoint(startTime);

    string ret = "";

    char buf[20];
    sprintf(buf, "%d", (int)route.size());

    ret+=buf;
	ret+="\n\n";

    for (int i = 0; i < route.size(); ++i) {
        vector<int> now = route[i];
        int size = now.size();
        for (int j = 0; j < size; ++j) {
			char buf[20];
            if (j) ret += " ";
            sprintf(buf, "%d", now[j]);
			ret += buf;
        }
        ret += '\n';
    }
	puts(ret.c_str());
/*
    printf("%d\n", route.size());
    for (int i = 0; i < route.size(); ++i) {
        vector<int> now = route[i];
        int size = now.size();
        for (int j = 0; j < size; ++j) {
            if (j) printf(" ");
            printf("%d", now[j]);
        }
        puts("");
    }
*/
 //   char* topo_file = (char *) ret.c_str();
/*
	// 需要输出的内容
	char * topo_file = (char *)"17\n\n0 8 0 20\n21 8 0 20\n9 11 1 13\n21 22 2 20\n23 22 2 8\n1 3 3 11\n24 3 3 17\n27 3 3 26\n24 3 3 10\n18 17 4 11\n1 19 5 26\n1 16 6 15\n15 13 7 13\n4 5 8 18\n2 25 9 15\n0 7 10 10\n23 24 11 23";
*/
	// 直接调用输出文件的方法输出到指定文件中(ps请注意格式的正确性，如果有解，第一行只有一个数据；第二行为空；第三行开始才是具体的数据，数据之间用一个空格分隔开)
//	write_result(topo_file, filename);
	write_result(ret.c_str(), filename);

}
