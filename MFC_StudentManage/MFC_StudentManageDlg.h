#pragma once
#include "StudentEntity.h"
#include "StudentManager.h"
#include <memory>
#include "ResultDisplay.h"

// CMFCStudentManageDlg dialog
class CMFCStudentManageDlg : public CDialogEx
{
	// Construction
public:
	CMFCStudentManageDlg(CWnd* pParent = nullptr);	// standard constructor
	StudentEntity m_studentData;
	std::unique_ptr<StudentManager> m_pStudentManager = std::make_unique<StudentManager>();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MainPage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedAddstudent();
	void DisplayStudents(StudentEntity& student);
	void LoadStudentData();
	afx_msg void OnBnClickedResult();
	afx_msg void OnBnClickedUpdatestudent();
	CListBox m_inputStudents;
};
