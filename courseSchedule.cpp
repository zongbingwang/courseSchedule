// courseSchedule.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "genetic.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Genetic p;
	int T=100;

	p.init();


	while(T--)
	{
		p.GA();
		//printf("��%d�ν��:\n",100-T);
		//p.printResult();
	}
	printf("��%d�ν��:\n",100-T);
	p.printResult();

	system("pause");
	return 0;
}

