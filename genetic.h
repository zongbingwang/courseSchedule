#include "stdafx.h"

/* 
int M=4;                    //群体中包含的假设数量
const int N=5;                    //假设的最大位数
const int T=10;                   //繁殖代数
const double pc=0.5;              //每一步中通过交叉取代群体成员的比例
const double pm=0.5;              //变异率
const double  Fitness_threshold=1.0;  //终止继续繁殖的阀值
*/

const int R=25;                   //最多教室数量
const int M=50;                   //群体中包含的假设数量
const int N=10;                   //最多班级数目
const int T=20;                   //时间段数量
const double pr=0.8;              //每一步中通过交叉取代群体成员的比例
const double pm=0.1;             //变异率
const double  Fitness_threshold=1.0;  //终止继续繁殖的阀值

struct Population         
{
	int G[N];               //假设
	double fitness;         //适应度
};

class Genetic
{
public:
	Genetic(){}
	void init();                    //初始化假设
	void GA();                      //遗传算法递归处理过程
	void printResult();             //输出结果
	

protected:

	int rand01();                             //随机产生01
	double randab(double a, double b);        //随机产生[a,b]内的一个值
	int    randab(int    a, int    b);        //随机产生[a,b]内的一个值

	

	void encoding();              //编码
	int  decoding(int h);         //解码

	void evalueFitness(int);      //根据函数计算适应度

	void choose_pi(int);		  //选择适应度个体
	void crossover(int);          //交叉
	void mutation(int);           //变异

	int getNew(int);

private:
	Population V[2*M];
	double sumfitness;
	int start_id;
};