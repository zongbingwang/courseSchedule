
// CourseSchedule1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCourseSchedule1App: 
// �йش����ʵ�֣������ CourseSchedule1.cpp
//

class CCourseSchedule1App : public CWinApp
{
public:
	CCourseSchedule1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCourseSchedule1App theApp;