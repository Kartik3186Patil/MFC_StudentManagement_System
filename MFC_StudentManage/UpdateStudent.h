#pragma once
#include "afxdialogex.h"
#include "StudentEntity.h"
#include "MFC_StudentManageDlg.h"

// UpdateStudent dialog

class UpdateStudent : public CDialog
{
	DECLARE_DYNAMIC(UpdateStudent)

public:
	UpdateStudent(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UpdateStudent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateStudent_Btn};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	StudentEntity m_Student;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUpdatestudent();
	CEdit m_update_id;
	CEdit m_update_marks1;
	CEdit m_update_marks2;
	CEdit m_update_marks3;

	//given by chatgpt
	void SetStudentData(const StudentEntity& student);
	StudentEntity getUpdatedStudent() { return m_Student; }
	virtual BOOL OnInitDialog() override;

	
};

//StudentEntity getUpdatedStudent() { return m_Student; }