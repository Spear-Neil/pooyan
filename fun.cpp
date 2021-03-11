﻿#include "pooyan.h"
#include"level_1.h"

void level1::startup_1()
{
	mciSendString(L"close bkmusic", NULL, 0, NULL);
	mciSendString(L"open bk1.mp3 alias bkm", NULL, 0, NULL);
	mciSendString(L"play bkm repeat", NULL, 0, NULL);
	loadimage(&level1_bk, L"level1_bk.jpg");	//背景图
	loadimage(&level1_pooyan_red_bk, L"level1_pooyan_red_bk.jpg");
	loadimage(&level1_pooyan_red_front, L"level1_pooyan_red_front.jpg");//猪妈的图
	loadimage(&pooyan_red_down_bk, L"pooyan_red_down_bk.jpg");
	loadimage(&pooyan_red_down_front, L"pooyan_red_down_front.jpg");
	loadimage(&pooyan_red1_down_bk, L"pooyan_red1_down_bk.jpg");
	loadimage(&pooyan_red1_down_front, L"pooyan_red1_down_front.jpg");//猪妈下坠的图
	loadimage(&arrow_bk, L"arrow_bk.jpg");
	loadimage(&arrow_front, L"arrow_front.jpg");//骨箭的图
	loadimage(&arrow_down_bk, L"arrow_down_bk.jpg");
	loadimage(&arrow_down_front, L"arrow_down_front.jpg");//骨箭下坠的图
	loadimage(&level1_ball_bk, L"level1_ball_bk.jpg");//气球的图
	loadimage(&level1_ball_front, L"level1_ball_front.jpg");
	//神奇！！！气球的图要是放在狼的图下面会出bug，show的时候明明没有show球，它也会产生影响，效果类似于x光透视
	loadimage(&ball_red_exploded_bk, L"ball_red_exploded_bk.jpg");
	loadimage(&ball_red_exploded_front, L"ball_red_exploded_front.jpg");//气球爆炸的图
	loadimage(&ball_rise_bk, L"ball_rise_bk.jpg");
	loadimage(&ball_rise_front, L"ball_rise_front.jpg");//气球上升的图
	loadimage(&level_wolf_bk, L"level_wolf_bk.jpg");
	loadimage(&level_wolf_front, L"level_wolf_front.jpg");//狼的图
	loadimage(&rope_bk, L"rope_bk.jpg");
	loadimage(&rope_front, L"rope_front.jpg");//绳子的图
	loadimage(&wolf1_bk_right, L"wolf1_bk_right.jpg");
	loadimage(&wolf1_right, L"wolf1_right.jpg");
	loadimage(&wolf2_bk_right, L"wolf2_bk_right.jpg");
	loadimage(&wolf2_right, L"wolf2_right.jpg");//狼向右行走的图
	loadimage(&wolf_stop_bk1, L"wolf_stop_bk1.jpg");
	loadimage(&wolf_stop_front1, L"wolf_stop_front1.jpg");
	loadimage(&wolf_stop_bk2, L"wolf_stop_bk2.jpg");
	loadimage(&wolf_stop_front2, L"wolf_stop_front2.jpg");//狼被击中的图
	loadimage(&wolf_dead_bk1, L"wolf_dead_bk1.jpg");
	loadimage(&wolf_dead_front1, L"wolf_dead_front1.jpg");
	loadimage(&wolf_dead_bk2, L"wolf_dead_bk2.jpg");
	loadimage(&wolf_dead_front2, L"wolf_dead_front2.jpg");//狼下坠的图
	loadimage(&bullet_bk, L"bullet_bk.jpg");
	loadimage(&bullet_front, L"bullet_front.jpg");//子弹的图
	loadimage(&bone_bk, L"level1_bone_bk.jpg");
	loadimage(&bone_front, L"level1_bone_front.jpg");//肉骨棒的图
	pooyan.setX(500), pooyan.setY(140);//猪妈的初始坐标
	pooyan.setStatus(1);
	int i;
	for (i = 0; i < ARROW_NUM; i++)
	{
		arrow[i].setShot(-1) ;
		arrow[i].setX(pooyan.getX()-25); //25保证了箭从箭头射出
	}//初始化
	rand_interval = rand() % 2500 + 1000;//控制狼与狼之间的随机间隔
	wolf_cst = -1;//初始一只狼都没有
	ball_cst = -1;//初始一只气球都没有

				  //思路，先实现狼一个一个出现，然后用随机函数来控制狼的出现时间 类似于static 静态变量的方法
	for (i = 0; i < WOLF_NUM; i++)
	{
		wolf[i].setInterval(0);
		ball[i].setInterval(0);
		wolf[i].setX(0);
		wolf[i].setY(7);//保证开始时狼的纵坐标和上面的悬崖平台相贴
		ball[i].setY(7);
		wolf[i].setSign(-1);
		ball[i].setSign(-1);
		wolf[i].setDownX(rand() % 300 + 90) ;//随机一下所有的狼的下落横坐标
		ball[i].setDownX(wolf[i].getDownX()) ;
		bullet[i].setSign(rand() % 2) ;//随机一群发射子弹的狼
		ball[i].setShot(0);
	}
	for (i = 0; i < WOLF_NUM; i++)
	{
		if (bullet[i].getSign() == 1)//0不发射，1发射
			bullet[i].setRand(rand() % 100 + 90) ;//随机狼发着子弹的位置
		bullet[i].setX(wolf[i].getDownX()) ;
		bullet[i].setY(bullet[i].getRand());
		bullet[i].setStatus(-1);
	}
	//肉骨棒的初始化
	bone.setX(516);
	bone.setY(120);
	bone.setvx(1.8);
	bone.setvy(0.2);
	bone.setStatus(1);
	bone.setOn_off(0);
	bone.setAwake(0);
	BeginBatchDraw();//开始绘画
}

