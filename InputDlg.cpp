// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "courseSchedule.h"
#include "InputDlg.h"
#include "afxdialogex.h"



// CInputDlg 对话框

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_classList);
	DDX_Control(pDX, IDC_EDIT3, m_className);
	DDX_Control(pDX, IDC_EDIT2, m_classNum);
	DDX_Control(pDX, IDC_EDIT1, m_college);
	DDX_Control(pDX, IDC_EDIT5, m_roomName);
	DDX_Control(pDX, IDC_EDIT4, m_roomNum);
	DDX_Control(pDX, IDC_LIST2, m_roomList);
	DDX_Control(pDX, IDC_LIST3, m_teacherList);
	DDX_Control(pDX, IDC_EDIT6, m_teacherName);
	DDX_Control(pDX, IDC_COMBO1, m_combo_className);
	DDX_Control(pDX, IDC_COMBO2, m_combo_teacherName);
	DDX_Control(pDX, IDC_EDIT8, m_lessonName);
	DDX_Control(pDX, IDC_EDIT7, m_allTime);
	DDX_Control(pDX, IDC_EDIT9, m_weekTime);
	DDX_Control(pDX, IDC_LIST4, m_lessonList);
	DDX_Control(pDX, IDC_EDIT10, m_classID);
	DDX_Control(pDX, IDC_EDIT11, m_roomID);
	DDX_Control(pDX, IDC_EDIT12, m_teacherID);
	DDX_Control(pDX, IDC_EDIT13, m_timeID);
	DDX_Control(pDX, IDC_EDIT14, m_timeDay);
	DDX_Control(pDX, IDC_EDIT15, m_timeDay_Lesson);
	DDX_Control(pDX, IDC_LIST5, m_timeList);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CInputDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CInputDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CInputDlg::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CInputDlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT5, &CInputDlg::OnEnChangeEdit5)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CInputDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CInputDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CInputDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CInputDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CInputDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CInputDlg 消息处理程序
BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//添加列表项
	num_class = 0;
	num_room = 0;
	num_teacher = 0;
	num_lesson = 0;

	CRect classRect;
	m_classList.GetClientRect(&classRect);
	/****************ListControl-Class*******************/
	// 为列表视图控件添加全行选中和栅格风格   
	m_classList.SetExtendedStyle(m_classList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	// 为列表视图控件添加三列   
	m_classList.InsertColumn(1, _T("班级ID"), LVCFMT_LEFT, 80);//在Listctrl控件上添加列，与数据库table对应。
	m_classList.InsertColumn(2, _T("班级名字"), LVCFMT_LEFT, 150);
	m_classList.InsertColumn(3, _T("班级人数"), LVCFMT_LEFT, 100);
	m_classList.InsertColumn(4, _T("学院"), LVCFMT_LEFT, 200);
	CString cmdStr = _T("SELECT * FROM class order by classID Desc"); 
	m_classShow(cmdStr);


	/****************ListControl-Room*******************/
	CRect roomRect;
	m_roomList.GetClientRect(&roomRect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_roomList.SetExtendedStyle(m_roomList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	// 为列表视图控件添加三列   
	m_roomList.InsertColumn(1, _T("教室ID"), LVCFMT_LEFT, 80);//在Listctrl控件上添加列，与数据库table对应。
	m_roomList.InsertColumn(2, _T("教室名字"), LVCFMT_LEFT, 140);
	m_roomList.InsertColumn(3, _T("教室容量"), LVCFMT_LEFT, 140);
	CString cmdStr_room = _T("SELECT * FROM room order by roomID Desc");
	m_roomShow(cmdStr_room);

	/****************ListControl-Teacher*******************/
	CRect teacherRect;
	m_teacherList.GetClientRect(&teacherRect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_teacherList.SetExtendedStyle(m_teacherList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_teacherList.InsertColumn(1, _T("教师ID"), LVCFMT_LEFT, 80);//在Listctrl控件上添加列，与数据库table对应。
	m_teacherList.InsertColumn(2, _T("教师名字"), LVCFMT_LEFT, 140);
	CString cmdStr_teacher = _T("SELECT * FROM teacher order by teacherID Desc");
	m_teacherShow(cmdStr_teacher);


	/****************ListControl-Teacher*******************/
	CRect lessonRect;
	m_lessonList.GetClientRect(&lessonRect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_lessonList.SetExtendedStyle(m_lessonList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_lessonList.InsertColumn(1, _T("课程ID"), LVCFMT_LEFT, 80);//在Listctrl控件上添加列，与数据库table对应。
	m_lessonList.InsertColumn(2, _T("课程名"), LVCFMT_LEFT, 150);
	m_lessonList.InsertColumn(3, _T("总学时"), LVCFMT_LEFT, 100);
	m_lessonList.InsertColumn(4, _T("周学时"), LVCFMT_LEFT, 200);
	m_lessonList.InsertColumn(5, _T("班级ID"), LVCFMT_LEFT, 200);
	m_lessonList.InsertColumn(6, _T("教师ID"), LVCFMT_LEFT, 200);
	CString cmdStr_lesson = _T("SELECT * FROM course order by courseID Desc");
	m_lessonShow(cmdStr_lesson);

	/****************Combo1_ClassName*******************/
	// 默认选择第一项   
	m_combo_className.SetCurSel(0);

	/****************Combo2_TeacherName*******************/
	// 为组合框控件的列表框添加列表项“鸡啄米”   

	// 默认选择第一项   
	m_combo_teacherName.SetCurSel(0);

	/****************ListControl-Time*******************/
	CRect timeRect;
	m_timeList.GetClientRect(&timeRect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_timeList.SetExtendedStyle(m_lessonList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_timeList.InsertColumn(1, _T("时间ID"), LVCFMT_LEFT, 80);//在Listctrl控件上添加列，与数据库table对应。
	m_timeList.InsertColumn(2, _T("星期几"), LVCFMT_LEFT, 150);
	m_timeList.InsertColumn(3, _T("第几节课"), LVCFMT_LEFT, 150);
	CString cmdStr_time = _T("SELECT * FROM time order by timeID Desc");
	m_timeShow(cmdStr_time);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}

void CInputDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInputDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInputDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	m_classID.GetWindowTextW(str);
	m_classList.InsertItem(num_class, str);

	m_className.GetWindowTextW(str);
	//m_className.SetWindowTextW(_T(""));
	m_classList.SetItemText(num_class, 1, str);
	//classlist[num_class] = str;//将教室的名字存到数组中

	//保存到下拉框
	m_combo_className.AddString(str);

	m_classNum.GetWindowTextW(str);
	m_classList.SetItemText(num_class, 2, str);

	m_college.GetWindowTextW(str);
	m_classList.SetItemText(num_class, 3, str);

	//新任务列表增加
	num_class++;

	CDatabase db;
	db.Open(NULL, FALSE, FALSE, _T("ODBC;DSN=TEST2;UID=root;PWD=1234"));
	CString Name, Num, ID, College;
	m_classID.GetWindowText(ID);
	m_className.GetWindowText(Name);
	m_classNum.GetWindowText(Num);
	m_college.GetWindowText(College);
	str.Format(L"insert into class values('%s','%s','%s','%s')", ID, Name, Num, College);
	db.ExecuteSQL(str);
	db.Close();
	CString cmdStr = _T("SELECT   * FROM class order by classID Desc");
	m_classShow(cmdStr);
}


void CInputDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void CInputDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CInputDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void CInputDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	m_roomID.GetWindowTextW(str);
	//m_roomID.SetWindowTextW(_T(""));
	m_roomList.InsertItem(num_room, str);

	m_roomName.GetWindowTextW(str);
	//m_roomName.SetWindowTextW(_T(""));
	m_roomList.SetItemText(num_room, 1, str);

	m_roomNum.GetWindowTextW(str);
	m_roomList.SetItemText(num_room, 2, str);

	//新任务列表增加
	num_room++;

	CDatabase db;
	db.Open(NULL, FALSE, FALSE, _T("ODBC;DSN=TEST2;UID=root;PWD=1234"));
	CString Name, Num, ID;
	m_roomID.GetWindowText(ID);
	m_roomName.GetWindowText(Name);
	m_roomNum.GetWindowText(Num);
	str.Format(L"insert into room values('%s','%s','%s')", ID, Name, Num);
	db.ExecuteSQL(str);
	db.Close();
	CString cmdStr = _T("SELECT   * FROM room order by roomID Desc");
	m_roomShow(cmdStr);
}


void CInputDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代
	CString str;
	m_teacherID.GetWindowTextW(str);
	m_teacherList.InsertItem(num_room, str);

	m_teacherName.GetWindowTextW(str);
	m_teacherList.SetItemText(num_room, 1, str);
	m_combo_teacherName.AddString(str);
	//新任务列表增加
	num_teacher++;

	CDatabase db;
	db.Open(NULL, FALSE, FALSE, _T("ODBC;DSN=TEST2;UID=root;PWD=1234"));
	CString Name, ID;
	m_teacherID.GetWindowText(ID);
	m_teacherName.GetWindowText(Name);
	str.Format(L"insert into teacher values('%s','%s')", ID, Name);
	db.ExecuteSQL(str);
	db.Close();
	CString cmdStr = _T("SELECT   * FROM teacher order by teacherID Desc");
	m_teacherShow(cmdStr);
}


void CInputDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;

	m_lessonName.GetWindowTextW(str);
	m_lessonName.SetWindowTextW(_T(""));
	m_lessonList.InsertItem(num_lesson, str);

	m_allTime.GetWindowTextW(str);
	m_allTime.SetWindowTextW(_T(""));
	m_lessonList.SetItemText(num_lesson, 1, str);

	m_weekTime.GetWindowTextW(str);
	m_weekTime.SetWindowTextW(_T(""));
	m_lessonList.SetItemText(num_lesson, 2, str);

	m_combo_className.GetWindowTextW(str);
	m_combo_className.SetWindowTextW(_T(""));
	m_lessonList.SetItemText(num_lesson, 3, str);

	m_combo_teacherName.GetWindowTextW(str);
	m_combo_teacherName.SetWindowTextW(_T(""));
	m_lessonList.SetItemText(num_lesson, 4, str);

	//新任务列表增加
	num_lesson++;
}

// get data from database and show them in list control
void CInputDlg::m_classShow(CString cmdStr)
{
	m_classList.DeleteAllItems();
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"classID", varID);
		m_classList.InsertItem(0, varID);
		CString varName;
		rs.GetFieldValue(L"className", varName);
		m_classList.SetItemText(0, 1, varName);
		CString varNum;
		rs.GetFieldValue(L"classNum", varNum);
		m_classList.SetItemText(0, 2, varNum);
		CString varCollege;
		rs.GetFieldValue(L"college", varCollege);
		m_classList.SetItemText(0, 3, varCollege);
		rs.MoveNext();
	}
	m_classList.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // | LVS_SINGLESEL);
	rs.Close();
	db.Close();
}
void CInputDlg::m_roomShow(CString cmdStr)
{
	m_roomList.DeleteAllItems();
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"roomID", varID);
		m_roomList.InsertItem(0, varID);
		CString varName;
		rs.GetFieldValue(L"roomName", varName);
		m_roomList.SetItemText(0, 1, varName);
		CString varNum;
		rs.GetFieldValue(L"roomNum", varNum);
		m_roomList.SetItemText(0, 2, varNum);
		rs.MoveNext();
	}
	m_roomList.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // | LVS_SINGLESEL);
	rs.Close();
	db.Close();
}
void CInputDlg::m_teacherShow(CString cmdStr)
{
	m_teacherList.DeleteAllItems();
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"teacherID", varID);
		m_teacherList.InsertItem(0, varID);
		CString varName;
		rs.GetFieldValue(L"teacherName", varName);
		m_teacherList.SetItemText(0, 1, varName);
		rs.MoveNext();
	}
	m_teacherList.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // | LVS_SINGLESEL);
	rs.Close();
	db.Close();
}
void CInputDlg::m_timeShow(CString cmdStr)
{
	m_timeList.DeleteAllItems();
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"timeID", varID);
		m_timeList.InsertItem(0, varID);
		CString varDay;
		rs.GetFieldValue(L"timeDay", varDay);
		m_timeList.SetItemText(0, 1, varDay);
		CString varN;
		rs.GetFieldValue(L"N", varN);
		m_timeList.SetItemText(0, 2, varN);
		rs.MoveNext();
	}
	m_timeList.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // | LVS_SINGLESEL);
	rs.Close();
	db.Close();
}
void CInputDlg::m_lessonShow(CString cmdStr)
{
	m_lessonList.DeleteAllItems();
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"courseID", varID);
		m_lessonList.InsertItem(0, varID);
		CString varName;
		rs.GetFieldValue(L"courseName", varName);
		m_lessonList.SetItemText(0, 1, varName);
		CString varTotalTime;
		rs.GetFieldValue(L"totalTime", varTotalTime);
		m_lessonList.SetItemText(0, 2, varTotalTime);
		CString varWeekTime;
		rs.GetFieldValue(L"weekTime", varWeekTime);
		m_lessonList.SetItemText(0, 3, varWeekTime);
		CString varClassID;
		rs.GetFieldValue(L"classID", varClassID);
		m_lessonList.SetItemText(0, 4, varClassID);
		CString varTeacherID;
		rs.GetFieldValue(L"teacherID", varTeacherID);
		m_lessonList.SetItemText(0, 5, varTeacherID);

		rs.MoveNext();
	}
	m_lessonList.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // | LVS_SINGLESEL);
	rs.Close();
	db.Close();
}



void CInputDlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	a.init();
	a.run(1000);
	a.print();
}
