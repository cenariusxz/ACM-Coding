#include "deploy.h"
#include <stdio.h>

#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

#define pb push_back

const int NUM = 20;
const int MAX_EDGE = 50010;
const int MAX_NETPOINT = 1010;
const int MAX_CONSUMPTION = 510;

int netNum, netEdgeNum, consumptionNum;
int perCost;
int head[MAX_NETPOINT];

vector<int> choose[NUM];

struct Bit {
	bitset<MAX_NETPOINT> choose;
	int cost;

	bool operator < (const Bit& rhs) const {
		return cost < rhs.cost;
	}
} bit[NUM];

struct Edge {
	int u, v, limit, cost;
	Edge() {}
	Edge(int _u, int _v, int _limit, int _cost) {
		u = _u, v = _v, limit = _limit, cost = _cost;
	}
} edge[MAX_EDGE * 2];

struct Consumption {
	int link, need;
} consumption[MAX_CONSUMPTION];




void loadParameter(int line_num, char * topo[MAX_EDGE_NUM]) {
	sscanf(topo[0], "%d%d%d", &netNum, &netEdgeNum, &consumptionNum);
	sscanf(topo[2], "%d", &perCost);

//	printf("%d %d %d\n%d\n\n", netNum, netEdgeNum, consumptionNum, perCost);
		
	// read net edge information
	int tot = 0, st = 4;
	for (int i = 1; i <= netEdgeNum; ++i) {
		int u, v, a, b;
		sscanf(topo[st++], "%d %d %d %d", &u, &v, &a, &b);

//		printf("%d %d %d %d\n", u, v, a, b);

		edge[tot] = Edge(u, v, a, b);
		head[u] = tot++;
		edge[tot] = Edge(v, u, a, b);
		head[v] = tot++;
	}

	st++;
//	puts("");

	// read consumption information
	for (int i = 1; i <= consumptionNum; ++i) {
		int a, b, c;
		sscanf(topo[st++], "%d%d%d", &a, &b, &c);
//		printf("%d %d %d\n", a, b, c);
		consumption[a].link = b, consumption[a].need = c;
	}
}

void Adjust() {
	sort(bit, bit + NUM);

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
			for (int k = 0; k <= mid; ++k) bit[st].choose[k] = bit[i].choose[k];
			for (int k = mid + 1; k < netNum; ++k) bit[st].choose[k] = bit[j].choose[k];
			st++;
		}
	}

}

void selectPoint() {
	for (int i = 0; i < NUM; ++i) bit[i].choose.reset();
	
	// initialize server points
	
	// firstly, choose all the neighbor netpoint
	for (int i = 1; i <= consumptionNum; ++i) {
		bit[0].choose[consumption[i].link] = 1;		
	}
	
	srand(time(NULL));
	for (int i = 1; i < NUM; ++i) {
		
		// choose the number of server points randomly
		int one;
		if (i & 1) one = rand() % (netNum / 10);
		else one = rand() % (consumptionNum / 5);

		for (int j = 0; j < one ; ++j) {
				bit[i].choose[rand() % netNum] = 1;
		}
	}

	int iteratorTime = 100;

	while (iteratorTime--) {
		for (int i = 0; i < NUM; ++i) {
			vector<int> can;
			for (int j = 0; j < netNum; ++j) {
				if (bit[i].choose[j]) can.pb(j);
			}

//			bit[i].cost = MaxFlow(can);
		}

		Adjust();
	}
	
}

//你要完成的功能总入口
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{	
	for (int i = 0; i < line_num; ++i) {
	//	puts(topo[i]);
	}	

	loadParameter(line_num, topo);

	// 需要输出的内容
	char * topo_file = (char *)"17\n\n0 8 0 20\n21 8 0 20\n9 11 1 13\n21 22 2 20\n23 22 2 8\n1 3 3 11\n24 3 3 17\n27 3 3 26\n24 3 3 10\n18 17 4 11\n1 19 5 26\n1 16 6 15\n15 13 7 13\n4 5 8 18\n2 25 9 15\n0 7 10 10\n23 24 11 23";

	// 直接调用输出文件的方法输出到指定文件中(ps请注意格式的正确性，如果有解，第一行只有一个数据；第二行为空；第三行开始才是具体的数据，数据之间用一个空格分隔开)
	write_result(topo_file, filename);

}
