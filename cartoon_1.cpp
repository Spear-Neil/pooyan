#include"cartoon.h"
CARTOON_1::CARTOON_1():CARTOON()
{
	loadimage(&pooyan_pink_3, L"pooyan_pink0.jpg");
	loadimage(&pooyan_pink_3_bk, L"pooyan_pink0_bk.jpg");
	loadimage(&pooyan_pink_4, L"pooyan_pink1.jpg");
	loadimage(&pooyan_pink_4_bk, L"pooyan_pink1_bk.jpg");
	loadimage(&pooyan_red_3, L"pooyan_red0.jpg");
	loadimage(&pooyan_red_3_bk, L"pooyan_red0_bk.jpg");
	loadimage(&pooyan_red_4, L"pooyan_red1.jpg");
	loadimage(&pooyan_red_4_bk, L"pooyan_red1_bk.jpg");
	loadimage(&wolf_3, L"wolf0.jpg");
	loadimage(&wolf_3_bk, L"wolf0_bk.jpg");
	loadimage(&wolf_4, L"wolf1.jpg");
	loadimage(&wolf_4_bk, L"wolf1_bk.jpg");
	loadimage(&pooyan_pink_3_bk_next, L"pooyan_pink0_bk_next.jpg");
	loadimage(&pooyan_pink_3_next, L"pooyan_pink0_next.jpg");
	loadimage(&pooyan_pink_4_bk_next, L"pooyan_pink1_bk_next.jpg");
	loadimage(&pooyan_pink_4_next, L"pooyan_pink1_next.jpg");
	loadimage(&wolf_3_bk_right, L"wolf1_bk_right.jpg");
	loadimage(&wolf_3_right, L"wolf1_right.jpg");
	loadimage(&wolf_4_bk_right, L"wolf2_bk_right.jpg");
	loadimage(&wolf_4_right, L"wolf2_right.jpg");

	BeginBatchDraw();
}

void CARTOON_1::show() const
{
	putimage(0, 0, &bk);
	int j;
	for (j = 0; j < WIDTH; j++)
	{
		if (j == pooyan_pink_0_x && pooyan_pink_0_x >= 240)
		{
			Sleep(100);
			if (j / 10 % 2 == 0)
			{
				putimage(pooyan_pink_3_x, pooyan_pink_3_y, &pooyan_pink_3_bk, NOTSRCERASE);
				putimage(pooyan_pink_3_x, pooyan_pink_3_y, &pooyan_pink_3, SRCINVERT);
			}
			if (j / 10 % 2 == 1)
			{
				putimage(pooyan_pink_3_x, pooyan_pink_3_y, &pooyan_pink_4_bk, NOTSRCERASE);
				putimage(pooyan_pink_3_x, pooyan_pink_3_y, &pooyan_pink_4, SRCINVERT);
			}
		}
		if (j == pooyan_pink_3_next_x && pooyan_pink_3_x <= 230 && pooyan_pink_3_next_x - wolf_1_right_x > 5)
		{
			if (wolf_1_right_x <= 0)
				Sleep(100);
			if (j / 10 % 2 == 0)
			{
				putimage(pooyan_pink_3_next_x, pooyan_pink_3_next_y, &pooyan_pink_3_bk_next, NOTSRCERASE);
				putimage(pooyan_pink_3_next_x, pooyan_pink_3_next_y, &pooyan_pink_3_next, SRCINVERT);
			}
			if (j / 10 % 2 == 1)
			{
				putimage(pooyan_pink_3_next_x, pooyan_pink_3_next_y, &pooyan_pink_4_bk_next, NOTSRCERASE);
				putimage(pooyan_pink_3_next_x, pooyan_pink_3_next_y, &pooyan_pink_4_next, SRCINVERT);
			}
		}
		if (j == wolf_1_right_x && pooyan_pink_3_x <= 230 && pooyan_pink_3_next_x - wolf_1_right_x > 5)
		{
			Sleep(100);
			if (j / 10 % 2 == 0)
			{
				putimage(wolf_1_right_x, wolf_1_right_y, &wolf_3_bk_right, NOTSRCERASE);
				putimage(wolf_1_right_x, wolf_1_right_y, &wolf_3_right, SRCINVERT);
			}
			if (j / 10 % 2 == 1)
			{
				putimage(wolf_1_right_x, wolf_1_right_y, &wolf_4_bk_right, NOTSRCERASE);
				putimage(wolf_1_right_x, wolf_1_right_y, &wolf_4_right, SRCINVERT);
			}
		}
		if (j == wolf_1_left_x && pooyan_pink_3_next_x - wolf_1_right_x < 5)
		{
			Sleep(100);
			if (j / 10 % 2 == 0)
			{
				putimage(wolf_1_left_x, wolf_1_left_y, &pooyan_pink_4_bk, NOTSRCERASE);
				putimage(wolf_1_left_x, wolf_1_left_y, &pooyan_pink_4, SRCINVERT);
				putimage(wolf_1_left_x, wolf_1_left_y, &wolf_4_bk, NOTSRCERASE);
				putimage(wolf_1_left_x, wolf_1_left_y, &wolf_4, SRCINVERT);
			}
			if (j / 10 % 2 == 1)
			{
				putimage(wolf_1_left_x, wolf_1_left_y, &pooyan_pink_4_bk, NOTSRCERASE);
				putimage(wolf_1_left_x, wolf_1_left_y, &pooyan_pink_4, SRCINVERT);
				putimage(wolf_1_left_x, wolf_1_left_y, &wolf_3_bk, NOTSRCERASE);
				putimage(wolf_1_left_x, wolf_1_left_y, &wolf_3, SRCINVERT);
			}
		}
		if (j == pooyan_red_3_x && wolf_1_left_x <= 320)
		{
			if (wolf_1_left_x < 0)
				Sleep(100);
			if (j / 10 % 2 == 0)
			{
				putimage(pooyan_red_3_x, pooyan_red_3_y, &pooyan_red_3_bk, NOTSRCERASE);
				putimage(pooyan_red_3_x, pooyan_red_3_y, &pooyan_red_3, SRCINVERT);
			}
			if (j / 10 % 2 == 1)
			{
				putimage(pooyan_red_3_x, pooyan_red_3_y, &pooyan_red_4_bk, NOTSRCERASE);
				putimage(pooyan_red_3_x, pooyan_red_3_y, &pooyan_red_4, SRCINVERT);
			}
		}
	}
	FlushBatchDraw();
}

void CARTOON_1::update_without_input()
{
	if (pooyan_pink_3_x >= 240 && wolf_1_right_x < pooyan_pink_3_next_x)
		pooyan_pink_3_x = pooyan_pink_3_x - 10;
	if (pooyan_pink_3_x <= 240 && pooyan_pink_3_next_x - wolf_1_right_x > 5)
		pooyan_pink_3_next_x = pooyan_pink_3_next_x + 10;
	if (pooyan_pink_3_x <= 240 && pooyan_pink_3_next_x - wolf_1_right_x > 5)
		wolf_1_right_x = wolf_1_right_x + 30;
	if (wolf_1_left_x >= 0 && pooyan_pink_3_next_x - wolf_1_right_x < 5)
		wolf_1_left_x = wolf_1_left_x - 30;
	if (pooyan_red_3_x >= 0 && wolf_1_left_x <= 320)
		pooyan_red_3_x = pooyan_red_3_x - 30;
}