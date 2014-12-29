#pragma once


// Cnprc dialog
class Cnprc : public CDialogEx
{
	DECLARE_DYNAMIC(Cnprc)

public:
	Cnprc(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cnprc();

// Dialog Data
	enum { IDD = IDHELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSetprc();
	int nprc;
};
