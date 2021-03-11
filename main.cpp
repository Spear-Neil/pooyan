#include"level_0.h"
#include"cartoon.h"
#include"level_1.h"
#include"level_2.h"

int act = 0;  //������Ϸ�ؿ�
int num = 0;  //���ƹ���
int num_2 = 0;
int score = 0;	//����

int main()
{
	initgraph(WIDTH, HEIGHT);//����һ��640*600����Ϸ����
	srand(time(NULL));
	LEVEL_0* level_0 = new LEVEL_0;   //��Ϸ��ʼ������
	while (act == 0)         
	{
		level_0->show();
		level_0->update_without_input();
		level_0->update_with_input();
	}
	delete level_0;

	CARTOON_1* cartoon_1 = new CARTOON_1;  //���ŵ�һ�ζ���
	while (act == 1)
	{
		cartoon_1->show();
		cartoon_1->update_without_input();
		if (cartoon_1->get_pooyan_red_3_x() <= 0)
			break;
	}
	delete cartoon_1;

	level1* level_1  = new level1;  //��һ��
	level_1->startup_1(); 
	while (act == 1)
	{
		level_1->show_1();
		level_1->update_without_input_1();
		level_1->update_with_input_1();
		if (num >= 10)
			break;
	}
	delete level_1;

	CARTOON_2* cartoon_2 = new CARTOON_2;  //��������
	while (act == 1)
	{
		cartoon_2->show();
		cartoon_2->update_without_input();
		if (cartoon_2->get_pooyan_red_4_x() <= 0)
			break;
	}
	delete cartoon_2;

	level02* level2 = new level02;   //�ڶ���
	level2->startup_level02();
	while (act == 1)
	{
		level2->show_level02();
		level2->update_without_input_level02();
		level2->update_with_input_level02();
	}
	level2->end_level02();
	delete level2;

	getch();   //����ǰͣ��
	EndBatchDraw();
	closegraph();
}