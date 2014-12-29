#pragma once


// CFCFS_RR dialog
class CFCFS_RR : public CDialogEx
{
	DECLARE_DYNAMIC(CFCFS_RR)

public:
	CFCFS_RR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFCFS_RR();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBt();
	int TMP_PRCn;
	int TMP_BT;
	afx_msg void OnEnSetfocusEdit1();
};
