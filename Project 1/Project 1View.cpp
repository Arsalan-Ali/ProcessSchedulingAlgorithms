
// Project 1View.cpp : implementation of the CProject1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Project 1.h"
#endif

#include "Project 1Doc.h"
#include "Project 1View.h"

#include "Cnprc.h"

#include "FCFS_RR.h"

#include "Process.h"

#include "QT.h"

#include "SJF.h"

#include "PRTY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum ALGO {FCFS,SJFP,SJFNP,PRIORITY,RR};
// CProject1View
static ALGO alg=FCFS;
static BOOL ifstart=FALSE;
static BOOL ifset=FALSE;
static CProcess* process;


IMPLEMENT_DYNCREATE(CProject1View, CView)

BEGIN_MESSAGE_MAP(CProject1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ALGORITHM_FCFS, &CProject1View::OnAlgorithmFcfs)
	ON_COMMAND(ID_ALGORITHM_PRIORITY, &CProject1View::OnAlgorithmPriority)
	ON_COMMAND(ID_ALGORITHM_RR, &CProject1View::OnAlgorithmRr)
	ON_COMMAND(ID_ALGORITHM_SJFNP, &CProject1View::OnAlgorithmSjfnp)
	ON_COMMAND(ID_ALGORITHM_SJFP, &CProject1View::OnAlgorithmSjfp)
	ON_UPDATE_COMMAND_UI(ID_ALGORITHM_FCFS, &CProject1View::OnUpdateAlgorithmFcfs)
	ON_UPDATE_COMMAND_UI(ID_ALGORITHM_PRIORITY, &CProject1View::OnUpdateAlgorithmPriority)
	ON_UPDATE_COMMAND_UI(ID_ALGORITHM_RR, &CProject1View::OnUpdateAlgorithmRr)
	ON_UPDATE_COMMAND_UI(ID_ALGORITHM_SJFNP, &CProject1View::OnUpdateAlgorithmSjfnp)
	ON_UPDATE_COMMAND_UI(ID_ALGORITHM_SJFP, &CProject1View::OnUpdateAlgorithmSjfp)
	ON_COMMAND(ID_START, &CProject1View::OnStart)
	ON_COMMAND(ID_SETVALUES, &CProject1View::OnSetvalues)
	
END_MESSAGE_MAP()

// CProject1View construction/destruction

CProject1View::CProject1View()
{
	// TODO: add construction code here

}

CProject1View::~CProject1View()
{
}

BOOL CProject1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProject1View drawing

