// png2giftDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "png2gift.h"
#include "png2giftDlg.h"

#define PROCESSBY_ONE	0

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpng2giftDlg ��ȭ ����


Cpng2giftDlg::Cpng2giftDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cpng2giftDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bLoad = FALSE;
}

void Cpng2giftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_inputPathCtrl);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_ctrlResultEd);
	DDX_Control(pDX, IDC_EDIT_OUTPUT, m_ctrlOutputEd);
}

BEGIN_MESSAGE_MAP(Cpng2giftDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cpng2giftDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cpng2giftDlg::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_PATH, &Cpng2giftDlg::OnBnClickedButtonPath)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUTPATH, &Cpng2giftDlg::OnBnClickedButtonOutputpath)
	ON_BN_CLICKED(IDC_BUTTON_TRANSE, &Cpng2giftDlg::OnBnClickedButtonTranse)
END_MESSAGE_MAP()


// Cpng2giftDlg �޽��� ó����

BOOL Cpng2giftDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cpng2giftDlg::OnPaint()
{
	CPaintDC dc(this);

	if (IsIconic())
	{
		//CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
	if(m_bLoad){
		m_Image.TransparentBlt( dc.m_hDC, 0, 0, m_Image.GetWidth(), m_Image.GetHeight(), RGB(255, 0, 0) );
		m_Image.BitBlt( dc.m_hDC, 300, 0 );
	}

}



// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Cpng2giftDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cpng2giftDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

void Cpng2giftDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnCancel();
}

void Cpng2giftDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void Cpng2giftDlg::OnBnClickedButtonPath()
{
#if PROCESSBY_ONE
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	wchar_t szFilter[] = L"File (*.PNG) | *.png; | All Files(*.*)|*.*||";
	CFileDialog* cfd = new CFileDialog(true, NULL, NULL, OFN_HIDEREADONLY, (LPCTSTR)(LPSTR)szFilter, NULL, 0);
	if(cfd->DoModal() == IDOK){
		//CString strFile = cfd->GetFileName();
		CString strPath = cfd->GetPathName();
		m_strDestPath.Format(L"%s.gift", strPath.Mid(0, strPath.Find(L".", 0)));

		m_inputPathCtrl.SetWindowText(strPath);
		m_ctrlOutputEd.SetWindowText(m_strDestPath);

		//m_bLoad = fileRead(strPath);
		m_bLoad = fileReadEx(strPath);
	}
#else
	ITEMIDLIST        *pidlBrowse;
	WCHAR    pszPathname[MAX_PATH] = {0,};
	BROWSEINFO BrInfo;
	BrInfo.hwndOwner = NULL; //GetSafeHwnd();
	BrInfo.pidlRoot = NULL;
	memset( &BrInfo, 0, sizeof(BrInfo) );
	BrInfo.pszDisplayName = pszPathname;
	BrInfo.lpszTitle = L"�����̹��� ���丮�� �����ϼ���";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;


	// ���̾�α׸� ����
	pidlBrowse = ::SHBrowseForFolder(&BrInfo);   


	if( pidlBrowse != NULL)
	{
	 // �н��� ����
		::SHGetPathFromIDList(pidlBrowse, pszPathname);

		m_inputPathCtrl.SetWindowText(pszPathname);
		m_ctrlOutputEd.SetWindowText(pszPathname);
		AppendTextToEditCtrl(m_ctrlResultEd, (LPCTSTR)(LPWSTR)pszPathname);
		
	}

	
	//CFileDialog od(TRUE/*bOpenFileDialog*/, NULL, NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , NULL, NULL, 0, TRUE/*bVistaStyle*/);
	/*
	wchar_t szFilter[] = L"File (*.PNG) | *.png; | All Files(*.*)|*.*||";
	CFileDialog* cfd = new CFileDialog(true, NULL, NULL, OFN_ALLOWMULTISELECT | OFN_EXPLORER, (LPCTSTR)(LPSTR)szFilter, NULL, 0);
	

	if(cfd->DoModal() == IDOK){
		POSITION pos = cfd->GetStartPosition();
		CString strPathName;

		CString strPath ;
		CString strExt;
		CString strFileName;
		CString strBuf;
		
		m_inputPathCtrl.SetWindowText(strPath);

		while(pos)
		{
			strPathName =  cfd->GetNextPathName(pos); // strPathName�� ������ �׸��� ��ΰ� ����
			strPath = cfd->GetFolderPath();

			strExt = strPathName.Right(strPathName.GetLength() - (strPathName.Find(L".", 0)+1));
			
			strBuf.Format(L"%s Start!",strPathName);
			AppendTextToEditCtrl(m_ctrlResultEd,strBuf);

			if(strExt.MakeUpper().Compare(L"PNG") == 0){
				m_strDestPath.Format(L"%s.gift", strPath.Mid(0, strPath.Find(L".", 0)));
				m_bLoad = fileReadEx(strPathName);
			}
			else{
				AppendTextToEditCtrl(m_ctrlResultEd, L"is Not PNG file!");
			}

			
		}
		*/
		/*
		//CString strFile = cfd->GetFileName();
		CString strPath = cfd->GetPathName();
		m_strDestPath.Format(L"%s.gift", strPath.Mid(0, strPath.Find(L".", 0)));

		m_inputPathCtrl.SetWindowText(strPath);
		m_ctrlOutputEd.SetWindowText(m_strDestPath);

		//m_bLoad = fileRead(strPath);
		m_bLoad = fileReadEx(strPath);
		
	}
	*/
#endif
}

