
// DKI(1).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDKI1App: 
// �йش����ʵ�֣������ DKI(1).cpp
//

class CDKI1App : public CWinApp
{
public:
	CDKI1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDKI1App theApp;