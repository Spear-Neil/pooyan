#ifndef  POOYAN_H
#define POOAYN_H

#pragma warning(disable : 4996)
#include<graphics.h>
#include<conio.h>
#include<windows.h>   //���������Ķ�����ʱ
#include<time.h>
#include<stdlib.h>
#pragma comment(lib,"Winmm.lib")  //����winmm.lib�⣬�������ֲ���
#include<iostream>
using namespace std;

#define HEIGHT 600
#define WIDTH 640
#define POOYAN_SPEED 3 //��ʼ��������ٶ�Ϊ5
#define ARROW_NUM 1000  //�Ǽ�֧��
#define ARROW_SPEED 3 //��ʼ���Ǽ����ٶ�Ϊ3
#define WOLF_NUM 18 //�ǵ�ֻ��
#define BONE_NUM 5 //��ǰ��ĸ���
#define WOLF_NUM_2 15//�ڶ����ǵ�ֻ��
#define WOLF_SPEED_2 20//�ڶ����ǵ��ٶ�
#define POOYAN_SPEED_2 3//�ڶ��س�ʼ�������ٶ�Ϊ3
#define SCORE_1 15//��һ��ͨ�ط���
#define SCORE_2 20//�ڶ���ͨ�ط���
extern int act;   //������Ϸ�ؿ�
extern int num;    //���ƹ���
extern int num_2;
extern int score; //����

#endif  // POOYAN_H
