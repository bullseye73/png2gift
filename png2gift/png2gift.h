// png2gift.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Cpng2giftApp:
// �� Ŭ������ ������ ���ؼ��� png2gift.cpp�� �����Ͻʽÿ�.
//

class Cpng2giftApp : public CWinApp
{
public:
	Cpng2giftApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Cpng2giftApp theApp;