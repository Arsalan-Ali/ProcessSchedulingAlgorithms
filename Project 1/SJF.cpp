// SJF.cpp : implementation file
//

#include "stdafx.h"
#include "Project 1.h"
#include "SJF.h"
#include "afxdialogex.h"


// CSJF dialog

IMPLEMENT_DYNAMIC(CSJF, CDialogEx)

CSJF::CSJF(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSJF::IDD, pParent)
{

}

CSJF::~CSJF()
{
}

void CSJF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSJF, CDialogEx)
	ON_BN_CLICKED(IDC_SJFBT, &CSJF::OnBnClickedSjfbt)
	ON_EN_SETFOCUS(IDC_SJFEDIT, &CSJF::OnEnSetfocusSjfedit)
END_MESSAGE_MAP()


// CSJF message handlers


void CSJF::OnBnClickedSjfbt()
{
	CString wndtxt;
	
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_SJFEDIT);
	wndtxtget->GetWindowTextW(wndtxt);	
	TMP_BT=StrToIntW(wndtxt);
	wndtxtget=(CEdit*)GetDlgItem(IDC_SJFEDIT2);
	wndtxtget->GetWindowTextW(wndtxt);	
	TMP_AT=StrToIntW(wndtxt);

}


void CSJF::OnEnSetfocusSjfedit()
{
	CString title;
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_SJFTITLE);
	title.Format(_T("Enter Burst Time of Process %d"),TMP_PRCn);
	wndtxtget->SetWindowTextW(title);
	wndtxtget=(CEdit*)GetDlgItem(IDC_SJFTITLE2);
	title.Format(_T("Enter Arrival Time of Process %d"),TMP_PRCn);
	wndtxtget->SetWindowTextW(title);
}
