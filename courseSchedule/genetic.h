#include "stdafx.h"

/* 
int M=4;                    //Ⱥ���а����ļ�������
const int N=5;                    //��������λ��
const int T=10;                   //��ֳ����
const double pc=0.5;              //ÿһ����ͨ������ȡ��Ⱥ���Ա�ı���
const double pm=0.5;              //������
const double  Fitness_threshold=1.0;  //��ֹ������ֳ�ķ�ֵ
*/

const int R=25;                   //����������
const int M=50;                   //Ⱥ���а����ļ�������
const int N=10;                   //���༶��Ŀ
const int T=20;                   //ʱ�������
const double pr=0.8;              //ÿһ����ͨ������ȡ��Ⱥ���Ա�ı���
const double pm=0.1;             //������
const double  Fitness_threshold=1.0;  //��ֹ������ֳ�ķ�ֵ

struct Population         
{
	int G[N];               //����
	double fitness;         //��Ӧ��
};

class Genetic
{
public:
	Genetic(){}
	void init();                    //��ʼ������
	void GA();                      //�Ŵ��㷨�ݹ鴦�����
	void printResult();             //������
	

protected:

	int rand01();                             //�������01
	double randab(double a, double b);        //�������[a,b]�ڵ�һ��ֵ
	int    randab(int    a, int    b);        //�������[a,b]�ڵ�һ��ֵ

	

	void encoding();              //����
	int  decoding(int h);         //����

	void evalueFitness(int);      //���ݺ���������Ӧ��

	void choose_pi(int);		  //ѡ����Ӧ�ȸ���
	void crossover(int);          //����
	void mutation(int);           //����

	int getNew(int);

private:
	Population V[2*M];
	double sumfitness;
	int start_id;
};