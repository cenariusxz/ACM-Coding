//#include "head.h"
#include<iostream>
#include<SDL/SDL.h>
#include<string>

using namespace std;

const int LIVE = 1;
const int MAXSPEED=4;

class Object {
private:
	int x,y;
//	SDL_Surface *pic;
public:
	const int Getx();
	const int Gety();
	void Setx(int);
	void Sety(int);
	Object();
	Object( int , int ,string);
};

class Buff : public Object {

};

class Obstacle : public Object {
public:
	Buff Die();			//障碍物摧毁（掉落buff）
};

class Bomberman : public Object {
private:
	int id;				//炸弹人编号
//	int sta;			//当前状态
	int Bombsum;		//炸弹总数
	int Bombrest;		//剩余炸弹数
	int pow;			//炸弹范围
	int speed;			//移动速度
	int life;			//生命数
public:
	Bomberman();
	Bomberman(int,int,string,int);
	void Die();
	const int GetSpeed();		//查询速度
	const int Life();			//查询是否死亡
	const int GetBombrest();	//查询剩余炸弹数
	const int GetBombsum();
	const int GetPow();
	void SetBombsum();
	void SetBombrest();
};

//--------------------Object---------------------

const int Object::Getx(){return x;}

const int Object::Gety(){return y;}

void Object::Setx(int _x){x=_x;}

void Object::Sety(int _y){y=_y;}

Object::Object(){}

Object::Object( int _x , int _y , string Filename):x(_x),y(_y) {
//	pic=Creat(Filename.c_str());
}

//--------------------Obstacle-------------------

//////////////
Buff Obstacle::Die(){
	Buff tmp;
	return tmp;
}

//--------------------Bomb-----------------------

//-------------------Bomberman-------------------

Bomberman::Bomberman(){}

Bomberman::Bomberman(int _x,int _y,string Filename,int _id):Object(_x,_y,Filename),id(_id),Bombsum(1),Bombrest(1),pow(1),speed(1),life(1){}

const int Bomberman::GetSpeed(){
	return speed;
}

const int Bomberman::Life(){
	return life;
}

const int Bomberman::GetPow(){
	return pow;
}

void Bomberman::Die(){
	life--;
}
