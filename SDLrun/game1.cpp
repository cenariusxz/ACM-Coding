#include<stdio.h>
#include"game.h"
#include"head.h"
#include<time.h>
#include<queue>
#include<stdlib.h>


const int INF=0x3f3f3f3f;			//极大值
const int Grid_Len = 40;			//格子像素
const int Grid_N = 13;				//地图尺寸x
const int Grid_M = 15;				//地图尺寸y
const int Bomb_Time = 5000000;		//炸弹爆炸时间
const int Move_Stop = 0;			//移动状态
const int Move_Left = 1;
const int Move_Right = 2;
const int Move_Up = 3;
const int Move_Down = 4;
const int Move_Time = 40000;		//移动基础时间
const int Decide_Time = 20000;		//决策间隔时间
const int Line_Time = 1000000;


//移动方向向量
int Move_x[5]={0,-1,1,0,0};
int Move_y[5]={0,0,0,-1,1};

//地图信息
int Map[Grid_N][Grid_M];
//0表示空，1表示障碍物，2表示墙
//3表示炸弹

//危险格子信息
int DangerMap[Grid_N][Grid_M];

//炸弹分布信息
Bomb BombMap[Grid_N][Grid_M];

//炸弹效果
int LineMap[Grid_N][Grid_M];
int LineTime[Grid_N][Grid_M];

//玩家
Bomberman Player[4];

int Move[4];				//移动状态
int IsMoving[4];			//移动半格状态
int MoveTime[4];			//上次移动时间
int PutBomb[4];				//放置炸弹状态
int DecideTime;				//电脑决策时间

//用于AI寻找最近安全格子的node结构体
struct node{
	int x,y,move;
	node(){}
	node(int _x,int _y,int _mo):x(_x),y(_y),move(_mo);
};
//用于BFS时保证不会重复搜索
int vis[Grid_N][Grid_M];

//单人游戏
void Run1();

//多人游戏
void Run2();

//从文件中得到地图信息
void GetMap();

//搜索安全格子行走路线
int BFS(int,int);

//检查在某个格子放置炸弹是否会是自己无法逃脱
bool CheckBomb(int,int);

//查看一个坐标是否出界
bool notOut(int,int);

//
void UpdateMap(int,int,int);

int main(){
	srand(time(NULL));
	Init();

	

	SDL_quit();
}


