#pragma once

#include "stdafx.h"
#include "genetic.h"
#include "classes.h"
#include "subjects.h"
#include "classRooms.h"
#include "time.h"
#include "teachers.h"

/*
const int M=50;                   //群体中包含的假设数量
const int N=10;                   //最多班级数目
const int T=20;                   //时间段数量
const double pc=0.8;              //每一步中通过交叉取代群体成员的比例
const double pm=0.01;             //变异率
const double  Fitness_threshold=1.0;  //终止继续繁殖的阀值
*/


struct Population1         
{
	int G[N][T][2];          //班级ID|时间ID|（课堂ID+教室ID)
	double fitness;          //适应度
};

class Timetable:public Genetic
{
	friend class Applaction;
public:
	Timetable(){Genetic();}
	void init();                    //初始化
	void GA();                      //遗传算法递归处理过程
	void printResult();             //输出结果
	double H(int);                  //计算时间适应度

protected:
	void input();                 //读入各项数据
	void input_test();            //测试使用
	//void encoding();            //编码
	//int  decoding(int h);       //解码

	void evalueFitness(int);      //根据函数计算适应度

	void choose_pi(int);		  //选择适应度个体
	void eliminate(int);          //减缓冲突
	void crossover(int);          //交叉
	void mutation(int);           //变异

private:
	Population1 V[2*M];
	double sumfitness;
	int start_id;
	int USE[T][R];

	int C;   //班级数量
	int P;   //时间
	int S;   //课堂
	int R;   //教室
	int T;   //教师

	std::vector<Class> vC;
	std::vector<Time> vP;
	std::vector<Subject> vS;
	std::vector<ClassRoom> vR;
	std::vector<Teacher> vT;
};

