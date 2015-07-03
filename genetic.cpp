#include "genetic.h"

int Genetic::rand01()
{
	return rand()%2;
}

double Genetic::randab(double a, double b)
{
	double c,r;
    c=b-a;
    r=a+c*rand()/(RAND_MAX+1.0);
    return r;
}

void Genetic::init(int start)
{
	//初始化M个假设
	srand(time(0));
	for (int i=start;i<start+M;i++)
	{
		for (int j=0;j<5;j++)
			V[i].G[j]=rand01();
	}
}

void Genetic::encoding()
{
	
}

int Genetic::decoding(int i)
{
	int sum;
	for (int j=0;j<5;j++) sum+=V[i].G[j]<<j;
}

void Genetic::evalueFitness(int start)
{
	sumfitness=0;
	for (int i=start;i<start+M;i++)
	{
		V[i].fitness=decoding(i);
		sumfitness+=V[i].fitness;
	}
}

void Genetic::choose_pi()
{
	
}

void Genetic::crossover()
{

}

void Genetic::mutation()
{

}

void Genetic::GA()
{

}