#ifndef LEVEL_2_H
#define LEVEL_2_H

#include"pooyan.h"
class level02
{
private:
	IMAGE level2_bk;	//背景图
	IMAGE stone_bk, stone_front;//石头的图
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

	int pooyan_red_x, pooyan_red_y;//定义猪妈的坐标
	int ball_x[WOLF_NUM_2], ball_y[WOLF_NUM_2];//气球的坐标
	int wolf_x[WOLF_NUM_2], wolf_y[WOLF_NUM_2];//狼的坐标
	int arrow_x[ARROW_NUM], arrow_y[ARROW_NUM];//箭的坐标
	int wolf_sign[WOLF_NUM_2];//标记屏幕上的每一只狼用于判断狼是否出现，-1表示没有出现，1表示出现
	int wolf_count;//用于控制屏幕上每一只狼
	int ball_count;//用于控制屏幕上每一只气球
	int count_shoot;//统计射了几只箭并便于后续控制
	int shoot[ARROW_NUM];//判断是否射射箭的数组，-1表示没有出现，1表示出现
	int rand_space;//随机出现的狼之间的间隔距离，避免重合
	int string_y;//绳子纵坐标
	int wolf_up_x[WOLF_NUM_2];//狼上升的位置的横坐标
	int ball_up_x[WOLF_NUM_2];//气球上升时的横坐标
	int ball_sign[WOLF_NUM_2];//标记每一个气球，-1表示没有出现，1表示出现
	int stone_x;//石头的横纵坐标
	int stone_y;
	int arrow_num;//统计屏幕上箭的个数，确保屏幕上存在箭的个数固定；
	int ball_interval[WOLF_NUM_2];//用来给爆炸后的气球延时处理
	int wolf_interval[WOLF_NUM_2];//给死后的狼延时处理
	int pooyan_red_dead_x;
	int pooyan_red_dead_y;//处理猪妈死亡后的坐标
	int pooyan_exit;//判断猪妈是否存活，1表示存活，2表示中弹死亡
	int put_wolf = 0;//推石头的狼

private:	//函数
	void arrow_level02();//箭的模块
	void stone_pooyan_level02();//石头和猪妈的模块
	void wolves_level02();//狼的模块
	void ballon_level02();//气球的模块
	void count_level02();//记录分数
	void arrow_moive_level02();//箭的移动
	void wolves_moive_level02();//狼和气球的移动
	void judgmentScore_level02();//得分判定
	void body_level02();//尸体处理
	void passOrFailure_levle02();//判断通关与否
		
public:
	void startup_level02();
	void show_level02();
	void update_without_input_level02();
	void update_with_input_level02();
	void end_level02();
};


#endif // !LEVEL_2_H
