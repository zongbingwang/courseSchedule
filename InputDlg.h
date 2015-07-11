#pragma once
#include "stdafx.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "applaction.h"


// CInputDlg 对话框

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputDlg();
	CString classlist[100];
	CString teacherlist[100];
	void m_classShow(CString cmdStr);
	void m_roomShow(CString cmdStr);
	void m_teacherShow(CString cmdStr);
	void m_lessonShow(CString cmdStr);
	void m_timeShow(CString cmdStr);


	
	// 对话框数据
	enum { IDD = IDD_DIALOG1 };

    Applaction a;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_classList;
	afx_msg void OnEnChangeEdit3();
	CEdit m_className;
	CEdit m_classNum;
	afx_msg void OnEnChangeEdit1();
	CEdit m_college;
	afx_msg void OnBnClickedButton1();
	int num_class;//Class Counter

	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit5();
	CEdit m_roomName; 
	CEdit m_roomNum;
	CListCtrl m_roomList;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	int num_room;//Room Counter

	afx_msg void OnBnClickedButton2();
	CListCtrl m_teacherList;
	CEdit m_teacherName;
	afx_msg void OnBnClickedButton3();
	int num_teacher;//Teacher Counter
	CComboBox m_combo_className;
	CComboBox m_combo_teacherName;

	afx_msg void OnBnClickedButton4();
	CEdit m_lessonName;
	CEdit m_allTime;
	CEdit m_weekTime;
	CListCtrl m_lessonList;
	int num_lesson;//Lesson Counter
	CEdit m_classID;
	CEdit m_roomID;
	CEdit m_teacherID;
	CEdit m_timeID;
	CEdit m_timeDay;
	CEdit m_timeDay_Lesson;
	CListCtrl m_timeList;
	afx_msg void OnBnClickedButton6();
};
