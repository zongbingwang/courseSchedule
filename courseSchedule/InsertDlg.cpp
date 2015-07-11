// InsertDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "courseSchedule.h"
#include "InsertDlg.h"
#include "afxdialogex.h"


// CInsertDlg 对话框

IMPLEMENT_DYNAMIC(CInsertDlg, CDialogEx)

CInsertDlg::CInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertDlg::IDD, pParent)
{

}

CInsertDlg::~CInsertDlg()
{
}

void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInsertDlg, CDialogEx)
END_MESSAGE_MAP()


// CInsertDlg 消息处理程序
