#pragma once
#include "afxdialogex.h"
#include "StudentEntity.h"
#include "MFC_StudentManageDlg.h"

// AddStudent dialog

class AddStudent : public CDialog
{
	DECLARE_DYNAMIC(AddStudent)

public:
	AddStudent(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddStudent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddStudent_Btn };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	StudentEntity m_Student;

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_inputStudentId;
	CEdit m_inputStudentName;
	CEdit m_inputStudentMarks;
	
	CEdit m_inputStudentMarks2;
	CEdit m_inputStudentMarks3;
	afx_msg void OnBnClickedFinaladdstudent();
	StudentEntity getStudent() { return m_Student; }
	afx_msg void OnBnClickedCancel();
};
