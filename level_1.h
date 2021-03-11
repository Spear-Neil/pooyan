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
	int x, y;//��ʼ������
	int down_x, down_y;//��ʼ������ı���
	int status;//��ʼ��״̬
};

class level1_pooyan:public base_level1
{};

class level1_arrow :public base_level1
{
public:
	void setShot(int c) { shot = c; }
	int getShot() { return shot; }
private:
	int shot;//����״̬ -1��δ�������ʧ��1�Ƿ��䣬2����׹
};

class level1_wolf :public base_level1
{
public:
	void setSign(int c) { sign = c; }
	void setInterval(int d) { interval = d; }
	int getSign() { return sign; }
	int getInterval() { return interval; }
private:
	int sign;//�ǵ�״̬ -1��δ���֣�1�Ǵ�2����ǰ������3�ǿ�����׹
	int interval;//��֮��ļ��
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
	int down_x;//�������������
	int sign;//�����״̬ -1��δ���ֻ���ʧ��1�Ǵ��ڣ�2�Ǳ�ը
	int interval;//����֮��ļ��
	int shot;//�޸�bug����ǰ������Ǻ󣬼����ƶ�Ӧ�����ٴ�����������
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
	int sign;//���һȺ�����ӵ����� 0�Ͳ�����1�ͷ�
	int rand_attack_y;//�Ƿ����ӵ���λ��
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
	IMAGE level1_bk;	//����ͼ
	IMAGE level1_pooyan_red_bk, level1_pooyan_red_front;	//�����ͼ
	IMAGE pooyan_red_down_bk, pooyan_red_down_front;
	IMAGE pooyan_red1_down_bk, pooyan_red1_down_front;//������׹
	IMAGE arrow_bk, arrow_front;//�Ǽ���ͼ
	IMAGE arrow_down_front, arrow_down_bk;//�Ǽ���׹��ͼ
	IMAGE level_wolf_bk, level_wolf_front;//�ǵ�ͼ
	IMAGE level1_ball_bk, level1_ball_front;//�����ͼ
	IMAGE ball_red_exploded_bk, ball_red_exploded_front;//����ը��ͼ
	IMAGE rope_bk, rope_front;//���ӵ�ͼ
	IMAGE wolf1_bk_right, wolf1_right, wolf2_bk_right, wolf2_right;//�������ߵ�ͼ
	IMAGE wolf_stop_bk1, wolf_stop_front1, wolf_stop_bk2, wolf_stop_front2;//�Ǳ����е�ͼ
	IMAGE wolf_dead_bk1, wolf_dead_front1, wolf_dead_bk2, wolf_dead_front2;//����׹��ͼ
	IMAGE bullet_bk, bullet_front;//�ӵ���ͼ
	IMAGE bone_bk, bone_front;//��ǰ���ͼ
	IMAGE ball_rise_bk, ball_rise_front;//����������
	level1_pooyan pooyan;
	level1_arrow arrow[ARROW_NUM];//�Ǽ������꣬�ż������飬�жϷż���on_off����ʵ����Ļ��ֻ������֧��
	int const_shot = -1;
	int on_off = 0;//��Ǽ���ص��������ͱ���
	int rand_interval;
	level1_wolf wolf[WOLF_NUM];//�����ǵ�ֻ��
	int wolf_cst;//�ǵ�һֻһֻ����
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