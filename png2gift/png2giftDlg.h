// png2giftDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include <atlimage.h>

// Cpng2giftDlg ��ȭ ����
class Cpng2giftDlg : public CDialog
{
// �����Դϴ�.
public:
	Cpng2giftDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PNG2GIFT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_inputPathCtrl;
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnDestroy();
public:
	afx_msg void OnBnClickedButtonPath();


	BOOL fileRead(CString strFile);
	char* fileReadEx(CString strFile);
	void writeFileEx(CString strPath, char* szData);
	void transePng2GiftEx(CString strOrginPath, CString strDestPath);
public:
	CEdit m_ctrlResultEd;
	CImage m_Image;
	BOOL m_bLoad;

	void fileBufPrint(char* szBuf, int nDataSize);

	char* uniToansi(const wchar_t* pwstrSrc);
	char* SuniToansi(CString Suni);
	wchar_t* ansiTouni(const char *szANSI);

	int toLittleEndian(char* sOffset);
	char* getSize(int nSize);
	void AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText);
public:
	CEdit m_ctrlOutputEd;
	CString m_strOrginPath;
	CString m_strDestPath;
public:
	afx_msg void OnBnClickedButtonOutputpath();
public:
	afx_msg void OnBnClickedButtonTranse();
};
