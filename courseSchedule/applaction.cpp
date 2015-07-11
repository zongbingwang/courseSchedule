#include "stdafx.h"
#include "applaction.h"

 Applaction:: Applaction()
{
}

 Applaction::~ Applaction()
{
}

void Applaction::run(int T)
{
	while(T--)
	{
		//printf("第%d次结果:\n",10-T);
		p.GA();
		//p.printResult();
	}
}

void Applaction::init()
{
	p.init();
}

void Applaction::print()
{
	p.printResult();
}

