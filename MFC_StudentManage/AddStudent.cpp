// AddStudent.cpp : implementation file
//

#include "pch.h"
#include "MFC_StudentManage.h"
#include "afxdialogex.h"
#include "AddStudent.h"


// AddStudent dialog

IMPLEMENT_DYNAMIC(AddStudent, CDialog)

AddStudent::AddStudent(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_AddStudent_Btn, pParent)
{

}

AddStudent::~AddStudent()
{
}

void AddStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_InputID, m_inputStudentId);
	DDX_Control(pDX, IDC_InputName, m_inputStudentName);
	DDX_Control(pDX, IDC_InputMarks1, m_inputStudentMarks);
	DDX_Control(pDX, IDC_InputMarks2, m_inputStudentMarks2);
	DDX_Control(pDX, IDC_InputMarks3, m_inputStudentMarks3);
}


BEGIN_MESSAGE_MAP(AddStudent, CDialog)
	
	ON_BN_CLICKED(IDC_FinalAddStudent, &AddStudent::OnBnClickedFinaladdstudent)
	ON_BN_CLICKED(IDCANCEL, &AddStudent::OnBnClickedCancel)
END_MESSAGE_MAP()


void AddStudent::OnBnClickedFinaladdstudent()
{
    CString studentName, studentId, studentMarks1, studentMarks2, studentMarks3;

    m_inputStudentId.GetWindowTextW(studentId);
    m_inputStudentName.GetWindowTextW(studentName);
    m_inputStudentMarks.GetWindowTextW(studentMarks1);
    m_inputStudentMarks2.GetWindowTextW(studentMarks2);
    m_inputStudentMarks3.GetWindowTextW(studentMarks3);

    // ✅ Check if any field is empty
    if (studentId.IsEmpty() || studentName.IsEmpty() ||
        studentMarks1.IsEmpty() || studentMarks2.IsEmpty() || studentMarks3.IsEmpty())
    {
        AfxMessageBox(_T("All fields are required!"));
        return;
    }

    // ✅ Convert values
    int idStudent = _ttoi(studentId);
    CT2A ascii(studentName);
    string nameStudent = string(ascii);
    int markStudent1 = _ttoi(studentMarks1);
    int markStudent2 = _ttoi(studentMarks2);
    int markStudent3 = _ttoi(studentMarks3);

    // ✅ Save data
    m_Student.setId(idStudent);
    m_Student.setName(nameStudent);
    m_Student.setSubMark1(markStudent1);
    m_Student.setSubMark2(markStudent2);
    m_Student.setSubMark3(markStudent3);

    EndDialog(IDD_AddStudent_Btn);
}


void AddStudent::OnBnClickedCancel()
{
	
	CDialog::OnCancel();
}
