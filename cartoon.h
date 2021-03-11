#ifndef CARTOON_H
#define CARTOON_H

#include"pooyan.h"
class CARTOON
{
protected:
	IMAGE bk;
public:
	CARTOON()
	{
		loadimage(&bk, L"bk.jpg");
	}
	virtual void show() const = 0;
	virtual void update_without_input() = 0;
};

class CARTOON_1 : public CARTOON //动画一相关数据
{
private:
	IMAGE pooyan_pink_3_bk_next, pooyan_pink_3_next, pooyan_pink_4_bk_next, pooyan_pink_4_next;
	IMAGE wolf_3_bk_right, wolf_3_right, wolf_4_bk_right, wolf_4_right;
	IMAGE pooyan_pink_3, pooyan_pink_3_bk, pooyan_pink_4, pooyan_pink_4_bk;
	IMAGE pooyan_red_3, pooyan_red_3_bk, pooyan_red_4, pooyan_red_4_bk;
	IMAGE wolf_3, wolf_3_bk, wolf_4, wolf_4_bk;
	int pooyan_pink_0_x = 640;
	int pooyan_pink_3_x = 640, pooyan_pink_3_y = 425;
	int pooyan_red_3_x = 640, pooyan_red_3_y = 425;
	int pooyan_pink_3_next_x = 240, pooyan_pink_3_next_y = 425;
	int wolf_1_right_x = 0, wolf_1_right_y = 425;
	int wolf_1_left_x = 325, wolf_1_left_y = 425;
public:
	CARTOON_1();
	void show() const;
	void update_without_input();
	int get_pooyan_red_3_x()
	{
		return pooyan_red_3_x;
	}
};

class CARTOON_2 : public CARTOON
{
private:
	IMAGE pooyan_blue_5, pooyan_blue_5_bk, pooyan_blue_6, pooyan_blue_6_bk;
	IMAGE pooyan_pink_5, pooyan_pink_5_bk, pooyan_pink_6, pooyan_pink_6_bk;
	IMAGE pooyan_red_5, pooyan_red_5_bk, pooyan_red_6, pooyan_red_6_bk;
	IMAGE ball_5, ball_5_bk, ball_6, ball_6_bk;
	IMAGE wolf_5, wolf_5_bk, wolf_6, wolf_6_bk;
	int pooyan_blue_4_x = 640, pooyan_blue_4_y = 425;
	int pooyan_pink_4_x = 640, pooyan_pink_4_y = 425;
	int pooyan_red_4_x = 640, pooyan_red_4_y = 425;
	int ball_4_x = 640, ball_4_y = 400;
	int wolf_4_x = 640, wolf_4_y = 425;
public:
	CARTOON_2();
	void show() const;
	void update_without_input();
	int get_pooyan_red_4_x()
	{
		return pooyan_red_4_x;
	}
};

#endif // !CARTOON_H
