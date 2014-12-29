// QT.cpp : implementation file
//

#include "stdafx.h"
#include "Project 1.h"
#include "QT.h"
#include "afxdialogex.h"


// CQT dialog

IMPLEMENT_DYNAMIC(CQT, CDialogEx)

CQT::CQT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQT::IDD, pParent)
{

}

CQT::~CQT()
{
}

void CQT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQT, CDialogEx)
	ON_BN_CLICKED(IDC_QTBUT, &CQT::OnBnClickedQtbut)
END_MESSAGE_MAP()


// CQT message handlers


void CQT::OnBnClickedQtbut()
{
	CString wndtxt;
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_QTEDIT);
	wndtxtget->GetWindowTextW(wndtxt);
	TEMPQT=StrToIntW(wndtxt);
}