void CProject1View::OnDraw(CDC* pDC)
{
	CProject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(ifstart)
	{
		switch(alg)
		{
			case FCFS:
				{
				CString disp;
				CRect rect;
				int WT=0;
				int TWT=0;
				float AWT=0;
				for (int i = 0; i < process->nprc ; i++)
				{
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+i*100,100,150+i*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(75+i*100,135,125+i*100,175);
					disp.Format(_T("P%d"),i+1);
					pDC->DrawText(disp,rect,DT_CENTER);
					rect.SetRect(50+i*100,75,150+i*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+(process + i)->BT);
					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					WT=WT+(process + i)->BT;
					if(i< (process->nprc-1))
						TWT=TWT+WT;
					
				}
				AWT=((float)TWT)/((float)process->nprc);
					rect.SetRect(50,250,600,280);
					disp.Format(_T("So Average Waiting Time = %f"),AWT);
					pDC->DrawText(disp,rect,DT_LEFT);
				}


				break;

			case SJFNP:
				{
				CString disp;
				CRect rect;
				int WT=0;
				int TWT=0;
				float AWT=0;
				int tempAT=-1;
				int indx=0;
				int j=0;
				int flag=0;
				while( 1 )
				{
				int flag=0;
				for (int i = 0; i < process->nprc; i++)
				{
					if ((process+i)->BT > 0)
					{
						tempAT=(process+i)->AT;
						break;

					}

				}
				for (int i = 0; i < process->nprc; i++)
				{
					if ((process+i)->BT > 0)
						if (tempAT>(process+i)->AT)
					{
						tempAT=(process+i)->AT;
						

					}

				}
				if (tempAT<=0)
				{
					for (int i = 0; i < process->nprc; i++)
					{
						if((process+i)->AT<=0)
							if((process+i)->BT > 0)
							{
								indx=i;
								break;
							}

					}
					for (int i = 0; i < process->nprc; i++)
					{
						if((process+i)->AT<=0)
							if((process+i)->BT > 0)
								if((process+indx)->BT>(process+i)->BT)
							{
								indx=i;
								
							}

					}
					for (int i = 0; i < process->nprc; i++)
					{
						(process+i)->AT=(process+i)->AT-(process+ indx )->BT;
							

					}
					

					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+j*100,100,150+j*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(75+j*100,135,125+j*100,175);
					disp.Format(_T("P%d"),indx+1);
					pDC->DrawText(disp,rect,DT_CENTER);
					rect.SetRect(50+j*100,75,150+j*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+(process + indx)->BT);
					(process+indx)->LstStrt=WT;

                    WT=WT+(process+ indx )->BT;
					
					(process+ indx )->BT= 0;

					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					tempAT=-1;
					j=j+1;
				}
				else
				{
					for (int i = 0; i < process->nprc; i++)
					{
						(process+i)->AT=(process+i)->AT-tempAT;
							

					}
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+j*100,100,150+j*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(50+j*100,75,150+j*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+tempAT);

                    WT=WT+tempAT;

					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					j=j+1;


				}

				for (int i = 0; i < process->nprc; i++)
				{
					if((process + i)->BT<=0)
					{
							
						flag=flag+1;
					
					}
				}
				if(flag == process->nprc)
					break;
				}
				for (int i = 0; i < process->nprc; i++)
				{
					TWT=TWT-(process+i)->TAT+(process+i)->LstStrt;

				}
				    AWT=((float)TWT)/((float)process->nprc);
					rect.SetRect(50,250,600,280);
					disp.Format(_T("So Average Waiting Time = %f"),AWT);
					pDC->DrawText(disp,rect,DT_LEFT);
				}
				break;

			case SJFP:
{
				CString disp;
				CRect rect;
				int WT=0;
				int TWT=0;
				float AWT=0;
				int tempAT=-1;
				int indx=0;
				int j=0;
				int flag=0;
				int mxAT=process->AT;
				int temp2=0;
				int flg=1;
				for(int i=0 ;i < process->nprc; i++)
				{
					(process+i)->LstStrt=0;
					(process+i)->RnT=0;
				}
				for (int i = 0; i < process->nprc; i++)
				{
					if (mxAT<(process+i)->AT)
					{
						mxAT=(process+i)->AT;
					}

				}
				while( 1 )
				{
				int flag=0;
				for (int i = 0; i < process->nprc; i++)
				{
					if ((process+i)->BT > 0)
					{
						tempAT=(process+i)->AT;
						break;

					}

				}
				for (int i = 0; i < process->nprc; i++)
				{
					if ((process+i)->BT > 0)
						if (tempAT>(process+i)->AT)
					{
						tempAT=(process+i)->AT;
						

					}

				}
				if (tempAT<=0)
				{
					for (int i = 0; i < process->nprc; i++)
					{
						if((process+i)->AT<=0)
							if((process+i)->BT > 0)
							{
								indx=i;
								break;
							}

					}
					for (int i = 0; i < process->nprc; i++)
					{
						if((process+i)->AT<=0)
							if((process+i)->BT > 0)
								if((process+indx)->BT>(process+i)->BT)
							{
								indx=i;
								
							}

					}
					for (int i = 1; i <= mxAT; i++)
					{
						for(int k=0 ; k<process->nprc ;k++)
						{
							if((process+k)->AT == i)
								if ((process+k)->BT<(process+indx)->BT-i)
								{
									temp2=(process+k)->AT;
						
								}
						}
						for(int k=0 ; k<process->nprc ;k++)
						{
							if((process+k)->AT == i)
								if ((process+k)->BT<(process+indx)->BT-i)
								if (temp2<(process+k)->BT)
								{
									temp2=(process+k)->AT;
									flg=0;
						
								}
						}
						if (flg==0)
						{
							flg=1;
							break;
						}

					}
					if(temp2 == 0)
					{
					for (int i = 0; i < process->nprc; i++)
					{
						(process+i)->AT=(process+i)->AT-(process+ indx )->BT;
							

					}
					

					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+j*100,100,150+j*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(75+j*100,135,125+j*100,175);
					disp.Format(_T("P%d"),indx+1);
					pDC->DrawText(disp,rect,DT_CENTER);
					rect.SetRect(50+j*100,75,150+j*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+(process + indx)->BT);
					(process+indx)->LstStrt=WT;

                    WT=WT+(process+ indx )->BT;
					
					(process+ indx )->BT= 0;

					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					tempAT=-1;
					j=j+1;
					}
					else
					{
						for (int i = 0; i < process->nprc; i++)
					    {
						(process+i)->AT=(process+i)->AT-temp2;
							

					    }
					
                    (process+indx)->BT=(process+indx)->BT-temp2;
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+j*100,100,150+j*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(75+j*100,135,125+j*100,175);
					disp.Format(_T("P%d"),indx+1);
					pDC->DrawText(disp,rect,DT_CENTER);
					rect.SetRect(50+j*100,75,150+j*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+temp2);
					
					(process+indx)->RnT=(process+indx)->RnT+temp2;

                    WT=WT+temp2;
					
					

					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					tempAT=-1;
					j=j+1;

					temp2=0;

					}
				}
				else
				{
					for (int i = 0; i < process->nprc; i++)
					{
						(process+i)->AT=(process+i)->AT-tempAT;
							

					}
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+j*100,100,150+j*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(50+j*100,75,150+j*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+tempAT);

                    WT=WT+tempAT;

					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					j=j+1;


				}

				for (int i = 0; i < process->nprc; i++)
				{
					if((process + i)->BT<=0)
					{
							
						flag=flag+1;
					
					}
				}
				if(flag == process->nprc)
					break;
				}
				for (int i = 0; i < process->nprc; i++)
				{
					TWT=TWT-(process+i)->TAT+(process+i)->LstStrt-(process+i)->RnT;

				}
				    AWT=((float)TWT)/((float)process->nprc);
					rect.SetRect(50,250,600,280);
					disp.Format(_T("So Average Waiting Time = %f"),AWT);
					pDC->DrawText(disp,rect,DT_LEFT);
				}
				break;

				break;

			case PRIORITY:
            {
				CString disp;
				CRect rect;
				int WT=0;
				int TWT=0;
				float AWT=0;
				int temp=0;
				for(int i = 0; i < process->nprc ; i++)
				{
					(process+i)->pno=i;
				}
				for (int j = 0; j < process->nprc-1 ; j++)
				{
					for (int k = 1+j; k < process->nprc; k++)
					{
						if((process+j)->PRTY > (process+k)->PRTY)
						{
							temp=(process+j)->BT;
							(process+j)->BT=(process+k)->BT;
							(process+k)->BT=temp;
							temp=(process+j)->PRTY;
							(process+j)->PRTY=(process+k)->PRTY;
							(process+k)->PRTY=temp;
							temp=(process+j)->pno;
							(process+j)->pno=(process+k)->pno;
							(process+k)->pno=temp;
						
						}
					}
				}

				for (int i = 0; i < process->nprc ; i++)
				{
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					rect.SetRect(50+i*100,100,150+i*100,200);
					pDC->SetBkColor(RGB(2,255,2));
					pDC->Rectangle(rect);
					rect.SetRect(75+i*100,135,125+i*100,175);
					disp.Format(_T("P%d"),(process + i)->pno + 1);
					pDC->DrawText(disp,rect,DT_CENTER);
					rect.SetRect(50+i*100,75,150+i*100,95);
					disp.Format(_T("%d ------ %d"),WT,WT+(process + i)->BT);
					pDC->SetBkColor(RGB(255,255,255));
					pDC->DrawText(disp,rect,DT_CENTER);
					WT=WT+(process + i)->BT;
					if(i< (process->nprc-1))
						TWT=TWT+WT;
					
				}
				AWT=((float)TWT)/((float)process->nprc);
					rect.SetRect(50,250,600,280);
					disp.Format(_T("So Average Waiting Time = %f"),AWT);
					pDC->DrawText(disp,rect,DT_LEFT);
				}

				break;

			case RR:

				{
				CString disp;
				CRect rect;
				int WT=0;
				int TWT=0;
				float AWT=0;
				for(int i=0 ;i < process->nprc; i++)
				{
					(process+i)->LstStrt=0;
					(process+i)->RnT=0;
				}

				int i=0;
				int k=0;
				int flag=0;

				while (flag < process->nprc)
				{
					flag=0;
					CBrush brush(RGB(2,255,2));
					CBrush* Poldbrush= pDC->SelectObject(&brush);
					pDC->SetBkColor(RGB(255,255,255));
					(process + i)->BT=(process + i)->BT - process->QT;
					if((process + i)->BT <= 0)
					{
						if((process + i)->BT<=-process->QT)
						{
							i++;
							continue;
						}
						else
						{
							(process+i)->LstStrt=WT;
						    disp.Format(_T("%d ------ %d"),WT,WT+ (process + i)->BT + process->QT);
						}
						
					}
					else
					{
						(process+i)->RnT=(process+i)->RnT+process->QT;
					    disp.Format(_T("%d ------ %d"),WT,WT+process->QT);
					}
					
					rect.SetRect(50+k*100,75,150+k*100,95);
					
					pDC->DrawText(disp,rect,DT_CENTER);

					rect.SetRect(50+k*100,100,150+k*100,200);
					pDC->Rectangle(rect);
					

					pDC->SetBkColor(RGB(2,255,2));
					disp.Format(_T("P%d"),i+1);
					rect.SetRect(75+k*100,135,125+k*100,175);
					pDC->DrawText(disp,rect,DT_CENTER);
					
					

					
					if((process + i)->BT<=0)
					{
						WT=WT+(process+i)->BT + process->QT;
					}
					else
					    WT=WT + process->QT;

					if (i < process->nprc - 1)
					{
					   k++;
                       i++;
					}
					else
					{
						k++;
						i=0;
					}

					for (int j = 0; j < process->nprc; j++)
					{
						if((process + j)->BT<=0)
						{
							
							flag=flag+1;
							
						}


					}
					
				}
				for(int i=0 ;i < process->nprc; i++)
				{
					TWT=TWT+((process+i)->LstStrt-(process+i)->RnT);
					
				}
				pDC->SetBkColor(RGB(255,255,255));
				AWT=((float)TWT)/((float)process->nprc);
				rect.SetRect(50,250,600,280);
				disp.Format(_T("So Average Waiting Time = %f"),AWT);
				pDC->DrawText(disp,rect,DT_LEFT);
				}

				break;

			default:
				return;
		}
	}
}


