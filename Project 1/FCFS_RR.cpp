// FCFS_RR.cpp : implementation file
//

#include "stdafx.h"
#include "Project 1.h"
#include "FCFS_RR.h"
#include "afxdialogex.h"


// CFCFS_RR dialog

IMPLEMENT_DYNAMIC(CFCFS_RR, CDialogEx)

CFCFS_RR::CFCFS_RR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFCFS_RR::IDD, pParent)
{

}

CFCFS_RR::~CFCFS_RR()
{
}

void CFCFS_RR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFCFS_RR, CDialogEx)
	ON_BN_CLICKED(IDC_BT, &CFCFS_RR::OnBnClickedBt)
	ON_EN_SETFOCUS(IDC_EDIT1, &CFCFS_RR::OnEnSetfocusEdit1)
END_MESSAGE_MAP()


// CFCFS_RR message handlers


void CFCFS_RR::OnBnClickedBt()
{
	CString wndtxt;
	
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_EDIT1);
	wndtxtget->GetWindowTextW(wndtxt);
	
	TMP_BT=StrToIntW(wndtxt);
}





void CFCFS_RR::OnEnSetfocusEdit1()
{
	CString title;
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_STATIC1);
	title.Format(_T("Enter Burst Time of Process %d"),TMP_PRCn);
	wndtxtget->SetWindowTextW(title);
}