//----------------------------单人游戏-----------------------
void Run1(){

	//得到地图信息
	GetMap();
	
	//初始化炸弹人
	Player[i] = Bomberman();
	
	//初始化危险格子、炸弹效果
	memset( DangerMap , 0 , sizeof( SaveMap ));
	memset( LineMap , 0 , sizeof( LineMap ));

	//初始化移动、炸弹标记、决策间隔时间
	memset( Move , 0 , sizeof( Move ));
	memset( IsMoving , 0 , sizeof( IsMoving ));
	for( int i = 0 ; i < 4 ; ++i ) MoveTime[i] = -INF ;
	memset( PutBomb , 0 , sizeof( PutBomb ));
	DecideTime = -INF ;

	//窗口退出
	bool Over = 0 ;
	
	while(!Over){
		SDL_Event event;



		//事件监听
		//关闭游戏
		//P1移动、放置炸弹
		while(SDL_PollEvent( &event )){
			switch(event.type)
			{
				case SDL_QUIT:			//退出游戏
					Over = 1;
					break;
				//松开按键：玩家移动、放置炸弹
				case SDL_KEYUP:	
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							Over = 1;
							break;
						case SDLK_UP:
							if(Move[0] == Move_Up)
								Move[0] = Move_Stop ;
							break;
						case SDLK_DOWN:
							if(Move[0] == Move_Down)
								Move[0] = Move_Stop ;
							break;
						case SDLK_LEFT:
							if(Move[0] == Move_Left)
								Move[0] = Move_Stop ;
							break;
						case SDLK_RIGHT:
							if(Move[0] == Move_Right)
								Move[0] = Move_Stop ;
							break;
						case SDLK_SPACE:
							PutBomb[0] = 0;
							break;
						default:
							break;
					}
					break;
				//按下按键：玩家移动、放置炸弹
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_UP:
							Move[0] = Move_Up ;
							break;
						case SDLK_DOWN:
							Move[0] = Move_Down ;
							break;
						case SDLK_LEFT:
							Move[0] = Move_Left ;
							break;
						case SDLK_RIGHT:
							Move[0] = Move_Right ;
							break;
						case SDLK_SPACE:
							PutBomb[0] = 1 ;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}



		int now = clock() ;		//当前时间



		//电脑决策移动、放置炸弹
		if( now - DecideTime >= Decide_Time ){
			DecideTime = now ;
			for( int i = 1 ; i < 4 ; ++i ){
				if( Player[i].Life() == 0 )continue;	//死亡的电脑

				int nowx = Player[i].Getx();
				int nowy = Player[i].Gety();
				int next_move = 0;

				//如果处在危险格子，优先逃跑（BFS）
				if( DangerMap[nowx][nowy] ){

					//控制主动逃跑的频率
					if( rand() % 100 < 80 )continue;

					next_move = BFS( nowx , nowy );

					//若无法走到安全格子，随机行走
					if( !next_move ) next_move = rand()%5 ;
					Move[i] = next_move;
				}
				//处于安全位置
				else{
					//一定概率选择放炸弹、移动、不作为

					int type = rand() % 100 ;
					if( type < 5 ){		//放炸弹
						//确定是否可以放置炸弹
						if( PutBomb[i] == 0 && 
								Player[i].GetBombrest() ){
							int flag = CheckBomb( nowx , nowy );
							if( flag )PutBomb[i] = 1 ;
						}
					}
					else if( type < 35 ){	//移动
						//随机移动方向，但保证不移动到危险格子
						//随机方式：随机初始确定的方向，从该方向开始找到第一个安全的方向
						int t = rand() % 4 + 1 ;
						for( int j = 0 ; j < 4 ; ++j ){
							int tmp_move = t + j;
							if( tmp_move > 4 ) tmp_move -= 4;
							int dx = nowx + Move_x[ tmp_move ];
							int dy = nowy + Move_y[ tmp_move ];
							if( notOut( dx , dy ) ){
								if( DangerMap[dx][dy] == 0 ){
									next_move = tmp_move ;
									break;
								}
							}
						}
						Move[i] = next_move;
					}
				}
			}
		}



		//炸弹人放置炸弹
		for( int i = 0 ; i < 4 ; ++i ){
			//炸弹人死亡
			if( Player[i].Life() == 0 )continue;
			//没有炸弹了
			if( Player[i].GetBombrest == 0 )continue;


			if( PutBomb[i] ){
				int nowx = Player[i].Getx();
				int nowy = Player[i].Gety();
				if( Map[nowx][nowy] != 3){
					Bomb[nowx][nowy] = Player[i].PutBomb(now);

					//计算危险格子
					DangerMap[nowx][nowy] ++;
					int tmpx,tmpy;
					for( int j = 1 ; j <= 4 ; ++j ){
						tmpx=nowx;
						tmpy=nowy;
						for( int k = 1 ; k <= Player[i].GetPow() ; ++k ){
							tmpx += Move_x[j];
							tmpy += Move_y[j];

							if( !notOut( tmpx , tmpy ) )break;
							if( Map[tmpx][tmpy] == 1 ||
									Map[tmpx][tmpy] == 2 ){
								break;
							}
							DangerMap[tmpx][tmpy] ++;
						}
					}

				}
				if( i > 0 ) PutBomb[i]=0;
			}
		}




		//炸弹人移动
		for( int i = 0 ; i < 4 ; ++i ){
			//炸弹人死亡
			if( Player[i].Life() == 0 )continue;
			if( now - MoveTime[i] >
					( MAXSPEED - Player[i].Getspeed() + 1 )
					* Move_Time / MAXSPEED ){
				//移动半格
				if( IsMoving[i] != Move_Stop ){
					Player[i].Setx( Player[i].Getx() + Move_x[ IsMoving[i] ] );
					Player[i].Sety( Player[i].Gety() + Move_y[ IsMoving[i] ] );
					int nowx=Player[i].Getx();
					int nowy=Player[i].Gety();
					if( LineMap[nowx][nowy] ){
						Player[i].Die();
					}
					IsMoving[i] = Move_Stop ;
				}
				//准备移动
				else if( Move[i] != Move_Stop ){
					int tmpx = Player[i].Getx() + Move_x[ Move[i]];
					int tmpy = Player[i].Gety() + Move_y[ Move[i]];
					if( notOut( tmpx , tmpy ) ){
						int tmpMap = Map[tmpx][tmpy] ;
						if( tmpMap == 0 || tmpMap > 3){
							IsMoving[i] = Move[i];
						}
					}
					if( i > 0 ) Move[i] = Move_Stop ;
				}
				MoveTime[i]=now;
			}
		}

		//更新原有炸弹效果
		for( int i = 0 ; i < Grid_N ; ++i ){
			for( int j = 0 ; j < Grid_M ; ++j ){
				if( LineMap[i][j] ){
					if( now - LineTime[i][j] > Line_Time ){
						LineMap[i][j]=0;
					}
				}
			}
		}

		//炸弹爆炸
		for( int i = 0 ; i < Grid_N ; ++i ){
			for( int j = 0 ; j < Grid_M ; ++j ){
				if( Map[i][j] == 3 ){
					if( now - Bomb[i][j].time > Bomb_Time ){

						//将 i j 炸弹爆炸
						UpdateMap( i , j , now );
					}
				}
			}
		}
		
		
	}
}