void level1::show_1()
{
	int i;
	putimage(0, 0, &level1_bk);//背景图
	putimage(530, 113, 20, rope.getY() - 100, &rope_bk, 530, 120, NOTSRCERASE);
	putimage(530, 113, 20, rope.getY() - 100, &rope_front, 530, 120, SRCINVERT);//绳子的图

	if (pooyan.getStatus() == 1)
	{
		putimage(pooyan.getX(), pooyan.getY(), &level1_pooyan_red_bk, NOTSRCERASE);
		putimage(pooyan.getX(), pooyan.getY(), &level1_pooyan_red_front, SRCINVERT);//猪妈的图
	}
	if (pooyan.getStatus() == 2)
	{
		putimage(pooyan.getDownX(), pooyan.getDownY() + 30, &pooyan_red1_down_bk, NOTSRCERASE);
		putimage(pooyan.getDownX(), pooyan.getDownY() + 30, &pooyan_red1_down_front, SRCINVERT);
		putimage(pooyan.getX(), pooyan.getY(), &pooyan_red_down_bk, NOTSRCERASE);
		putimage(pooyan.getX(), pooyan.getY(), &pooyan_red_down_front, SRCINVERT);//猪妈下坠的图

	}
	for (i = 0; i < ARROW_NUM; i++)
	{
		if (arrow[i].getShot() == 1)//if (shot[i])与	if (shot[i]==1)的运行速度天差地别，这是一个非常奇妙的事
		{
			putimage(arrow[i].getX(), arrow[i].getY(), &arrow_bk, NOTSRCERASE);
			putimage(arrow[i].getX(), arrow[i].getY(), &arrow_front, SRCINVERT);//骨箭的图
		}
		if (arrow[i].getShot() == 2)
		{
			putimage(arrow[i].getX(), arrow[i].getY(), &arrow_down_bk, NOTSRCERASE);
			putimage(arrow[i].getX(), arrow[i].getY(), &arrow_down_front, SRCINVERT);//骨箭下坠的图
		}
	}
	for (i = 0; i < WOLF_NUM; i++)
	{
		if (wolf[i].getSign() == 1)
		{
			if (wolf[i].getX() < wolf[i].getDownX())
			{
				if (wolf[i].getX() % 10 <= 5)//负责减速本来写的是wolf[i].x % 2 ==0，跑起来像飞毛腿一样
				{
					putimage(wolf[i].getX(), wolf[i].getY()+ 20, &wolf1_bk_right, NOTSRCERASE);
					putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf1_right, SRCINVERT);
				}
				else if (wolf[i].getX() % 10 > 5)
				{
					putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf2_bk_right, NOTSRCERASE);
					putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf2_right, SRCINVERT);
				}
			}
			else if (wolf[i].getX() >= wolf[i].getDownX())//下落
			{
				putimage(wolf[i].getX(), wolf[i].getY(), &level_wolf_bk, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY(), &level_wolf_front, SRCINVERT);
			}
		}
		if (wolf[i].getSign() == 2)//狼被击中
		{
			if (wolf[i].getInterval() % 30 <= 15)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_stop_bk1, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_stop_front1, SRCINVERT);
			}
			else if (wolf[i].getInterval() % 30 > 15)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_stop_bk2, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_stop_front2, SRCINVERT);
			}
		}
		if (wolf[i].getSign() == 3)
		{
			//快速下坠
			if (wolf[i].getY() % 100 <= 50)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_dead_bk1, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_dead_front1, SRCINVERT);
			}
			else if (wolf[i].getY() % 100 > 50)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_dead_bk2, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 50, &wolf_dead_front2, SRCINVERT);
			}
		}
		if (wolf[i].getSign() == 4)
		{
			if (wolf[i].getX() % 10 <= 5)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf1_bk_right, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf1_right, SRCINVERT);
			}
			else if (wolf[i].getX() % 10 > 5)
			{
				putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf2_bk_right, NOTSRCERASE);
				putimage(wolf[i].getX(), wolf[i].getY() + 20, &wolf2_right, SRCINVERT);
			}
		}
	}

	for (i = 0; i < WOLF_NUM; i++)
	{
		//气球正常下落
		if (ball[i].getSign() == 1 && wolf[i].getX() >= wolf[i].getDownX())
		{
			putimage(ball[i].getX(), ball[i].getY(), &level1_ball_bk, NOTSRCERASE);
			putimage(ball[i].getX(), ball[i].getY(), &level1_ball_front, SRCINVERT);
		}
		//气球爆炸
		if (ball[i].getSign() == 2)
		{
			putimage(ball[i].getX() + 25, ball[i].getY() + 5, &ball_red_exploded_bk, NOTSRCERASE);
			putimage(ball[i].getX() + 25, ball[i].getY() + 5, &ball_red_exploded_front, SRCINVERT);
		}
		//气球上升
		if (ball[i].getSign() == 3)
		{
			putimage(ball[i].getX() + 25, ball[i].getY() + 5, &ball_rise_bk, NOTSRCERASE);
			putimage(ball[i].getX() + 25, ball[i].getY() + 5, &ball_rise_front, SRCINVERT);
		}
	}
	for (i = 0; i < WOLF_NUM; i++)
	{
		if (bullet[i].getSign() == 1)
		{
			if (bullet[i].getStatus() == 1)
			{
				putimage(bullet[i].getX() + 20, bullet[i].getY() + 30, &bullet_bk, NOTSRCERASE);
				putimage(bullet[i].getX() + 20, bullet[i].getY() + 30, &bullet_front, SRCINVERT);
			}
		}
	}
	if (bone.getStatus() == 1 || bone.getStatus() == 2)
	{
		putimage(bone.getX(), bone.getY(), &bone_bk, NOTSRCERASE);
		putimage(bone.getX(), bone.getY(), &bone_front, SRCINVERT);
	}
	TCHAR s[80];
	_stprintf_s(s, _T("%06d"), score);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, _T("黑体"));
	outtextxy(2, 5, _T("分数:"));
	outtextxy(55, 5, s);
	FlushBatchDraw();//结束当前帧的绘画
}

