#ifndef CARTOON_1_H
#define CARTOON_1_H
#include"pooyan.h"
extern int act = 0;  //控制游戏关卡
extern int num = 0;  //控制过关
extern int num_2 = 0;
class CARTOON_1  //动画一相关数据
{
private:
	IMAGE bk;
	IMAGE pooyan_pink_3_bk_next, pooyan_pink_3_next, pooyan_pink_4_bk_next, pooyan_pink_4_next;
	IMAGE wolf_3_bk_right, wolf_3_right, wolf_4_bk_right, wolf_4_right;
	IMAGE pooyan_pink_3, pooyan_pink_3_bk, pooyan_pink_4, pooyan_pink_4_bk;
	IMAGE pooyan_red_3, pooyan_red_3_bk, pooyan_red_4, pooyan_red_4_bk;
	IMAGE wolf_3, wolf_3_bk, wolf_4, wolf_4_bk;
	int pooyan_pink_3_x = 640, pooyan_pink_3_y = 425;
	int pooyan_red_3_x = 640, pooyan_red_3_y = 425;
	int pooyan_pink_3_next_x = 240, pooyan_pink_3_next_y = 425;
	int wolf_1_right_x = 0, wolf_1_right_y = 425;
	int wolf_1_left_x = 325, wolf_1_left_y = 425;
public:
	CARTOON_1();

};


# endif //CARTOON_H