// CProject1View printing

BOOL CProject1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProject1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProject1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CProject1View diagnostics

#ifdef _DEBUG
void CProject1View::AssertValid() const
{
	CView::AssertValid();
}

void CProject1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProject1Doc* CProject1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject1Doc)));
	return (CProject1Doc*)m_pDocument;
}
#endif //_DEBUG


// CProject1View message handlers


void CProject1View::OnAlgorithmFcfs()

{
	alg=FCFS;
}


void CProject1View::OnAlgorithmPriority()
{
	alg=PRIORITY;
}


void CProject1View::OnAlgorithmRr()
{
	alg=RR;
}


void CProject1View::OnAlgorithmSjfnp()
{
	alg=SJFNP;
}


void CProject1View::OnAlgorithmSjfp()
{
	alg=SJFP;
}


void CProject1View::OnUpdateAlgorithmFcfs(CCmdUI *pCmdUI)
{
	if(alg==FCFS)
		pCmdUI->SetCheck(TRUE);
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}


void CProject1View::OnUpdateAlgorithmPriority(CCmdUI *pCmdUI)
{
	if(alg==PRIORITY)
		pCmdUI->SetCheck(TRUE);
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}


void CProject1View::OnUpdateAlgorithmRr(CCmdUI *pCmdUI)
{
	if(alg==RR)
		pCmdUI->SetCheck(TRUE);
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}


