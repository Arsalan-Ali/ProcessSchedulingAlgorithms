#pragma once


// CQT dialog

class CQT : public CDialogEx
{
	DECLARE_DYNAMIC(CQT)

public:
	CQT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CQT();

// Dialog Data
	enum { IDD = IDD_QT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedQtbut();
	int TEMPQT;
};
