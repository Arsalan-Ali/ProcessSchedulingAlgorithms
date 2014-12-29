#pragma once


// CPRTY dialog

class CPRTY : public CDialogEx
{
	DECLARE_DYNAMIC(CPRTY)

public:
	CPRTY(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPRTY();

// Dialog Data
	enum { IDD = IDD_PRTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPrtybt();
	int TMP_PRCn;
	int TMP_BT;
	int TMP_PRTY;
	afx_msg void OnEnSetfocusPrtyedit();
};
