// PRTY.cpp : implementation file
//

#include "stdafx.h"
#include "Project 1.h"
#include "PRTY.h"
#include "afxdialogex.h"


// CPRTY dialog

IMPLEMENT_DYNAMIC(CPRTY, CDialogEx)

CPRTY::CPRTY(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPRTY::IDD, pParent)
{

}

CPRTY::~CPRTY()
{
}

void CPRTY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPRTY, CDialogEx)
	ON_BN_CLICKED(IDC_PRTYBT, &CPRTY::OnBnClickedPrtybt)
	ON_EN_SETFOCUS(IDC_PRTYEDIT, &CPRTY::OnEnSetfocusPrtyedit)
END_MESSAGE_MAP()


// CPRTY message handlers


void CPRTY::OnBnClickedPrtybt()
{
	CString wndtxt;
	
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_PRTYEDIT);
	wndtxtget->GetWindowTextW(wndtxt);	
	TMP_BT=StrToIntW(wndtxt);
	wndtxtget=(CEdit*)GetDlgItem(IDC_PRTYEDIT2);
	wndtxtget->GetWindowTextW(wndtxt);	
	TMP_PRTY=StrToIntW(wndtxt);
}


void CPRTY::OnEnSetfocusPrtyedit()
{
	CString title;
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_PRTYTITLE);
	title.Format(_T("Enter Burst Time of Process %d"),TMP_PRCn);
	wndtxtget->SetWindowTextW(title);
	wndtxtget=(CEdit*)GetDlgItem(IDC_PRTYTITLE2);
	title.Format(_T("Enter Priority of Process %d"),TMP_PRCn);
	wndtxtget->SetWindowTextW(title);
}
