#ifndef  POOYAN_H
#define POOAYN_H

#pragma warning(disable : 4996)
#include<graphics.h>
#include<conio.h>
#include<windows.h>   //键盘输入后的短暂延时
#include<time.h>
#include<stdlib.h>
#pragma comment(lib,"Winmm.lib")  //导入winmm.lib库，用于音乐播放
#include<iostream>
using namespace std;

#define HEIGHT 600
#define WIDTH 640
#define POOYAN_SPEED 3 //初始化猪妈的速度为5
#define ARROW_NUM 1000  //骨箭支数
#define ARROW_SPEED 3 //初始化骨箭的速度为3
#define WOLF_NUM 18 //狼的只数
#define BONE_NUM 5 //肉骨棒的个数
#define WOLF_NUM_2 15//第二关狼的只数
#define WOLF_SPEED_2 20//第二关狼的速度
#define POOYAN_SPEED_2 3//第二关初始化猪妈速度为3
#define SCORE_1 15//第一关通关分数
#define SCORE_2 20//第二关通关分数
extern int act;   //控制游戏关卡
extern int num;    //控制过关
extern int num_2;
extern int score; //分数

#endif  // POOYAN_H
