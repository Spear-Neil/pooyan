#ifndef LEVEL_0_H
#define LEVEL_0_H

#include"pooyan.h"
class LEVEL_0
{
private:
	IMAGE level0_bk;	//±³¾°Í¼
	IMAGE pooyan_blue_0, pooyan_blue_0_bk, pooyan_blue_1, pooyan_blue_1_bk;
	IMAGE pooyan_pink_0, pooyan_pink_0_bk, pooyan_pink_1, pooyan_pink_1_bk;
	IMAGE pooyan_red_0, pooyan_red_0_bk, pooyan_red_1, pooyan_red_1_bk;
	IMAGE ball_0, ball_0_bk, ball_1, ball_1_bk;
	IMAGE wolf_0, wolf_0_bk, wolf_1, wolf_1_bk;
	int pooyan_blue_0_x = 640, pooyan_blue_0_y = 425;
	int pooyan_pink_0_x = 640, pooyan_pink_0_y = 425;
	int pooyan_red_0_x = 640, pooyan_red_0_y = 425;
	int ball_0_x = 640, ball_0_y = 400;
	int wolf_0_x = 640, wolf_0_y = 425;
public:
	LEVEL_0();
	void show() const;
	void update_without_input();
	void update_with_input();
};

#endif // !LEVEL_0_H
