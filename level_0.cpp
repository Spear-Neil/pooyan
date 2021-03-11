#include"level_0.h"

LEVEL_0::LEVEL_0()
{
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("ÖíÐ¡µÜ"));//»ñµÃ´°¿Ú¾ä±ú
	loadimage(&level0_bk, L"pooyan.jpg");	//±³¾°Í¼
	loadimage(&pooyan_blue_0, L"pooyan_blue0.jpg");
	loadimage(&pooyan_blue_0_bk, L"pooyan_blue0_bk.jpg");
	loadimage(&pooyan_blue_1, L"pooyan_blue1.jpg");
	loadimage(&pooyan_blue_1_bk, L"pooyan_blue1_bk.jpg");
	loadimage(&pooyan_pink_0, L"pooyan_pink0.jpg");
	loadimage(&pooyan_pink_0_bk, L"pooyan_pink0_bk.jpg");
	loadimage(&pooyan_pink_1, L"pooyan_pink1.jpg");
	loadimage(&pooyan_pink_1_bk, L"pooyan_pink1_bk.jpg");
	loadimage(&pooyan_red_0, L"pooyan_red0.jpg");
	loadimage(&pooyan_red_0_bk, L"pooyan_red0_bk.jpg");
	loadimage(&pooyan_red_1, L"pooyan_red1.jpg");
	loadimage(&pooyan_red_1_bk, L"pooyan_red1_bk.jpg");
	loadimage(&ball_0, L"ball0.jpg");
	loadimage(&ball_0_bk, L"ball0_bk.jpg");
	loadimage(&ball_1, L"ball1.jpg");
	loadimage(&ball_1_bk, L"ball1_bk.jpg");
	loadimage(&wolf_0, L"wolf0.jpg");
	loadimage(&wolf_0_bk, L"wolf0_bk.jpg");
	loadimage(&wolf_1, L"wolf1.jpg");
	loadimage(&wolf_1_bk, L"wolf1_bk.jpg");

	mciSendString(_T("open bk0.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	BeginBatchDraw();
}

void LEVEL_0::show() const
{
	putimage(0, 0, &level0_bk);  //±³¾°
	int i, j;
	for (j = 0; j < HEIGHT; j++)
	{
		for (i = 0; i < WIDTH; i++)
		{
			if (i == wolf_0_x && j == wolf_0_y && wolf_0_x > 0)
			{
				Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(wolf_0_x, wolf_0_y, &wolf_0_bk, NOTSRCERASE);
					putimage(wolf_0_x, wolf_0_y, &wolf_0, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(wolf_0_x, wolf_0_y, &wolf_1_bk, NOTSRCERASE);
					putimage(wolf_0_x, wolf_0_y, &wolf_1, SRCINVERT);
				}
			}
			if (i == pooyan_blue_0_x && j == pooyan_blue_0_y && pooyan_blue_0_x > 0)
			{
				if (wolf_0_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_blue_0_x, pooyan_blue_0_y, &pooyan_blue_0_bk, NOTSRCERASE);
					putimage(pooyan_blue_0_x, pooyan_blue_0_y, &pooyan_blue_0, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_blue_0_x, pooyan_blue_0_y, &pooyan_blue_1_bk, NOTSRCERASE);
					putimage(pooyan_blue_0_x, pooyan_blue_0_y, &pooyan_blue_1, SRCINVERT);
				}
			}
			if (i == pooyan_pink_0_x && j == pooyan_pink_0_y && pooyan_pink_0_x > 0)
			{
				if (pooyan_blue_0_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_pink_0_x, pooyan_pink_0_y, &pooyan_pink_0_bk, NOTSRCERASE);
					putimage(pooyan_pink_0_x, pooyan_blue_0_y, &pooyan_pink_0, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_pink_0_x, pooyan_pink_0_y, &pooyan_pink_1_bk, NOTSRCERASE);
					putimage(pooyan_pink_0_x, pooyan_blue_0_y, &pooyan_pink_1, SRCINVERT);
				}
			}
			if (i == ball_0_x && j == ball_0_y && wolf_0_x <= 428)
			{
				if (ball_0_y > 380)
				{
					if (i / 10 % 2 == 0)
					{
						putimage(ball_0_x, ball_0_y, &ball_0_bk, NOTSRCERASE);
						putimage(ball_0_x, ball_0_y, &ball_0, SRCINVERT);
					}
					if (i / 10 % 2 == 1)
					{
						putimage(ball_0_x, ball_0_y, &ball_1_bk, NOTSRCERASE);
						putimage(ball_0_x, ball_0_y, &ball_1, SRCINVERT);
					}
				}
				if (ball_0_y <= 380)
				{
					if (j / 10 % 2 == 0)
					{
						putimage(ball_0_x, ball_0_y, &ball_0_bk, NOTSRCERASE);
						putimage(ball_0_x, ball_0_y, &ball_0, SRCINVERT);
					}
					if (j / 10 % 2 == 1)
					{
						putimage(ball_0_x, ball_0_y, &ball_1_bk, NOTSRCERASE);
						putimage(ball_0_x, ball_0_y, &ball_1, SRCINVERT);
					}
				}
			}
			if (i == pooyan_red_0_x && j == pooyan_red_0_y && pooyan_red_0_x > 0)
			{
				if (pooyan_pink_0_x == 0)
					Sleep(100);
				if (i / 10 % 2 == 0)
				{
					putimage(pooyan_red_0_x, pooyan_red_0_y, &pooyan_red_0_bk, NOTSRCERASE);
					putimage(pooyan_red_0_x, pooyan_red_0_y, &pooyan_red_0, SRCINVERT);
				}
				if (i / 10 % 2 == 1)
				{
					putimage(pooyan_red_0_x, pooyan_red_0_y, &pooyan_red_1_bk, NOTSRCERASE);
					putimage(pooyan_red_0_x, pooyan_red_0_y, &pooyan_red_1, SRCINVERT);
				}
			}
		}

	}
	FlushBatchDraw();
}

void LEVEL_0::update_without_input()
{
	if (wolf_0_x > 0)
		wolf_0_x = wolf_0_x - 10;
	if (wolf_0_x <= 540 && pooyan_blue_0_x > 0)
		pooyan_blue_0_x = pooyan_blue_0_x - 10;
	if (wolf_0_x <= 440 && pooyan_pink_0_x > 0)
		pooyan_pink_0_x = pooyan_pink_0_x - 10;
	if (wolf_0_x <= 428)
	{
		if (ball_0_x > 175)
			ball_0_x = ball_0_x - 10;
		else if (ball_0_y > 280 && pooyan_red_0_x > 130)
			ball_0_y = ball_0_y - 10;
	}
	if (wolf_0_x <= 340 && pooyan_red_0_x > 0)
		pooyan_red_0_x = pooyan_red_0_x - 10;
}

void LEVEL_0::update_with_input()
{
	char input;
	if (kbhit())
	{
		input = getch();
		if (input == 's' && ball_0_y == 280)
			ball_0_y = 340;
		if (input == 'w' && ball_0_y == 340)
			ball_0_y = 280;
		if (input == 13 && ball_0_y == 280)
			act = 1;
	}
}