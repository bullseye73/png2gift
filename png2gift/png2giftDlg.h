// png2giftDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include <atlimage.h>

// Cpng2giftDlg 대화 상자
class Cpng2giftDlg : public CDialog
{
// 생성입니다.
public:
	Cpng2giftDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PNG2GIFT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