void level1::update_without_input_1()
{
	int i, j;
	rope.setY(pooyan.getY()) ;

	//骨箭的模块
	static int arrow_speed = 0;//定义静态变量arrow_speed来控制箭的速度
	if (arrow_speed < ARROW_SPEED)
		arrow_speed++;
	if (arrow_speed == ARROW_SPEED)
	{
		for (i = 0; i < ARROW_NUM; i++)
		{
			if (arrow[i].getShot() == 1)
			{
				if (arrow[i].getX() > -80)//扫描所有的箭，如果箭接受了发箭指令，那只箭就开始进行自减，进行向左移动，由于箭图的put是从箭头开始的，所以-80是为了隐藏箭身
					arrow[i].setX(arrow[i].getX()-1);//为了接下来箭和其他元素进行交互，这种箭的速度定为1，从而使箭的移动更细腻一点
				if (arrow[i].getX() == -80)
					arrow[i].setShot(-1) ;
			}
			if (arrow[i].getShot() == 2)
			{
				if (arrow[i].getY() < HEIGHT + 50)
					arrow[i].setY(arrow[i].getY()+1);
				if (arrow[i].getY() == HEIGHT + 50)
					arrow[i].setShot(-1);
			}
		}
		arrow_speed = 0;
	}
	on_off = 0;//负责刷新
	for (i = 0; i < ARROW_NUM; i++)
	{
		if (arrow[i].getShot() > 0)//如果有箭的状态是在屏幕上移动的，那么开始计数
			on_off++;
	}


	//狼的模块

	static int rand_wolf = 0;//用于狼的延迟出现
	if (rand_wolf < rand_interval)
		rand_wolf++;
	if (rand_wolf == rand_interval && wolf_cst < WOLF_NUM - 1)
		//wolf_cst<WOLF_NUM-1修复结尾bug，毕竟wolf[wolf_cst].sign是数组，不能越界
		//定义wolf[].sign只能存WOLF_NUM个数据，wolf_cst < WOLF_NUM-1，（-1<WOLF_NUM-1，即0<WOLF_NUM，即WOLF_NUM只狼），所以WOLF_NUM-1这个数再大一点，wolf[].sign就越界，
		//如果单独显示，sign越界没问题，但是在一个复杂的界面上，就不行，数据必须精确，如果WOLF_NUM-1再大一点，结尾就变成了狼和箭不能同时正常运行的尴尬局面	
	{
		wolf_cst++;//一只一只狼的赋值，体现变化

		ball_cst++;//气球
		if (wolf_cst >= 0)
			wolf[wolf_cst].setSign(1);//狼的赋值

		if (ball_cst >= 0)
			ball[ball_cst].setSign(1);//气球的赋值
									//普天同庆，修复最后一只狼的bug，自加后，立刻赋值，最为合理和安全，放外面，就是错，就是不对！
		rand_interval = rand() % 2500 + 1000;//rand()%m+n  m为随机变化幅度   n为固定变化幅度
		rand_wolf = 0;
	}
	//遍历，找到落到地面的狼，之后向右跑
	for (i = 0; i < WOLF_NUM; i++)
		if (wolf[i].getY() >= 490 && wolf[i].getSign() == 1)
		{
			wolf[i].setSign(4);
			ball[i].setSign(-1);
		}
	//狼的移动速度
	static int wolf_speed = 0;
	if (wolf_speed < 20)
		wolf_speed++;
	if (wolf_speed == 20)
	{
		for (i = 0; i < WOLF_NUM; i++)
		{
			//开始时的向右跑
			if (wolf[i].getSign()== 1 && wolf[i].getX() < wolf[i].getDownX())
				wolf[i].setX(wolf[i].getX()+1);
			//下落
			if (wolf[i].getSign() == 1 && wolf[i].getX() == wolf[i].getDownX())
			{
				wolf[i].setY(wolf[i].getY()+1); 
				ball[i].setY(ball[i].getY()+1);
			}
			//快速下落
			if (wolf[i].getSign() == 3)
				wolf[i].setY(wolf[i].getY()+5);
			//狼下落到地面向右行走
			if (wolf[i].getSign() == 4)
				wolf[i].setX(wolf[i].getX()+1);
			if (ball[i].getSign() == 3)
				ball[i].setY(ball[i].getY()-1);
		}
		wolf_speed = 0;
	}

	for (j = 0; j < WOLF_NUM; j++)
	{
		if ((bone.getX() >= wolf[j].getDownX() - 8) && (bone.getX() <= wolf[j].getDownX() + 40) && (bone.getY() > ball[j].getY() + 30) && (bone.getY() <= ball[j].getY() + 65))
		{
			wolf[j].setSign(2) ;//狼死前挣扎
			ball[j].setSign(3) ;//上升
			ball[j].setShot(1) ;
		}
	}
	//箭射中气球的判断
	for (i = 0; i < ARROW_NUM; i++)
	{
		for (j = 0; j < WOLF_NUM; j++)
		{
			//删除if (arrow[i].shot == 1)，实现下坠的箭可以扎破下方的气球
			if ((arrow[i].getX() >= ball[j].getDownX() - 8) && (arrow[i].getX() <= ball[j].getDownX() + 40) && (arrow[i].getY() >= ball[j].getY() - 3) && (arrow[i].getY() <= ball[j].getY() + 30))
			{
				//骨箭下坠
				ball[j].setSign(2);//气球爆炸
				if (ball[j].getShot() == 0)
				{
					wolf[j].setSign(2);//狼死前挣扎
				}
				arrow[i].setX(-50) ;//箭消失，刷新下一支
				score += 700;//分数
			}
			if ((arrow[i].getX() >= wolf[j].getDownX() - 8) && (arrow[i].getX() <= wolf[j].getDownX() + 40) && (arrow[i].getY() > ball[j].getY() + 30) && (arrow[i].getY() <= ball[j].getY() + 65))
			{
				if (wolf[j].getSign() == 1)
					arrow[i].setShot(2);//骨箭射中狼，骨箭下坠（ps:之后加射中狼两次，狼就死）
				if (ball[j].getSign() == 4)
				{
					ball[j].setSign(2);
					ball[i].setY(-1);
					arrow[i].setX(-50);//箭消失，刷新下一支
					score += 200;
				}
			}
			if ((bone.getX() >= wolf[j].getDownX() - 8) && (bone.getX() <= wolf[j].getDownX() + 40) && (bone.getY() > ball[j].getY() + 30) && (bone.getY() <= ball[j].getY() + 65))
			{
				wolf[j].setSign(2) ;//狼死前挣扎
				ball[j].setSign(3) ;//上升	
			}
		}
	}
	//狼挣扎状态变化的延迟
	for (j = 0; j < WOLF_NUM; j++)
	{
		if (wolf[j].getSign() == 2)
			wolf[j].setInterval(wolf[j].getInterval()+1);
		if (wolf[j].getInterval() == 600)
		{
			score += 500;
			wolf[j].setSign(3) ;
			wolf[j].setDownX(-1) ;
			wolf[j].setInterval(0) ;
			num++;
		}
	}
	//气球爆炸状态变化的延迟
	for (j = 0; j < WOLF_NUM; j++)
	{
		if (ball[j].getSign() == 2)
			ball[j].setInterval(ball[j].getInterval()+1);
		if (ball[j].getInterval() == 100)//将ball的interval的值定为100，修复了紧接着射出的第二支箭也消失的bug
		{
			ball[j].setY(-1);//修复bug，将被射中的气球去掉，否则当箭再次出现在下坠的狼的上方的时候，下坠的狼还会暂停一下，也就是又被射死了一次
			ball[j].setSign(-1);
			ball[j].setDownX(-1);
			ball[j].setInterval(0);
		}
	}
	//子弹的模块
	//子弹的发射与移动
	for (i = 0; i < WOLF_NUM; i++)
	{
		if (wolf[i].getY() == bullet[i].getRand() && wolf[i].getSign() == 1)//当狼走到该发子弹的位置时，子弹状态变位1，即发射状态
			bullet[i].setStatus(1);
	}
	static int bullet_speed = 0;//子弹的移动速度
	if (bullet_speed < 10)
		bullet_speed++;
	if (bullet_speed == 10)
	{
		for (i = 0; i < WOLF_NUM; i++)
		{
			if (bullet[i].getStatus() == 1)
			{
				bullet[i].setX(bullet[i].getX()+2);
				bullet[i].setY(bullet[i].getY()+1);
			}
		}
		bullet_speed = 0;
	}
	//子弹状态的变化
	for (i = 0; i < WOLF_NUM; i++)
	{
		//猪妈中弹
		if ((bullet[i].getX() >= pooyan.getX()) && (bullet[i].getX() < pooyan.getX() + 5) && (bullet[i].getY() >= pooyan.getY() - 5) && (bullet[i].getY() <= pooyan.getY() + 45))
		{
			pooyan.setStatus(2);
			pooyan.setDownX(pooyan.getX());
			pooyan.setDownY(pooyan.getY());
		}
		//猪妈用吊篮的顶部挡掉子弹
		if ((bullet[i].getX() >= pooyan.getX() - 5) && (bullet[i].getX() <= pooyan.getX() + 50) && (bullet[i].getY() >= pooyan.getY() - 20) && (bullet[i].getY() < pooyan.getY()))
		{
			bullet[i].setStatus(-1);
			bullet[i].setX(-1);
			bullet[i].setY(-1);
		}
		//猪妈用吊篮的底部挡掉子弹
		if ((bullet[i].getX() >= pooyan.getX() - 15) && (bullet[i].getX() <= pooyan.getX() + 50) && (bullet[i].getY() >= pooyan.getY() + 35))
		{
			bullet[i].setStatus(-1);
			bullet[i].setX(-1);
			bullet[i].setY(-1);
		}
	}
	//子弹击中猪妈后，猪妈的快速下坠
	static int speed_pooyan_red = 0;//控制猪妈下坠的速度
	if (speed_pooyan_red < 2)
		speed_pooyan_red++;
	if (speed_pooyan_red == 2)
	{
		if (pooyan.getStatus() == 2)
			pooyan.setDownY(pooyan.getDownY()+1);
		speed_pooyan_red = 0;
	}
	//猪妈死亡，游戏结束
	if (pooyan.getDownY() >= HEIGHT)
		act = 3;
	//肉骨棒模块
	if (pooyan.getY() == 120 && bone.getStatus() == 1)
	{
		bone.setStatus(2);
	}
	if (bone.getStatus() == 2 && bone.getOn_off() == 0)
	{
		bone.setX(pooyan.getX() - 10);
		bone.setY(pooyan.getY() + 45);
	}
	static int l = 0;

	if (bone.getStatus() == 2 && bone.getOn_off() == 1)
	{
		if (l < 4)
			l++;
		if (l == 4)
		{
			bone.setX(bone.getX()-bone.getvx());
			bone.setY(bone.getY()+bone.getvy());
			if (bone.getX() <= 300)
				bone.setvy(bone.getvy()+0.01);
			l = 0;
		}
	}

	if (bone.getX() <= 40 || bone.getY() > 500)
	{
		bone.setOn_off(0);
		bone.setStatus(-1);
		bone.setX(516);
		bone.setY(120);
		bone.setAwake(1);
		bone.setvx(1.8);
		bone.setvy(0.2);
	}
	static int x = 0;
	if (bone.getAwake() == 1)
	{
		if (x < 3000)
			x++;
		if (x == 3000)
		{
			bone.setStatus(1);
			x = 0;
			bone.setAwake(0);
		}
	}
}
void level1::update_with_input_1()
{
	int i;
	static int speed_pooyan = 0;//定义静态变量speed_pooyan来控制猪的速度
	if (GetAsyncKeyState(0x57) & 0x8000 && pooyan.getY() >= 113 && pooyan.getStatus() == 1)//w，猪妈向上移动
	{
		if (speed_pooyan < POOYAN_SPEED)
			speed_pooyan++;
		if (speed_pooyan == POOYAN_SPEED)
		{
			pooyan.setY(pooyan.getY()-1);//写1用来细腻的移动
			speed_pooyan = 0;
		}
	}
	if (GetAsyncKeyState(0x53) & 0x8000 && pooyan.getY() <= 400 && pooyan.getStatus() == 1)//s，猪妈向下移动
	{
		if (speed_pooyan < POOYAN_SPEED)
			speed_pooyan++;
		if (speed_pooyan == POOYAN_SPEED)
		{
			pooyan.setY(pooyan.getY()+1);//写1用来细腻的移动
			speed_pooyan = 0;
		}
	}
	char input;
	int judge;/*直接用无冲突按键的函数，会出现问题(问题为GetAsyncKeyState函数判断太灵敏，你感觉是按了一下'j'，
			  但是const_shot的自加进行了很多次，所以无法实现按一次射一只箭，但是无冲突按键又对游戏性有极大的提高），所以用judge跳转一下*/
	judge = 0;//初始化judge，并刷新judge以保证正常情况下，能随时接受按键'j'的指令
	if (_kbhit())
	{
		input = _getch();
		if (input == 'j')
			judge = 1;
	}
	if (GetAsyncKeyState(0x4A) & 0x8000 && (on_off < 2))//j  (on_off<2)用来控制屏幕中只能存在两支箭，否则输入无效
	{
		/*如果按一次j，第一支箭会一直向左射，如果第二次按j，数组的1启动，第二支箭会一直向左射，从举例到一般的思考中得出骨箭元素的写法*/
		if (judge == 1)
		{
			if (bone.getStatus() == 2)
			{
				bone.setOn_off(1);
				mciSendString(L"close py", NULL, 0, NULL);
				mciSendString(L"open py.mp3 alias py", NULL, 0, NULL);
				mciSendString(L"play py", NULL, 0, NULL);
			}
			else
			{
				const_shot++;//计算按了多少次j
				arrow[const_shot].setShot(1);//如果按下了'j'键，就把一支箭从-1状态变为1；按一次'j'，const_shot就自加一次，相当于换箭的开关
				arrow[const_shot].setY(pooyan.getY() + 43);//跟踪按下'j'时，那只箭的Y坐标，该语句不能放在update_without_input之中，因为箭一旦射出，就无需更新

				mciSendString(L"close shot", NULL, 0, NULL);
				mciSendString(L"open shot.mp3 alias shot", NULL, 0, NULL);
				mciSendString(L"play shot", NULL, 0, NULL);
			}
		}
	}
}