void Cpng2giftDlg::transePng2GiftEx(CString strOrginPath, CString strDestPath)
{
	CFileFind finder;
	CString strFindPath;
	CString strReadFile;
	CString strDestFile;
	CString strBuffer;


	strFindPath.Format(L"%s\\*.png", strOrginPath);
	BOOL bWorking = finder.FindFile(strFindPath);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		AppendTextToEditCtrl(m_ctrlResultEd, finder.GetFileName());
		strDestFile.Format(L"%s.gift", finder.GetFileName().Mid(0, finder.GetFileName().Find(L".", 0)));
		
		strReadFile.Format(L"%s\\%s", strOrginPath, finder.GetFileName());
		m_strDestPath.Format(L"%s\\%s", strDestPath, strDestFile);

		strBuffer.Format(L"%s >>>>> write start!", m_strDestPath);
		AppendTextToEditCtrl(m_ctrlResultEd, strBuffer);

		writeFileEx(m_strDestPath, fileReadEx(strReadFile));

		strBuffer.Format(L"%s <<<<< write end!", m_strDestPath);
		AppendTextToEditCtrl(m_ctrlResultEd, strBuffer);
	}
}

void Cpng2giftDlg::OnBnClickedButtonOutputpath()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
#if PROCESSBY_ONE
	//wchar_t szFilter[] = L"File (*.PNG) | *.png; | All Files(*.*)|*.*||";
	CFileDialog* cfd = new CFileDialog(true, NULL, NULL, OFN_HIDEREADONLY, NULL, NULL, 0);
	if(cfd->DoModal() == IDOK){
		CString strFile = cfd->GetFileName();
		m_strDestPath = cfd->GetFolderPath();
		m_ctrlOutputEd.SetWindowText(m_strDestPath);
	}
#else
	ITEMIDLIST        *pidlBrowse;
	WCHAR    pszPathname[MAX_PATH] = {0,};
	BROWSEINFO BrInfo;
	BrInfo.hwndOwner = NULL; //GetSafeHwnd();
	BrInfo.pidlRoot = NULL;
	memset( &BrInfo, 0, sizeof(BrInfo) );
	BrInfo.pszDisplayName = pszPathname;
	BrInfo.lpszTitle = L"�����̹��� ���丮�� �����ϼ���";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;


	// ���̾�α׸� ����
	pidlBrowse = ::SHBrowseForFolder(&BrInfo);   


	if( pidlBrowse != NULL)
	{
	 // �н��� ����
		::SHGetPathFromIDList(pidlBrowse, pszPathname);
		
		m_ctrlOutputEd.SetWindowText(pszPathname);

	}
#endif
}



void Cpng2giftDlg::OnBnClickedButtonTranse()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
#if PROCESSBY_ONE

