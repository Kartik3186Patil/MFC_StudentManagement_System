#pragma once
#include "afxdialogex.h"
#include "StudentEntity.h"
#include "StudentManager.h"
#include<memory>



// ResultDisplay dialog

class ResultDisplay : public CDialogEx
{
	DECLARE_DYNAMIC(ResultDisplay)

public:
	ResultDisplay(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ResultDisplay();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Result_Btn };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CListBox m_listTotalMarks;
	CListBox m_listHighestSubject1;
	CListBox m_listHighestSubject2;
	CListBox m_listHighestSubject3;

	void SetStudentManager(StudentManager* pStudentManager);
	// Pass student data
	virtual BOOL OnInitDialog();
private:
	StudentManager* m_pStudentManager;

public:
	afx_msg void OnStnClickedsub2();
};
