
// CourseSchedule1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "InputDlg.h"
#include "InsertDlg.h"
// CCourseSchedule1Dlg �Ի���
class CCourseSchedule1Dlg : public CDialogEx
{
// ����
public:
	CCourseSchedule1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CInputDlg m_inputDlg;
	CInsertDlg m_insertDlg;

// �Ի�������
	enum { IDD = IDD_COURSESCHEDULE1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
