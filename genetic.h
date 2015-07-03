#include "stdafx.h"

const int M=4;                    //Ⱥ���а����ļ�������
const int N=5;                    //��������λ��
const int T=10;                   //��ֳ����
const double pc=0.5;              //ÿһ����ͨ������ȡ��Ⱥ���Ա�ı���
const double pm=0.1;              //������
const double  Fitness_threshold;  //��ֹ������ֳ�ķ�ֵ

struct Population         
{
	int G[N];               //����
	double fitness;         //��Ӧ��
};

class Genetic
{
public:
	Genetic(){}

protected:

	int rand01();                             //�������01
	double randab(double a, double b);        //�������[a,b]�ڵ�һ��ֵ

	void init(int start=0);

	void encoding();              //����
	int  decoding(int h);         //����

	void evalueFitness(int);      //���ݺ���������Ӧ��

	void choose_pi();			  //ѡ����Ӧ�ȸ���
	void crossover();             //����
	void mutation();              //����

	void GA();                    //�Ŵ��㷨�ݹ鴦�����

private:
	Population V[2*M];
	double sumfitness;
};