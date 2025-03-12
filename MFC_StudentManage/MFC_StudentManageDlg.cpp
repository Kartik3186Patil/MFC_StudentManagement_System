
// MFC_StudentManageDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_StudentManage.h"
#include "MFC_StudentManageDlg.h"
#include "afxdialogex.h"
#include "AddStudent.h"
#include "StudentEntity.h"
#include "UpdateStudent.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCStudentManageDlg dialog



CMFCStudentManageDlg::CMFCStudentManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MainPage, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStudentManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ListHomePage, m_inputStudents);
	DDX_Control(pDX, IDC_ListHomePage, m_inputStudents);
}

BEGIN_MESSAGE_MAP(CMFCStudentManageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AddStudent, &CMFCStudentManageDlg::OnBnClickedAddstudent)
	ON_BN_CLICKED(IDC_Result, &CMFCStudentManageDlg::OnBnClickedResult)
	ON_BN_CLICKED(IDC_UpdateStudent, &CMFCStudentManageDlg::OnBnClickedUpdatestudent)
END_MESSAGE_MAP()


// CMFCStudentManageDlg message handlers

BOOL CMFCStudentManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCStudentManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCStudentManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCStudentManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCStudentManageDlg::OnBnClickedAddstudent()
{
	AddStudent dlgB;

	if (dlgB.DoModal() == IDD_AddStudent_Btn)
	{
		StudentEntity student = dlgB.getStudent();
		m_pStudentManager->saveStudent(student);

		//// Refresh the student list
		LoadStudentData();
	}
}

void CMFCStudentManageDlg::DisplayStudents(StudentEntity &student) {
	m_inputStudents.AddString(CString(std::to_string(student.getId()).c_str()) + _T(" ") + CString(student.getName().c_str()));

}

void CMFCStudentManageDlg::OnBnClickedResult()
{
	ResultDisplay dlgResult;
	dlgResult.SetStudentManager(m_pStudentManager.get()); // ✅ Pass raw pointer
	dlgResult.DoModal();
}

void CMFCStudentManageDlg::OnBnClickedUpdatestudent()
{
	int selectedIndex = m_inputStudents.GetCurSel();
	if (selectedIndex == LB_ERR)
	{
		AfxMessageBox(_T("Please select a student from the list."));
		return;
	}

	CString selectedEntry;
	m_inputStudents.GetText(selectedIndex, selectedEntry);

	// ✅ Extract Student ID (first value in the string)
	int selectedID;
	if (_stscanf_s(selectedEntry, _T("ID: %d"), &selectedID) != 1)
	{
		AfxMessageBox(_T("Error extracting Student ID."), MB_ICONERROR);
		return;
	}

	// ✅ Retrieve student from StudentManager
	StudentEntity selectedStudent;
	if (m_pStudentManager->getStudentById(selectedID, selectedStudent))
	{
		UpdateStudent dlgUpdate;
		dlgUpdate.SetStudentData(selectedStudent);

		if (dlgUpdate.DoModal() == IDOK)
		{
			// ✅ Get updated student data and update in StudentManager
			StudentEntity updatedStudent = dlgUpdate.getUpdatedStudent();
			m_pStudentManager->updateStudent(selectedID, updatedStudent);

			// ✅ Refresh UI after updating
			LoadStudentData();
		}
	}
	else
	{
		AfxMessageBox(_T("Student not found."), MB_ICONERROR);
	}
}


void CMFCStudentManageDlg::LoadStudentData()
{
	m_inputStudents.ResetContent(); // Clear previous entries

	for (const auto& student : m_pStudentManager->getAllStudents())
	{
		CString studentEntry;
		studentEntry.Format(_T("ID: %d | Name: %s | Marks: %d, %d, %d"),
			student.getId(),
			CString(student.getName().c_str()),
			student.getSubMark1(),
			student.getSubMark2(),
			student.getSubMark3());

		m_inputStudents.AddString(studentEntry); // Add full details to ListBox
	}
}