#else
	CString strDestPath;
	CString strOrginPath;

	m_inputPathCtrl.GetWindowTextW(strOrginPath);
	m_ctrlOutputEd.GetWindowTextW(strDestPath);
	transePng2GiftEx(strOrginPath , strDestPath );
#endif
}


BOOL Cpng2giftDlg::fileRead(CString strFile)
{
	CFile cfile;
	char *spRead = NULL;

	if(!cfile.Open(strFile, CFile::modeRead)){
    // �̹����� �ҷ� ���µ� ���� ���� ���.
        CString strtmp = _T("ERROR : Failed to load");
        strtmp += strFile + _T("\n");
        TRACE(strtmp);
        return FALSE;
    }
	UINT nFileSize = cfile.GetLength();
	spRead = new char[nFileSize*sizeof(char)];
	memset(spRead, 0x00, sizeof(spRead));
	
	cfile.Read (spRead, nFileSize);

	fileBufPrint(spRead, nFileSize);

	//
	
	if(spRead != NULL){
		delete spRead;
		spRead = NULL;
	}

	cfile.Close();
	return TRUE;
}

char* Cpng2giftDlg::fileReadEx(CString strFile)
{
	//fopen
	FILE* pFile;
	int c, n = 0;
	int len = 0, iSize;
	char* szPrintBuf;
	char szBuffer[9] = {0,};
	//char szHex[4*sizeof(char)*5 + 8*sizeof(char)*5] = {0,};


	pFile=fopen(SuniToansi(strFile),"rb");
	if (pFile==NULL) { 
		AppendTextToEditCtrl(m_ctrlResultEd, L"File Read error"); 
		return NULL;
	}

	// file pointer move to end
    fseek(pFile, 0L, SEEK_END);
	len = ftell(pFile);
	rewind (pFile);

	//	
	iSize = len*sizeof(char)*5 + 8*sizeof(char)*5;
	szPrintBuf= new char[iSize];
	memset(szPrintBuf, 0, iSize);

	do {
		if(n == 0){
			strcat(szPrintBuf, getSize(len));
		}

		n++;
		c = fgetc (pFile);
		if (c == EOF){		break;		}

		sprintf(szBuffer, "0x%02x,", c);

		strcat(szPrintBuf, szBuffer);
		
	} while (1);

	szPrintBuf[iSize] = 0x00;
	fclose (pFile);
	

	return szPrintBuf;
}

void Cpng2giftDlg::writeFileEx(CString strPath, char* szData){
	FILE* pFile;

	pFile = fopen (SuniToansi(strPath) , "wb" );
	if (pFile==NULL) { 
		AppendTextToEditCtrl(m_ctrlResultEd, L"File Write error"); 
		return;
	}

	fwrite (szData , 1 , strlen(szData) , pFile );
	fclose (pFile);
}

void Cpng2giftDlg::fileBufPrint(char* szBuf, int nDataSize){

	//m_ctrlResultEd.SetWindowText(ansiTouni(szBuf));
	UINT nSize = nDataSize+1 ;
	char* szPrintBuf;
	char szBuffer[1] = {0,};
	CString strPrint;

	szPrintBuf= new char[nSize];
	memset(szPrintBuf, 0, sizeof(szPrintBuf));

	for(int i=0 ; i< nSize; i++){
		memset(szBuffer, 0x00, sizeof(szBuffer));

		sprintf(szBuffer, "0x%02x", szBuf[i]);
		if (i%8 == 0){
			strcat(szPrintBuf, "\n");
		}
		strcat(szPrintBuf, szBuffer);
		TRACE(szPrintBuf);
	}
	szPrintBuf[nSize] = NULL;

	CString strBuf;
	strBuf.Format(_T("%s"), szPrintBuf);
	m_ctrlResultEd.SetWindowText(strBuf);

	if(szPrintBuf != NULL){
		delete szPrintBuf;
		szPrintBuf = NULL;
	}
}

int Cpng2giftDlg::toLittleEndian(char* sOffset)
{
	unsigned int nOffset = (unsigned int) * sOffset;
	nOffset =	(nOffset >> 24) |					// Move first byte to the end,
				((nOffset << 8) & 0x00FF0000) |	// move 2nd byte to 3rd,
				((nOffset >> 8) & 0x0000FF00) |	// move 3rd byte to 2nd,
				(nOffset << 24);

	return nOffset;
}

