// Cnprc.cpp : implementation file
//

#include "stdafx.h"
#include "Project 1.h"
#include "Cnprc.h"
#include "afxdialogex.h"


// Cnprc dialog

IMPLEMENT_DYNAMIC(Cnprc, CDialogEx)

Cnprc::Cnprc(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cnprc::IDD, pParent)
{

}

Cnprc::~Cnprc()
{
}

void Cnprc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cnprc, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cnprc::OnBnClickedSetprc)
END_MESSAGE_MAP()


// Cnprc message handlers


void Cnprc::OnBnClickedSetprc()
{
	CString wndtxt;
	CEdit* wndtxtget;
	wndtxtget=(CEdit*)GetDlgItem(IDC_EDIT);
	wndtxtget->GetWindowTextW(wndtxt);
	nprc=StrToIntW(wndtxt);
}
