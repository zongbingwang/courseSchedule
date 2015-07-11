#pragma once

#include "stdafx.h"
#include "genetic.h"
#include "classes.h"
#include "subjects.h"
#include "classRooms.h"
#include "time.h"
#include "teachers.h"

/*
const int M=50;                   //Ⱥ���а����ļ�������
const int N=10;                   //���༶��Ŀ
const int T=20;                   //ʱ�������
const double pc=0.8;              //ÿһ����ͨ������ȡ��Ⱥ���Ա�ı���
const double pm=0.01;             //������
const double  Fitness_threshold=1.0;  //��ֹ������ֳ�ķ�ֵ
*/


struct Population1         
{
	int G[N][T][2];          //�༶ID|ʱ��ID|������ID+����ID)
	double fitness;          //��Ӧ��
};

class Timetable:public Genetic
{
	friend class Applaction;
public:
	Timetable(){Genetic();}
	void init();                    //��ʼ��
	void GA();                      //�Ŵ��㷨�ݹ鴦�����
	void printResult();             //������
	double H(int);                  //����ʱ����Ӧ��

protected:
	void input();                 //�����������
	void input_test();            //����ʹ��
	//void encoding();            //����
	//int  decoding(int h);       //����

	void evalueFitness(int);      //���ݺ���������Ӧ��

	void choose_pi(int);		  //ѡ����Ӧ�ȸ���
	void eliminate(int);          //������ͻ
	void crossover(int);          //����
	void mutation(int);           //����

private:
	Population1 V[2*M];
	double sumfitness;
	int start_id;
	int USE[T][R];

	int C;   //�༶����
	int P;   //ʱ��
	int S;   //����
	int R;   //����
	int T;   //��ʦ

	std::vector<Class> vC;
	std::vector<Time> vP;
	std::vector<Subject> vS;
	std::vector<ClassRoom> vR;
	std::vector<Teacher> vT;
};

