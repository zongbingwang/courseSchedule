#include "stdafx.h"
#include "tools.h"
//cst-CString
//i-int
// 整形转换为LPCSTR
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