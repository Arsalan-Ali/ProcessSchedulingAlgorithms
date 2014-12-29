#pragma once


// CSJF dialog

class CSJF : public CDialogEx
{
	DECLARE_DYNAMIC(CSJF)

public:
	CSJF(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSJF();

// Dialog Data
	enum { IDD = IDD_SJF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSjfbt();
	int TMP_PRCn;
	int TMP_BT;
	int TMP_AT;
	afx_msg void OnEnSetfocusSjfedit();
};
