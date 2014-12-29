
// Project 1View.h : interface of the CProject1View class
//

#pragma once


class CProject1View : public CView
{
protected: // create from serialization only
	CProject1View();
	DECLARE_DYNCREATE(CProject1View)

// Attributes
public:
	CProject1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CProject1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAlgorithmFcfs();
	afx_msg void OnAlgorithmPriority();
	afx_msg void OnAlgorithmRr();
	afx_msg void OnAlgorithmSjfnp();
	afx_msg void OnAlgorithmSjfp();
	afx_msg void OnUpdateAlgorithmFcfs(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAlgorithmPriority(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAlgorithmRr(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAlgorithmSjfnp(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAlgorithmSjfp(CCmdUI *pCmdUI);
	afx_msg void OnStart();
	afx_msg void OnSetvalues();
};

#ifndef _DEBUG  // debug version in Project 1View.cpp
inline CProject1Doc* CProject1View::GetDocument() const
   { return reinterpret_cast<CProject1Doc*>(m_pDocument); }
#endif