void CProject1View::OnUpdateAlgorithmSjfnp(CCmdUI *pCmdUI)
{
	if(alg==SJFNP)
		pCmdUI->SetCheck(TRUE);
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}


void CProject1View::OnUpdateAlgorithmSjfp(CCmdUI *pCmdUI)
{
	if(alg==SJFP)
		pCmdUI->SetCheck(TRUE);
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}


void CProject1View::OnStart()
{
	if(ifset)
	{
	  ifstart=TRUE;
	  InvalidateRect(nullptr);
	  UpdateWindow();
	}
}


void CProject1View::OnSetvalues()
{
	static Cnprc nprcdlg;
	nprcdlg.DoModal();
	
	switch(alg)
		{
		 case FCFS:
		 {
		 process=new CProcess[nprcdlg.nprc];
		 process->nprc=nprcdlg.nprc;
	     for (int i = 0; i < nprcdlg.nprc; i++)
		  {
			static CFCFS_RR* dlg=new CFCFS_RR;
			dlg->TMP_PRCn=i+1;
			dlg->DoModal();
			(process+i)->BT=dlg->TMP_BT;
		  }	
		 ifset=TRUE;
		 
		 }
		 break;

			case SJFNP:
			{
		 process=new CProcess[nprcdlg.nprc];
		 process->nprc=nprcdlg.nprc;
	     for (int i = 0; i < nprcdlg.nprc; i++)
		  {
			static CSJF* dlg=new CSJF;
			dlg->TMP_PRCn=i+1;
			dlg->DoModal();
			(process+i)->BT=dlg->TMP_BT;
			(process+i)->AT=dlg->TMP_AT;
			(process+i)->TAT=dlg->TMP_AT;
		  }	
		 ifset=TRUE;
		 
		 }


				break;

			case SJFP:
				{
		 process=new CProcess[nprcdlg.nprc];
		 process->nprc=nprcdlg.nprc;
	     for (int i = 0; i < nprcdlg.nprc; i++)
		  {
			static CSJF* dlg=new CSJF;
			dlg->TMP_PRCn=i+1;
			dlg->DoModal();
			(process+i)->BT=dlg->TMP_BT;
			(process+i)->AT=dlg->TMP_AT;
			(process+i)->TAT=dlg->TMP_AT;
		  }	
		 ifset=TRUE;
		 
		 }


				break;

			case PRIORITY:
				{
		 process=new CProcess[nprcdlg.nprc];
		 process->nprc=nprcdlg.nprc;
	     for (int i = 0; i < nprcdlg.nprc; i++)
		  {
			  static CPRTY* dlg=new CPRTY;
			dlg->TMP_PRCn=i+1;
			dlg->DoModal();
			(process+i)->BT=dlg->TMP_BT;
			(process+i)->PRTY=dlg->TMP_PRTY;
		  }	
		 ifset=TRUE;
		 
		 }


				break;

			case RR:
         {
		 static CQT* QTDLG = new CQT;
		 QTDLG->DoModal();
		 process=new CProcess[nprcdlg.nprc];
		 process->QT=QTDLG->TEMPQT;
		 process->nprc=nprcdlg.nprc;
	     for (int i = 0; i < nprcdlg.nprc; i++)
		  {
			static CFCFS_RR* dlg=new CFCFS_RR;
			dlg->TMP_PRCn=i+1;
			dlg->DoModal();
			(process+i)->BT=dlg->TMP_BT;
		  }	
		 ifset=TRUE;
		 
		 }


				break;

			default:
				;
				
		}
	


	
}





