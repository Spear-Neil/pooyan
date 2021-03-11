#ifndef LEVEL_2_H
#define LEVEL_2_H

#include"pooyan.h"
class level02
{
private:
	IMAGE level2_bk;	//����ͼ
	IMAGE stone_bk, stone_front;//ʯͷ��ͼ
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

	int pooyan_red_x, pooyan_red_y;//�������������
	int ball_x[WOLF_NUM_2], ball_y[WOLF_NUM_2];//���������
	int wolf_x[WOLF_NUM_2], wolf_y[WOLF_NUM_2];//�ǵ�����
	int arrow_x[ARROW_NUM], arrow_y[ARROW_NUM];//��������
	int wolf_sign[WOLF_NUM_2];//�����Ļ�ϵ�ÿһֻ�������ж����Ƿ���֣�-1��ʾû�г��֣�1��ʾ����
	int wolf_count;//���ڿ�����Ļ��ÿһֻ��
	int ball_count;//���ڿ�����Ļ��ÿһֻ����
	int count_shoot;//ͳ�����˼�ֻ�������ں�������
	int shoot[ARROW_NUM];//�ж��Ƿ�����������飬-1��ʾû�г��֣�1��ʾ����
	int rand_space;//������ֵ���֮��ļ�����룬�����غ�
	int string_y;//����������
	int wolf_up_x[WOLF_NUM_2];//��������λ�õĺ�����
	int ball_up_x[WOLF_NUM_2];//��������ʱ�ĺ�����
	int ball_sign[WOLF_NUM_2];//���ÿһ������-1��ʾû�г��֣�1��ʾ����
	int stone_x;//ʯͷ�ĺ�������
	int stone_y;
	int arrow_num;//ͳ����Ļ�ϼ��ĸ�����ȷ����Ļ�ϴ��ڼ��ĸ����̶���
	int ball_interval[WOLF_NUM_2];//��������ը���������ʱ����
	int wolf_interval[WOLF_NUM_2];//�����������ʱ����
	int pooyan_red_dead_x;
	int pooyan_red_dead_y;//�������������������
	int pooyan_exit;//�ж������Ƿ��1��ʾ��2��ʾ�е�����
	int put_wolf = 0;//��ʯͷ����

private:	//����
	void arrow_level02();//����ģ��
	void stone_pooyan_level02();//ʯͷ�������ģ��
	void wolves_level02();//�ǵ�ģ��
	void ballon_level02();//�����ģ��
	void count_level02();//��¼����
	void arrow_moive_level02();//�����ƶ�
	void wolves_moive_level02();//�Ǻ�������ƶ�
	void judgmentScore_level02();//�÷��ж�
	void body_level02();//ʬ�崦��
	void passOrFailure_levle02();//�ж�ͨ�����
		
public:
	void startup_level02();
	void show_level02();
	void update_without_input_level02();
	void update_with_input_level02();
	void end_level02();
};


#endif // !LEVEL_2_H