void GetMap(){
	
}

int BFS( int nowx , int nowy ){
	queue<node>Q;
	memset(vis,0,sizeof(vis));

	//将周围可以走的格子加入队列
	for( int j = 1 ; j <= 4 ; ++j ){
		int dx = nowx + Move_x[j];
		int dy = nowy + Move_y[j];
		if( notOut( dx , dy ) ){
			int dMap = Map[dx][dy] ;
			if( dMap == 0 || dMap > 3){
				Q.push( node( dx , dy , j ) );
			}
		}
	}

	//寻找第一个安全的格子
	while(!Q.empty()){
		node u = Q.front();
		Q.pop();
		if( DangerMap[u.x][u.y]==0 ){
			return u.move;
		}
		for( int j = 1 ; j <= 4 ; ++j ){
			int dx = u.x + Move_x[j];
			int dy = u.y + Move_y[j];
			if( notOut( dx , dy ) ){
				int dMap = Map[dx][dy] ;
				if( dMap == 0 || dMap > 3){
					Q.push( node( dx , dy , u.move ) );
				}
			}
		}
	}
	
	return 0;
}

bool notOut( int nowx , int nowy ){
	return nowx >= 0 && nowx < Grid_N && nowy >= 0 && nowy < Grid_M;
}

int CheckBomb( int nowx , int nowy ,int power){
	DangerMap[nowx][nowy] ++;
	int tmpx,tmpy;
	
	for( int i = 1 ; i <= 4 ; ++i ){
		tmpx=nowx;
		tmpy=nowy;
		for( int j = 1 ; j <= power ; ++j ){
			tmpx += Move_x[i];
			tmpy += Move_y[i];

			if( !notOut( tmpx , tmpy ) )break;
			if( Map[tmpx][tmpy] == 1 ||
					Map[tmpx][tmpy] == 2 ){
				break;
			}
			DangerMap[tmpx][tmpy] ++;
		}
	}

	int ans = BFS( nowx , nowy );

	DangerMap[nowx][nowy] --;
	for( int i = 1 ; i <= 4 ; ++i ){
		tmpx=nowx;
		tmpy=nowy;
		for( int j = 1 ; j <= power ; ++j ){
			tmpx += Move_x[i];
			tmpy += Move_y[i];

			if( !notOut( tmpx , tmpy ) )break;
			if( Map[tmpx][tmpy] == 1 ||
					Map[tmpx][tmpy] == 2 ){
				break;
			}
			DangerMap[tmpx][tmpy] --;
		}
	}
	
	return ans;
}

void UpdateMap( int nowx , int nowy ,int time){
	Map[nowx][nowy] = 0 ;
	DangerMap[nowx][nowy] -- ;
	///////////////
	LineMap[nowx][nowy] = ;
	LineTime[nowx][nowy] = time ;
	int pow = Bomb[nowx][nowy].GetPow();
	Bomb[nowx][nowy].Die();

	int tmpx,tmpy,prex,prey;
///////////////////////	
	for( int i = 1 ; i <= 4 ; ++i ){
		tmpx=nowx;
		tmpy=nowy;
		for( int j = 1 ; j <= pow ; ++j ){
			tmpx += Move_x[i];
			tmpy += Move_y[i];

			if( !notOut( tmpx , tmpy ) )break;
			if( Map[tmpx][tmpy] == 1 ||
					Map[tmpx][tmpy] == 2 ){
				break;
			}
			DangerMap[tmpx][tmpy] ++;
		}
	}



}
