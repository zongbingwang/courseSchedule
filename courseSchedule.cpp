// courseSchedule.cpp : 定义控制台应用程序的入口点。
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
		printf("第%d次结果:\n",10-T);
		p.printResult();
	}
	

	system("pause");
	return 0;
}

