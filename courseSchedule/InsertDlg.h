#pragma once


// CInsertDlg �Ի���

class CInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertDlg)

public:
	CInsertDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
