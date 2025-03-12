// UpdateStudent.cpp : implementation file
//

#include "pch.h"
#include "MFC_StudentManage.h"
#include "afxdialogex.h"
#include "UpdateStudent.h"
#include "StudentEntity.h"
#include "MFC_StudentManageDlg.h"


// UpdateStudent dialog

IMPLEMENT_DYNAMIC(UpdateStudent, CDialog)

UpdateStudent::UpdateStudent(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_UpdateStudent_Btn, pParent)
{

}

UpdateStudent::~UpdateStudent()
{
}

void UpdateStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_editUpdate_Id, m_update_id);
	DDX_Control(pDX, IDC_editUpdate_marks1, m_update_marks1);
	DDX_Control(pDX, IDC_editUpdate_marks2, m_update_marks2);
	DDX_Control(pDX, IDC_editUpdate_marks3, m_update_marks3);
}


BEGIN_MESSAGE_MAP(UpdateStudent, CDialog)
	ON_BN_CLICKED(IDC_UpdateStudent, &UpdateStudent::OnBnClickedUpdatestudent)
END_MESSAGE_MAP()


// UpdateStudent message handlers

void UpdateStudent::OnBnClickedUpdatestudent()
{
    CString st_marks1, st_marks2, st_marks3;

    // Get values from edit boxes
    m_update_marks1.GetWindowTextW(st_marks1);
    m_update_marks2.GetWindowTextW(st_marks2);
    m_update_marks3.GetWindowTextW(st_marks3);

    // Convert CString to int
    int markStudent1 = _ttoi(st_marks1);
    int markStudent2 = _ttoi(st_marks2);
    int markStudent3 = _ttoi(st_marks3);

    // Update the student entity
    m_Student.setSubMark1(markStudent1);
    m_Student.setSubMark2(markStudent2);
    m_Student.setSubMark3(markStudent3);

    CString debugMsg;
    debugMsg.Format(_T("Updated Marks:\nMarks1: %d\nMarks2: %d\nMarks3: %d"), markStudent1, markStudent2, markStudent3);
    AfxMessageBox(debugMsg);

    // Close the dialog with success
    EndDialog(IDOK);
}
void UpdateStudent::SetStudentData(const StudentEntity& student)
{
    m_Student = student;
}
BOOL UpdateStudent::OnInitDialog()
{
    CDialog::OnInitDialog();  // Call base class initialization

    // Pre-fill the fields with existing data
    CString idStr, marks1Str, marks2Str, marks3Str;

    idStr.Format(_T("%d"), m_Student.getId());
    marks1Str.Format(_T("%d"), m_Student.getSubMark1());
    marks2Str.Format(_T("%d"), m_Student.getSubMark2());
    marks3Str.Format(_T("%d"), m_Student.getSubMark3());

    m_update_id.SetWindowTextW(idStr);
    m_update_marks1.SetWindowTextW(marks1Str);
    m_update_marks2.SetWindowTextW(marks2Str);
    m_update_marks3.SetWindowTextW(marks3Str);
    m_update_id.EnableWindow(FALSE);

    return TRUE;  // Return TRUE unless you want to set focus to a control
}




//CString st_id;
//CString st_marks1;
//CString st_marks2;
//CString st_marks3;
//m_update_id.GetWindowTextW(st_id);
//m_update_marks1.GetWindowTextW(st_marks1);
//m_update_marks2.GetWindowTextW(st_marks2);
//m_update_marks3.GetWindowTextW(st_marks3);
//
//int markStudent1 = _ttoi(st_marks1);
//int markStudent2 = _ttoi(st_marks2);
//int markStudent3 = _ttoi(st_marks3);
//
//m_Student.setSubMark1(markStudent1);
//m_Student.setSubMark2(markStudent2);
//m_Student.setSubMark3(markStudent3);
//
//EndDialog(IDD_UpdateStudent_Btn);

