// courseSchedule.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "genetic.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Genetic p;
	int T=10;

	p.init();


	while(T--)
	{
		p.GA();
		printf("��%d�ν��:\n",10-T);
		p.printResult();
	}
	

	system("pause");
	return 0;
}

