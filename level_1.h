#ifndef  LEVEL_1_H
#define LEVEL_1_H
#include "pooyan.h"

class base_level1 
{
public:	
	virtual void setX(int a) { x = a; }
	virtual void setY(int b) { y = b; }
	virtual void setStatus(int c) { status = c; }
	virtual void setDownX(int e) { down_x = e; }
	virtual void setDownY(int f) { down_y = f; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int getDownX() { return down_x; }
	virtual int getDownY() { return down_y; }
	virtual int getStatus() { return status; }
private:
	int x, y;//初始化坐标
	int down_x, down_y;//初始化坐标改变量
	int status;//初始化状态
};

class level1_pooyan:public base_level1
{};

class level1_arrow :public base_level1
{
public:
	void setShot(int c) { shot = c; }
	int getShot() { return shot; }
private:
	int shot;//箭的状态 -1是未发射或消失，1是发射，2是下坠
};

class level1_wolf :public base_level1
{
public:
	void setSign(int c) { sign = c; }
	void setInterval(int d) { interval = d; }
	int getSign() { return sign; }
	int getInterval() { return interval; }
private:
	int sign;//狼的状态 -1是未出现，1是存活，2是死前挣扎，3是快速下坠
	int interval;//狼之间的间隔
};

class level1_ball :public base_level1
{
public:
	void setX(int a) { down_x = a; }
	void setSign(int c) { sign = c; }
	void setInterval(int d) { interval = d; }
	void setDownX(int e) { down_x = e; }
	void setShot(int f) { shot = f; }
	int getX() { return down_x; }
	int getSign() { return sign; }
	int getInterval() { return interval; }
	int getShot() { return shot; }
	int getDownX() { return down_x; }
private:
	int down_x;//气球的下落坐标
	int sign;//气球的状态 -1是未出现或消失，1是存在，2是爆炸
	int interval;//气球之间的间隔
	int shot;//修复bug，肉骨棒射中狼后，箭射破对应气球再次死亡的问题
};

class level1_rope :public base_level1
{};

class level1_bullet :public base_level1
{
public:
	void setSign(int c) { sign = c; }
	void setRand(int d) { rand_attack_y = d; }
	int getSign() { return sign; }
	int getRand() { return rand_attack_y; }
private:
	int sign;//随机一群发射子弹的狼 0就不发，1就发
	int rand_attack_y;//狼发射子弹的位置
};

class level1_bone :public base_level1
{
public:
	void setX(float a) { x = a; }
	void setY(float b) { y = b; }
	void setvx(float d) { vx = d; }
	void setvy(float e) { vy = e; }
	void setStatus(int c) { status = c; }
	void setOn_off(int f) { on_off = f; }
	void setAwake(int i) { awake = i; }
	float getX() { return x; }
	float getY() { return y; }
	float getvx() { return vx; }
	float getvy() { return vy; }
	int getStatus() { return status; }
	int getOn_off() { return on_off; }
	int getAwake() { return awake; }
private:
	float x;
	float y;
	float vx;
	float vy;
	int status;
	int on_off;
	int awake;
};

class level1
{
public:
	IMAGE level1_bk;	//背景图
	IMAGE level1_pooyan_red_bk, level1_pooyan_red_front;	//猪妈的图
	IMAGE pooyan_red_down_bk, pooyan_red_down_front;
	IMAGE pooyan_red1_down_bk, pooyan_red1_down_front;//猪妈下坠
	IMAGE arrow_bk, arrow_front;//骨箭的图
	IMAGE arrow_down_front, arrow_down_bk;//骨箭下坠的图
	IMAGE level_wolf_bk, level_wolf_front;//狼的图
	IMAGE level1_ball_bk, level1_ball_front;//气球的图
	IMAGE ball_red_exploded_bk, ball_red_exploded_front;//气球爆炸的图
	IMAGE rope_bk, rope_front;//绳子的图
	IMAGE wolf1_bk_right, wolf1_right, wolf2_bk_right, wolf2_right;//狼向右走的图
	IMAGE wolf_stop_bk1, wolf_stop_front1, wolf_stop_bk2, wolf_stop_front2;//狼被击中的图
	IMAGE wolf_dead_bk1, wolf_dead_front1, wolf_dead_bk2, wolf_dead_front2;//狼下坠的图
	IMAGE bullet_bk, bullet_front;//子弹的图
	IMAGE bone_bk, bone_front;//肉骨棒的图
	IMAGE ball_rise_bk, ball_rise_front;//上升的气球
	level1_pooyan pooyan;
	level1_arrow arrow[ARROW_NUM];//骨箭的坐标，放箭的数组，判断放箭，on_off用来实现屏幕中只存在两支箭
	int const_shot = -1;
	int on_off = 0;//与骨箭相关的两个整型变量
	int rand_interval;
	level1_wolf wolf[WOLF_NUM];//定义狼的只数
	int wolf_cst;//狼的一只一只出现
	level1_ball ball[WOLF_NUM];
	int ball_cst;
	level1_rope rope;
	level1_bullet bullet[WOLF_NUM];
	level1_bone bone;
	void show_1();
	void update_without_input_1();
	void update_with_input_1();
	void startup_1();
};
#endif  //LEVEL1CLASSES_H