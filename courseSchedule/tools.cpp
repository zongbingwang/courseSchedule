#include "stdafx.h"
#include "tools.h"
//cst-CString
//i-int
// ����ת��ΪLPCSTR
CString cstoi(int i)
{
	static CString str;
	str.Format(L"%d", i);
	return str;
}

int itocst(CString str)
{
	static int i;
	i = _ttoi(str);
	return i;
}