#pragma once
class CProcess
{
public:
	int AT;
	int BT;
	int QT;
	int PRTY;
	int AWT;
	int TAT;
	int nprc;
	int pno;
	int RnT;
	int LstStrt;
	CProcess(int AT=0,int BT=0,int QT=0,int PRTY=0,int AWT=0);
	~CProcess(void);
	
};

