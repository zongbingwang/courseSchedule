#include "stdafx.h"
#include "genetic.h"

int Genetic::getNew(int old)
{
	return old==0 ? M:0;
}

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

int Genetic::randab(int a, int b)
{
	int c,r;
    c=b-a;
	r=a+rand()%(c+1);
    return r;
}

void Genetic::init()
{
	//初始化M个假设
	srand( (unsigned)time(NULL));
	for (int i=0;i<M;i++)
	{
		for (int j=0;j<5;j++)
			V[i].G[j]=rand01();
	}
	start_id=0;
}

void Genetic::encoding()
{
	
}

int Genetic::decoding(int i)
{
	int sum=0;
	for (int j=0;j<5;j++) sum+=V[i].G[j]<<j;
	return sum;
}

void Genetic::evalueFitness(int start)
{
	sumfitness=0;
	for (int i=start;i<start+M;i++)
	{
		V[i].fitness=decoding(i);
		V[i].fitness=1/((V[i].fitness-10)*(V[i].fitness-10)+1);      //f[x]=(x-10)^2;
		sumfitness+=V[i].fitness;
	}

}

void Genetic::choose_pi(int start)
{
	//srand((int)time(0));
	//srand( (unsigned)time(NULL));
	int next=getNew(start);

	for (int i=0;i<M;i++)
	{
		double value=randab(0.0, 1.0);
		//printf("%f\n",value);
		double temPi=0;
		for (int j=start;j<start+M;j++)
		{
			if (temPi<value && value<=temPi+V[j].fitness/sumfitness) { /*printf("%d %f %f\n",j,value, temPi);*/V[next++]=V[j];}
			temPi+=(V[j].fitness/sumfitness);
		}
		//printf("%lf   %lf\n",temPi,sumfitness);
	}

	start_id=next-M;
}

void Genetic::crossover(int start)
{
	//srand(time(0));
	int next=getNew(start);

	for (int i=0;i<M/2;i++)
	{
		int father;
		int mather;

		while (true)
		{
			father=start+randab(0,M-1);
			mather=start+randab(0,M-1);
			if (father!=mather) break;
		}

		int middle=randab(0,N-1);
		for (int j=0;j<=middle;j++)
		{
			V[next].G[j]=V[father].G[j];
			V[next+1].G[j]=V[mather].G[j];
		}
		for (int j=middle+1;j<N;j++)
		{
			V[next].G[j]=V[mather].G[j];
			V[next+1].G[j]=V[father].G[j];
		}
		next+=2;
	}

	start_id=next-M;
}

void Genetic::mutation(int start)
{
	//srand(time(0));
	int next=getNew(start);

	for (int i=0;i<M;i++)
	{
		V[next]=V[start];

		double mutate=randab(0.0,1.0);
		if (mutate>pm)
		{
			next++;
			start++;
			continue;
		}

		int id=randab(0,N-1);
		V[next++].G[id]=!V[start++].G[id];
	}

	start_id=next-M;
}

void Genetic::GA()
{
	evalueFitness(start_id);
	choose_pi(start_id);
	crossover(start_id);
	mutation(start_id);
}

void Genetic::printResult()
{
	int start=start_id;
	for (int i=start;i<start+M;i++)
		printf("%d\n",decoding(i));
}