char* Cpng2giftDlg::getSize(int nSize)
{
	char szSizeBuf[9]={0,};
	char buffer[8*sizeof(char)*5]={0,};
	char szBuf[6] = {0,};
	int nlen = 0;
	
	sprintf(szSizeBuf, "%08x", nSize);
	
	nlen = strlen(szSizeBuf);

	for(int i = 0 ; i < nlen ; i+=2){
		sprintf(szBuf, "0x%c%c,", szSizeBuf[(nlen-1) - (i+1)], szSizeBuf[(nlen-1) - i]);
		strcat(buffer, szBuf);
	}

	//itoa(nSize, buffer, 16);
	

	//sprintf(szSizeBuf, "%s", buffer);
	//sprintf(szSizeBuf, "%08x", toLittleEndian(itoa(nSize, buffer, 16)));

	return buffer;
}

void Cpng2giftDlg::AppendTextToEditCtrl(CEdit& edit, LPCTSTR pszText)
{
   // get the initial text length
	CString strPrint;
	strPrint.Format(L"%s\r\n", pszText);
   int nLength = edit.GetWindowTextLength();
   edit.SetSel(nLength, nLength);
   edit.ReplaceSel(strPrint);
}

//---------------------------------------------------------------------------
wchar_t* Cpng2giftDlg::ansiTouni(const char *szANSI)
{
	wchar_t					*szwUNI = NULL;
	ULONG					cChar;

	if(NULL == szANSI)
	{
		szwUNI = NULL;

		return NULL;
	}

	cChar =  (ULONG)strlen(szANSI) + 1;

	szwUNI = new wchar_t[cChar * 2];

	if(NULL == szwUNI)
		return NULL;

	if(0 == MultiByteToWideChar(CP_ACP, 0, szANSI, cChar, szwUNI, cChar))
	{
		delete []szwUNI;
		szwUNI = NULL;

		return NULL;
	}

	return szwUNI;
}
//---------------------------------------------------------------------------
char *Cpng2giftDlg::SuniToansi(CString Suni)
{
	char					*szData = NULL;
	int						len = 0;

	if(Suni.GetLength() == 0)
		Suni.Format(_T(" "));

	len = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, Suni, Suni.GetLength(), szData, 0, NULL, NULL);

	if(len == 0)
		return NULL;

	szData = new char[len + 1];

	memset(szData, 0x00, len + 1);

	if(NULL == szData)
		return NULL;

	if(0 == WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, Suni, Suni.GetLength(), szData, len + 1, NULL, NULL))
	{
		delete []szData;
		szData = NULL;

		return NULL;
	}

	return szData;
}
//---------------------------------------------------------------------------
char *Cpng2giftDlg::uniToansi(const wchar_t* pwstrSrc)
{
	//    ASSERT(pwstrSrc);

	if(NULL == pwstrSrc)
		AfxMessageBox(_T("CSchDateDlg : uniToansi error! => �˼��մϴ� �ٿ��̵�� �����ڿ��� ���� �޼����� �˷� �ּ���!"));

	int						len = 0;

	len = ((int)wcslen(pwstrSrc) + 1) * 2;

	char					*pstr = (char *)malloc(sizeof(char) * len);

	WideCharToMultiByte(CP_ACP, 0, pwstrSrc, -1, pstr, len, NULL, NULL);

	return pstr;
}
/*
void CBullsCarDlg::SetTransparent(int percent)
{
	SLWA pSetLayeredWindowAttributes = NULL;

	HINSTANCE hmodUSER32 = LoadLibrary(L"USER32.DLL");
	pSetLayeredWindowAttributes =
		(SLWA)GetProcAddress(hmodUSER32,"SetLayeredWindowAttributes");

	HWND hwnd = this->m_hWnd;
	SetWindowLong(hwnd,GWL_EXSTYLE,GetWindowLong(hwnd,GWL_EXSTYLE) | WS_EX_LAYERED);
	pSetLayeredWindowAttributes(hwnd, 0, percent, LWA_ALPHA);
}
*/


