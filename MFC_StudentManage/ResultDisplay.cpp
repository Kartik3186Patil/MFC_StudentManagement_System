// ResultDisplay.cpp : implementation file
//

#include "pch.h"
#include "MFC_StudentManage.h"
#include "afxdialogex.h"
#include<algorithm>
#include "ResultDisplay.h"
using namespace std;


// ResultDisplay dialog

IMPLEMENT_DYNAMIC(ResultDisplay, CDialogEx)

ResultDisplay::ResultDisplay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Result_Btn, pParent)
{

}

ResultDisplay::~ResultDisplay()
{
}

void ResultDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AllResultDisplay, m_listTotalMarks);
	DDX_Control(pDX, IDC_mark1Topper, m_listHighestSubject1);
	DDX_Control(pDX, IDC_mark2Topper, m_listHighestSubject2);
	DDX_Control(pDX, IDC_mark3Topper, m_listHighestSubject3);
}


BEGIN_MESSAGE_MAP(ResultDisplay, CDialogEx)
	ON_BN_CLICKED(IDOK, &ResultDisplay::OnBnClickedOk)
    ON_STN_CLICKED(IDC_sub2, &ResultDisplay::OnStnClickedsub2)
END_MESSAGE_MAP()


// ResultDisplay message handlers

void ResultDisplay::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();

}
void ResultDisplay::SetStudentManager(StudentManager* pStudentManager)
{
    m_pStudentManager = pStudentManager; // ✅ Store the raw pointer
}

BOOL ResultDisplay::OnInitDialog() {
    CDialog::OnInitDialog(); // Call base class

    if (!m_pStudentManager)
    {
        AfxMessageBox(_T("No student data available."));
        return TRUE;
    }

    // Get all students
    std::vector<StudentEntity> students = m_pStudentManager->getAllStudents();

    // ✅ Ensure sorting is correct
    std::sort(students.begin(), students.end(), [](const StudentEntity& a, const StudentEntity& b) {
        int totalA = a.getSubMark1() + a.getSubMark2() + a.getSubMark3();
        int totalB = b.getSubMark1() + b.getSubMark2() + b.getSubMark3();
        return totalA > totalB; // ✅ Sorting in descending order
        });

    // ✅ Clear ListBox before adding new values
    m_listTotalMarks.ResetContent();

    // ✅ Fill ListBox 1: Display toppers sorted by total marks
    for (const auto& student : students)
    {
        int totalMarks = student.getSubMark1() + student.getSubMark2() + student.getSubMark3();
        CString entry;
        entry.Format(_T("%s - Total Marks: %d"), CString(student.getName().c_str()), totalMarks);
        m_listTotalMarks.AddString(entry);
    }

    StudentEntity* topSubject1 = nullptr;
    StudentEntity* topSubject2 = nullptr;
    StudentEntity* topSubject3 = nullptr;

    for (auto& student : students)
    {
        if (!topSubject1 || student.getSubMark1() > topSubject1->getSubMark1())
            topSubject1 = &student;

        if (!topSubject2 || student.getSubMark2() > topSubject2->getSubMark2())
            topSubject2 = &student;

        if (!topSubject3 || student.getSubMark3() > topSubject3->getSubMark3())
            topSubject3 = &student;
    }

    // Fill ListBox 2 (Highest in Subject 1)
    if (topSubject1)
    {
        CString entry;
        entry.Format(_T("%s - Marks: %d"), CString(topSubject1->getName().c_str()), topSubject1->getSubMark1());
        m_listHighestSubject1.AddString(entry);
    }

    // Fill ListBox 3 (Highest in Subject 2)
    if (topSubject2)
    {
        CString entry;
        entry.Format(_T("%s - Marks: %d"), CString(topSubject2->getName().c_str()), topSubject2->getSubMark2());
        m_listHighestSubject2.AddString(entry);
    }

    // Fill ListBox 4 (Highest in Subject 3)
    if (topSubject3)
    {
        CString entry;
        entry.Format(_T("%s - Marks: %d"), CString(topSubject3->getName().c_str()), topSubject3->getSubMark3());
        m_listHighestSubject3.AddString(entry);
    }

    return TRUE;
}

void ResultDisplay::OnStnClickedsub2()
{
    // TODO: Add your control notification handler code here
}
