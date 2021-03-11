#include"cartoon.h"

CARTOON_2::CARTOON_2():CARTOON()
{
	loadimage(&bk, L"bk.jpg");
	loadimage(&pooyan_blue_5, L"pooyan_blue0.jpg");
	loadimage(&pooyan_blue_5_bk, L"pooyan_blue0_bk.jpg");
	loadimage(&pooyan_blue_6, L"pooyan_blue1.jpg");
	loadimage(&pooyan_blue_6_bk, L"pooyan_blue1_bk.jpg");
	loadimage(&pooyan_pink_5, L"pooyan_pink0.jpg");
	loadimage(&pooyan_pink_5_bk, L"pooyan_pink0_bk.jpg");
	loadimage(&pooyan_pink_6, L"pooyan_pink1.jpg");
	loadimage(&pooyan_pink_6_bk, L"pooyan_pink1_bk.jpg");
	loadimage(&pooyan_red_5, L"pooyan_red0.jpg");
	loadimage(&pooyan_red_5_bk, L"pooyan_red0_bk.jpg");
	loadimage(&pooyan_red_6, L"pooyan_red1.jpg");
	loadimage(&pooyan_red_6_bk, L"pooyan_red1_bk.jpg");
	loadimage(&wolf_5, L"wolf0.jpg");
	loadimage(&wolf_5_bk, L"wolf0_bk.jpg");
	loadimage(&wolf_6, L"wolf1.jpg");
	loadimage(&wolf_6_bk, L"wolf1_bk.jpg");

	BeginBatchDraw();
}

void CARTOON_2::show() const
{
	putimage(0, 0, &bk);  //±³¾°
	int i, j;
	for (j = 0; j < HEIGHT; j++)
	{
		for (i = 0; i < WIDTH; i++)
		{
			if (i == wolf_4_x && j == wolf_4_y && wolf_4_x > 0)
			{
				Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(wolf_4_x, wolf_4_y, &wolf_5_bk, NOTSRCERASE);
					putimage(wolf_4_x, wolf_4_y, &wolf_5, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(wolf_4_x, wolf_4_y, &wolf_6_bk, NOTSRCERASE);
					putimage(wolf_4_x, wolf_4_y, &wolf_6, SRCINVERT);
				}
			}
			if (i == pooyan_blue_4_x && j == pooyan_blue_4_y && pooyan_blue_4_x > 0)
			{
				if (wolf_4_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_blue_4_x, pooyan_blue_4_y, &pooyan_blue_5_bk, NOTSRCERASE);
					putimage(pooyan_blue_4_x, pooyan_blue_4_y, &pooyan_blue_5, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_blue_4_x, pooyan_blue_4_y, &pooyan_blue_6_bk, NOTSRCERASE);
					putimage(pooyan_blue_4_x, pooyan_blue_4_y, &pooyan_blue_6, SRCINVERT);
				}
			}
			if (i == pooyan_pink_4_x && j == pooyan_pink_4_y && pooyan_pink_4_x > 0)
			{
				if (pooyan_blue_4_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_pink_4_x, pooyan_pink_4_y, &pooyan_pink_5_bk, NOTSRCERASE);
					putimage(pooyan_pink_4_x, pooyan_blue_4_y, &pooyan_pink_5, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_pink_4_x, pooyan_pink_4_y, &pooyan_pink_6_bk, NOTSRCERASE);
					putimage(pooyan_pink_4_x, pooyan_blue_4_y, &pooyan_pink_6, SRCINVERT);
				}
			}
			if (i == pooyan_red_4_x && j == pooyan_red_4_y && pooyan_red_4_x > 0)
			{
				if (pooyan_pink_4_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_red_4_x, pooyan_red_4_y, &pooyan_red_5_bk, NOTSRCERASE);
					putimage(pooyan_red_4_x, pooyan_red_4_y, &pooyan_red_5, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_red_4_x, pooyan_red_4_y, &pooyan_red_6_bk, NOTSRCERASE);
					putimage(pooyan_red_4_x, pooyan_red_4_y, &pooyan_red_6, SRCINVERT);
				}
			}
		}
	}
	FlushBatchDraw();
}

void CARTOON_2::update_without_input()
{
	if (wolf_4_x > 0)
		wolf_4_x = wolf_4_x - 10;
	if (wolf_4_x <= 540 && pooyan_blue_4_x > 0)
		pooyan_blue_4_x = pooyan_blue_4_x - 10;
	if (wolf_4_x <= 440 && pooyan_pink_4_x > 0)
		pooyan_pink_4_x = pooyan_pink_4_x - 10;
	if (wolf_4_x <= 340 && pooyan_red_4_x > 0)
		pooyan_red_4_x = pooyan_red_4_x - 10;
}