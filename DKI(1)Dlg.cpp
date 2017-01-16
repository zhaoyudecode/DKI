
// DKI(1)Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DKI(1).h"
#include "DKI(1)Dlg.h"
#include "G_DIALOGI.h"
#include "afxdialogex.h"
#include "resource.h"
#include <vector>
#include <map>
//#include<cmath>
#include <math.h>
#include"nr.h"
#include<string.h>
#include<stdlib.h>
#define PI 3.141592653589793238
#include "DKIAG.h"
double *C = NULL;
double *temp_2D = NULL;
#define N 256

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDKI1Dlg 对话框



CDKI1Dlg::CDKI1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDKI1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDKI1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDKI1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENFILE, &CDKI1Dlg::OnBnClickedOpenfile)
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_SELECT, &CDKI1Dlg::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_GRAPH, &CDKI1Dlg::OnBnClickedGraph)
	ON_BN_CLICKED(IDC_REDO, &CDKI1Dlg::OnBnClickedRedo)
	ON_WM_MBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_OPENFILE2, &CDKI1Dlg::OnBnClickedOpenfile2)
	ON_BN_CLICKED(IDC_SELECT2, &CDKI1Dlg::OnBnClickedSelect2)
END_MESSAGE_MAP()


// CDKI1Dlg 消息处理程序

BOOL CDKI1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	CButton *pButton1 = (CButton*)GetDlgItem(IDC_SELECT);
	pButton1->ShowWindow(SW_HIDE);
	CButton *pButton2 = (CButton*)GetDlgItem(IDC_GRAPH);
	pButton2->ShowWindow(SW_HIDE);
	CButton *pButton3 = (CButton*)GetDlgItem(IDC_REDO);
	pButton3->ShowWindow(SW_HIDE);


	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDKI1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDKI1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDKI1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDKI1Dlg::OnBnClickedOpenfile()
{
	
	MessageBox(_T("请加载相关的17个diocm图像文件！"));
	CFileDialog CFDlgRead(TRUE, NULL, NULL, OFN_READONLY | OFN_ALLOWMULTISELECT, _T("医学影像格式(*.dcm)|*.dcm|所有文件|*.*|"), NULL);
	TCHAR *pBuffer = new TCHAR[MAX_PATH * 100];
	int a = 0;


	/*CButton *pButton1 = (CButton*)GetDlgItem(IDC_SELECT);
	pButton1->ShowWindow(SW_SHOW);*/

	CFDlgRead.m_ofn.lpstrTitle = _T("请加载相关17个图像文件");
	CFDlgRead.m_ofn.lpstrFile = pBuffer;
	CFDlgRead.m_ofn.nMaxFile = MAX_PATH * 100;
	CFDlgRead.m_ofn.Flags |= OFN_ALLOWMULTISELECT;
	CFDlgRead.m_ofn.lpstrFile[0] = '\0';
	if (IDCANCEL == CFDlgRead.DoModal())
		return;


	POSITION Pos;
	Pos = CFDlgRead.GetStartPosition();                                        //创建位置类成员，它指向CFDlg数据流的初始位置 
	while (Pos != NULL)
	{
		CString filename = CFDlgRead.GetNextPathName(Pos);                     //当Pos不为空（最后）的时候，Pos原先在CFDlg数据流的开头，利用GetNextPathName函数，依次返回每个文件的完整路径
		vecszPath.push_back(filename);
	}
	int temp_pathsize = vecszPath.size();


	/*CString str;
	str.Format(_T("%d"), temp_pathsize);
	LPCTSTR pStr = LPCTSTR(str);
	AfxMessageBox(pStr);*/


	if (17!= temp_pathsize)
	{
		AfxMessageBox(_T("您加载的图像文件数不为17, 请重新加载！"));
		vecszPath.clear();
		return;
	}

	/*for (int picturenumber =0; picturenumber < vecszPath.size(); ++picturenumber)
	{
	AfxMessageBox(vecszPath.at(picturenumber).GetBuffer(0));
	}

	USES_CONVERSION;
	char* cFilePath = T2A(vecszPath.at(1).GetBuffer(0));
	vecszPath.at(0).ReleaseBuffer();
	CString str;
	str.Format(_T("%d"), cFilePath);
	LPCTSTR pStr = LPCTSTR(str);
	AfxMessageBox(pStr);*/

if (!Throwpicture())
	{
		AfxMessageBox(_T("图像绘制失败！"));
		return;
	}


return;
	
	// TODO:  在此添加控件通知处理程序代码
}


bool CDKI1Dlg::Throwpicture()
{
	    int WindowCenter;
		int WindowWidth;
		USES_CONVERSION;
		char* cPathName = T2A(vecszPath.at(0).GetBuffer(0));
		vecszPath.at(0).ReleaseBuffer();
	
		DcmFileFormat *DcmfileFormat = new DcmFileFormat;
		DcmfileFormat->loadFile(cPathName);
		if (DcmfileFormat->loadFile(cPathName).bad())
		{
			AfxMessageBox(_T("打开Dicom文件失败！"));
			return FALSE;
		}
		DcmDataset *pDataset = DcmfileFormat->getDataset();
		E_TransferSyntax xfer = pDataset->getOriginalXfer();
		DicomImage *DcmImage = new DicomImage(DcmfileFormat, xfer, CIF_AcrNemaCompatibility, 0, 1);	//DicomImage* DcmImage = new DicomImage(cPathName);
		Width = DcmImage->getWidth();
		Height = DcmImage->getHeight();
		OFString FValue;
		if (pDataset->findAndGetOFStringArray(DCM_WindowCenter, FValue).good())
		{
			CString CValue = (CString)FValue.c_str();
			WindowCenter = _ttof(CValue);//读取Dicom窗位信息
		}
		if (pDataset->findAndGetOFStringArray(DCM_WindowWidth, FValue).good())
		{
			CString CValue = (CString)FValue.c_str();
			WindowWidth = _ttof(CValue);//读取Dicom窗宽信息
		}
	
		DcmImage->setWindow(WindowCenter, WindowWidth);//设定Dicom图像窗宽窗位
	
		int nScreeWidth, nScreeHeight;
		//nScreeWidth = GetSystemMetrics(SM_CXSCREEN);
		nScreeHeight = GetSystemMetrics(SM_CYSCREEN);
		CRect recDlg;
		GetWindowRect(recDlg);
		//MoveWindow(recDlg.left-111, recDlg.top-111, Width +120, Height + 30);//移动窗口位置以适应图像大小
		

        /* displaywidth=int(480/Width);
		 displayheigt = int(640 / Height);
		 displaywidth= int(min(displaywidth, displayheigt));*/
		 
		 
		 MoveWindow(380, 155, Width + 120,Height + 30);//移动窗口位置以适应图像大小
		CClientDC *pDC = new CClientDC(this);//创建绑定主对话框的设备上下文
	
		BITMAPINFOHEADER* BitmapInfoHeader = (BITMAPINFOHEADER*) new char[sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)* 256];
		BitmapInfoHeader->biSize = sizeof(BITMAPINFOHEADER);
		BitmapInfoHeader->biWidth = Width;
		BitmapInfoHeader->biHeight = Height;
		BitmapInfoHeader->biPlanes = 1;
		BitmapInfoHeader->biBitCount = 24;
		BitmapInfoHeader->biCompression = BI_RGB;
		BitmapInfoHeader->biSizeImage = 0;
		BitmapInfoHeader->biXPelsPerMeter = 0;
		BitmapInfoHeader->biYPelsPerMeter = 0;
		
		void* pDicomDibits;
		DcmImage->createWindowsDIB(pDicomDibits, 0, 0, 24, 1, 1);	//得到DICOM文件的24位图像数据
		pDC->SetStretchBltMode(COLORONCOLOR);//设定较好的缩放质量
		StretchDIBits(pDC->GetSafeHdc(), 0, 0, Width, Height, 0, 0, Width, Height,
			pDicomDibits, (LPBITMAPINFO)BitmapInfoHeader, DIB_RGB_COLORS, SRCCOPY);//显示Dicom图像/*displaywidth**/
	/*displayheigt* */
		return TRUE;
}


void CDKI1Dlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{


	CDialogEx::OnWindowPosChanged(lpwndpos);
	/*{CString str;
	str.Format(_T("%d"), (lpwndpos->cx));
	LPCTSTR pStr = LPCTSTR(str);
	AfxMessageBox(pStr); }*/
	if (lpwndpos->cx == 524)
		return;
	Graphbool = TRUE;

	CButton *pButton1 = (CButton*)GetDlgItem(IDC_OPENFILE);
	pButton1->ShowWindow(SW_HIDE);


	CButton *pButton2 = (CButton*)GetDlgItem(IDC_SELECT);
	pButton2->ShowWindow(SW_SHOW);
	pButton2->MoveWindow(CRect(lpwndpos->cx - 120, 1, lpwndpos->cx - 20, 50));
	CButton *pButton3 = (CButton*)GetDlgItem(IDC_GRAPH);
	pButton3->ShowWindow(SW_SHOW);
	pButton3->MoveWindow(CRect(lpwndpos->cx - 120, 55, lpwndpos->cx - 20, 104));
	CButton *pButton4 = (CButton*)GetDlgItem(IDC_REDO);
	pButton4->ShowWindow(SW_SHOW);
	pButton4->MoveWindow(CRect(lpwndpos->cx - 120, 109, lpwndpos->cx - 20, 158));

	CButton *pButton5 = (CButton*)GetDlgItem(IDC_SELECT2);
	pButton5->ShowWindow(SW_SHOW);
	pButton5->MoveWindow(CRect(lpwndpos->cx - 120, 163, lpwndpos->cx - 20, 212));

	// TODO:  在此处添加消息处理程序代码
}







void CDKI1Dlg::OnBnClickedSelect()
{
	m_ROI_Point = (0, 0);
	m_Graphbool = TRUE;
	// TODO:  在此添加控件通知处理程序代码
}



void amyfour1(double *data, const int n, const int isign) {
	int nn, mmax, m, j, istep, i;
	double wtemp, wr, wpr, wpi, wi, theta, tempr, tempi;
	
	
	nn = n << 1;
	j = 1;
	for (i = 1; i<nn; i += 2) {
		if (j > i) {
			SWAP(data[j - 1], data[i - 1]);
			SWAP(data[j], data[i]);
		}
		m = n;
		while (m >= 2 && j > m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	}

	mmax = 2;
	while (nn > mmax) {

		istep = mmax << 1;
		theta = isign*(6.28318530717959 / mmax);
		wtemp = sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi = sin(theta);
		wr = 1.0;
		wi = 0.0;
		for (m = 1; m < mmax; m += 2) {

			for (i = m; i <= nn; i += istep) {

				
					j = i + mmax;
					tempr = wr*data[j - 1] - wi*data[j];
					tempi = wr*data[j] + wi*data[j - 1];
					data[j - 1] = data[i - 1] - tempr;
					data[j] = data[i] - tempi;
					data[i - 1] += tempr;
					data[i] += tempi;
				}
				wr = (wtemp = wr)*wpr - wi*wpi + wr;
				wi = wi*wpr + wtemp*wpi + wi;
			}
			mmax = istep;
		}
	}


void myfour1(double(&data)[16], const int isign)
	{
		
			amyfour1(&data[0], 8, isign);
	}

	void myrealft(double(&data)[16], const int isign) {
	int i=0, i1=0, i2=0, i3=0, i4=0, n = 16;
	double c1 = 0.5, c2, h1r, h1i, h2r, h2i, wr, wi, wpr, wpi, wtemp;
	double theta = 3.141592653589793238 / double(n >> 1);
	if (isign == 1) {
		c2 = -0.5;
		myfour1(data, 1); 
	}
	else 
	{
		c2 = 0.5; 
		theta = -theta;
	}
	wtemp = sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi = sin(theta);
	wr = 1.0 + wpr;
	wi = wpi;

	for (i = 1; i<(n >> 2); i++) {
		
		i2 = 1 + (i1 = i + i);
		i4 = 1 + (i3 = n - i1);
		h1r = c1*(data[i1] + data[i3]);
		h1i=c1*(data[i2] - data[i4]);
		h2r = -c2*(data[i2] + data[i4]);
		h2i = c2*(data[i1] - data[i3]);
		data[i1] = h1r + wr*h2r - wi*h2i; 
	    data[i2] = h1i + wr*h2i + wi*h2r;
		data[i3] = h1r - wr*h2r + wi*h2i;
		data[i4] = -h1i + wr*h2i + wi*h2r;
		wr = (wtemp = wr)*wpr - wi*wpi + wr;
		wi = wi*wpr + wtemp*wpi + wi;
	}
	if (isign == 1) {
		data[0] = (h1r = data[0]) + data[1]; 
		data[1] = h1r - data[1];
	}
	else {
		data[0] = c1*((h1r = data[0]) + data[1]);
		data[1] = c1*(h1r - data[1]);
		myfour1(data, -1); 
	} 
}



	void mycosft1(double(&y)[17]) {
	
	
	int j, n = 16;
	double sum, y1, y2, theta, wi = 0.0, wpi, wpr, wr = 1.0, wtemp;
	double yy[16];
		theta = PI / n; 
		wtemp = sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi = sin(theta);
	sum = 0.5*(y[0] - y[n]);
	yy[0] = 0.5*(y[0] + y[n]);
	for (j = 1; j<n / 2; j++) 
	{
		wr = (wtemp = wr)*wpr - wi*wpi + wr;
		wi = wi*wpr + wtemp*wpi + wi;
		y1 = 0.5*(y[j] + y[n - j]); 
		y2 = (y[j] - y[n - j]);
		yy[j] = y1 - wi*y2; 
		yy[n - j] = y1 + wi*y2;
		sum += wr*y2; 
	}
	yy[n / 2] = y[n / 2]; 
	myrealft(yy, 1);
	for(j = 0; j<n; j++) y[j] = yy[j];
	y[n] = y[1];
		y[1] = sum; 
		for (j = 3; j<n; j += 2) {
			sum += y[j];
				y[j] = sum;
		}

		y[0] = y[0] / 2;
		for (j = 0; j<17; j++)
			y[j] = y[j] / 8;
		
}







void CDKI1Dlg::OnBnClickedGraph()
{
	
	
	

	if (m_ROI_Point.x == 0)
	{
		AfxMessageBox(_T("请选择一点后操作"));
		return;
	}

	

	
	
	
	//  bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb 绘制的信号
	
	double test[17] = { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 };
	for (int aa = 0; aa < 17; aa++)test[aa] =2 + 1 * cos(4*aa * 2 * PI / 16) + 1*cos(2 * aa * 2 * PI / 16);





	//传值放大
	double gdata_t[17];
	double temp_t[17];
	double temp_f[17];
	for (int i = 0; i < 17; ++i)
	{
		/*temp_t[i] = log(dki_data[i]);
		temp_f[i] = log(dki_data[i]);*/
		gdata_t[i] = log(dki_data[i]);
		/*temp_t[i] = test[i] * 10;
		temp_f[i] = test[i] * 10;
		gdata_t[i] = test[i] * 10;*/
		
	}
	gdata_t[4] = gdata_t[3];
	gdata_t[12] = gdata_t[11];
//{CString str;
//		str.Format(_T("%d"), (dki_data[8]));
//		LPCTSTR pStr = LPCTSTR(str);
//		AfxMessageBox(pStr); }

	//横坐标选取
	int singnal_t_q[17] = { 25 }; singnal_t_q[0] = 25;
	int startq = 25;
	for (int i = 1; i < 17; ++i)
	{
		startq += 36;
		singnal_t_q[i] = startq;

	}
	
	//信号调窗
	double centurepoint_q = 0;
	double dki_range_q = 0;
	{
		double tempmax = gdata_t[0], tempmin = gdata_t[0];
		for (int i = 1; i<17; i++)
		{

			if (gdata_t[i]>tempmax)
				tempmax = gdata_t[i];
		}

		for (int i = 1; i<17; i++)
		{

			if (gdata_t[i]<tempmin)
				tempmin = gdata_t[i];
		}
		dki_range_q = (tempmax - tempmin) / 2;
		centurepoint_q = tempmax - dki_range_q;
	}

	//归一化hou放大
	int gmypoint[17];
	for (int i = 0; i <17; ++i)
	{
		gmypoint[i] = int(((gdata_t[i] - centurepoint_q) / dki_range_q) * 100 + 110);

	}

	G_DIALOGI  *MYGRAPH = new  G_DIALOGI;
	MYGRAPH->Create(IDD_G_DIALOG1);
	MYGRAPH->ShowWindow(SW_SHOW);




	CClientDC dc(MYGRAPH);

	//c处理前DC绘图
	
	for (int i = 0; i < 17; ++i)
	{
		/*dc.MoveTo(singnal_t_q[i], gmypoint[i]);
		dc.LineTo(singnal_t_q[i+1], gmypoint[i+1]);*/
		dc.Ellipse(singnal_t_q[i] - 6,gmypoint[i] - 6, singnal_t_q[i] + 6, gmypoint[i] + 6);
		
		/*CString str;
		str.Format(_T("%d"), 6);
		LPCTSTR pStr = LPCTSTR(str);
		AfxMessageBox(pStr);*/
	}
	
	


	int singnal_t_cos[49] = { 25 }; singnal_t_cos[0] = 25;
	int start1 = 25;
	int cospoint[49];
	cospoint[0] = 210;
	for (int i = 1; i <49; ++i)
	{
		cospoint[i] = cos(4 * i *  PI / 48) * 100 + 110;
		start1 += 12;
		singnal_t_cos[i] = start1;

	}

	


	for (int i = 0; i < 48; ++i)
	{

		dc.MoveTo(singnal_t_cos[i], cospoint[i]);
		dc.LineTo(singnal_t_cos[i + 1], cospoint[i + 1]);

	}





	
	// TODO:  在此添加控件通知处理程序代码
}


void CDKI1Dlg::OnBnClickedRedo()
{
	m_ROI_Point = (0, 0);
	m_Graphbool = TRUE;// TODO:  在此添加控件通知处理程序代码
}


void CDKI1Dlg::OnMButtonDblClk(UINT nFlags, CPoint point)
{
	
}


void CDKI1Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{/*{CString str;
str.Format(_T("%d"), (point.x));
	LPCTSTR pStr = LPCTSTR(str);
	AfxMessageBox(pStr); }*/
	// TODO:  在此添加消息处理程序代码和/或调用默认值
if (FALSE == m_Graphbool)
	{
		AfxMessageBox(_T("点击按钮后操作"));
		return;
}
if (!(point.x >= 0 && point.x < Width && point.y >= 0 && point.y < Height))//displaywidth *displayheigt*
	{
		AfxMessageBox(_T("只能在图像区域内选择！"));
		return;
	}
	
	m_ROI_Point = point;
	int x = m_ROI_Point.x;// displaywidth;// displaywidth;
	int y = m_ROI_Point.y;// displaywidth;// displayheigt;
	m_PositionInArray = Width*y + x - 1;

	AfxMessageBox(_T("成功选择！"));
	
	
	
	
	
	multimap<int, int>map_reptition;
	int temp_pathsize = vecszPath.size();

	/*CString str;
	str.Format(_T("%d"), temp_pathsize);
	LPCTSTR pStr = LPCTSTR(str);
	AfxMessageBox(pStr);*/







	for (int path_n = 0; path_n < temp_pathsize; ++path_n)

	{
		USES_CONVERSION;
		char* cPathName = T2A(vecszPath.at(path_n).GetBuffer(0));
		//qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq	ss


		//int cnt_int = 0;
		////cnt_int 用于存放字符串中的数字.
		////cnt_index 作为字符串b的下标.

		//for (int i = 0; cPathName[i] != '\0'; ++i) //当a数组元素不为结束符时.遍历字符串a.
		//{
		//	if (cPathName[i] >= '0'&& cPathName[i] <= '9') //如果是数字.
		//	{
		//		cnt_int *= 10;
		//		cnt_int += cPathName[i] - '0'; //数字字符的ascii-字符'0'的ascii码就等于该数字.
		//	}


		//}
		//cnt_int = cnt_int % 100;
		/*CString str;
		str.Format(_T("%d"), cnt_int);
		LPCTSTR pStr = LPCTSTR(str);
		AfxMessageBox(pStr);*/
		

		/*int  reptition = cnt_int;*/
		//qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq	


		vecszPath.at(path_n).ReleaseBuffer();//CString转char*

		int *data = new int[Width*Height];//初始化图像数据缓冲区

		DcmFileFormat *DcmfileFormat = new DcmFileFormat;
		if (DcmfileFormat->loadFile(cPathName).bad())//读取cPathName对应的Dicom文件
		{
			AfxMessageBox(_T("打开Dicom文件失败 ！"));
			return;
		}
		DcmDataset *pDataset = DcmfileFormat->getDataset();
		E_TransferSyntax xfer = pDataset->getOriginalXfer();
		DicomImage *DcmImage = new DicomImage(DcmfileFormat , xfer, CIF_AcrNemaCompatibility, 0, 1);	//DicomImage* DcmImage = new DicomImage(cPathName);


		OFString acquisition;
		pDataset->findAndGetOFStringArray(DcmTagKey(0x0020, 0x0012), acquisition);
		CString acqtime = (CString)acquisition.c_str();
		
		char* chacqtime =T2A(acqtime);

		
		
  //      {
		//	
		//	
		//	CString str ; str = chacqtime;
		////str.Format(_T("%s"), chacqtime);
		//LPCTSTR pStr = LPCTSTR(str);
		//AfxMessageBox(pStr); 
		//
		//
		//
		//}
		int iacqtime = 0;
		for (int i = 0; chacqtime[i] != '\0'; ++i) //当a数组元素不为结束符时.遍历字符串a.
		{
			if (chacqtime[i] >= '0'&& chacqtime[i] <= '9') //如果是数字.
			{
				iacqtime *= 10;
				iacqtime += (chacqtime[i] - '0'); //数字字符的ascii-字符'0'的ascii码就等于该数字.
			}


		}
		int  reptition;
		reptition =int(iacqtime);
		/*{
				
				
				CString str ; 
				str.Format(_T("%d"), reptition);
			LPCTSTR pStr = LPCTSTR(str);
			AfxMessageBox(pStr); 
			
			
			
			}*/
		
		
		OFString OFStype;//
		pDataset->findAndGetOFStringArray(DCM_PixelRepresentation, OFStype);
		CString CStype = (CString)OFStype.c_str();
		
		

		int dki;
		if (CStype == "0")
		{
			Uint16* UPixeldata = (Uint16*)DcmImage->getOutputData();

			dki = UPixeldata[m_PositionInArray];

			
			{


				/*CString str;
				str.Format(_T("ccccccc%d"), dki);
				LPCTSTR pStr = LPCTSTR(str);
				AfxMessageBox(pStr);*/



			}
		}
		else if (CStype == "1")
		{
			Sint16* SPixeldata = (Sint16*)DcmImage->getOutputData();


			dki = (short)(SPixeldata[m_PositionInArray] - 32768);
			/*CString str;
			str.Format(_T("ffffcc%d"), dki);
			LPCTSTR pStr = LPCTSTR(str);
			AfxMessageBox(pStr);*/



		}
		else
		{
			AfxMessageBox(_T("数据格式出错！"));
			return;
		}

		map_reptition.insert(map<int, int>::value_type(reptition, dki));

	}

	
	multimap<int, int>::iterator i, iend;
	iend = map_reptition.end();
	int j = 0;
	for (i = map_reptition.begin(); i != iend; i++)
	{

		dki_data[j] = int((*i).second);
		j++;

	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	return;// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnMButtonDblClk(nFlags, point);
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


//void CDKI1Dlg::cosdcf()
//{
//}


//⁯void CDKI1Dlg::cosdfa(Vec_IO_DP & y)
//{
//
//}




void CDKI1Dlg::OnBnClickedOpenfile2()
{



	//short test1[17] = { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 };
	//for (short i = 0; i < 17; ++i)test1[i] = short(200 *( exp(1 + cos(4 * i *  PI / 16) + cos(2 * i *  PI / 16))));
	///*for (int i = 0; i < 17; i++)
	//{
	//	double f = cos( i * PI / 16);
	//	CString str;
	//	str.Format(_T("COS%f"), f);
	//	LPCTSTR pStr = LPCTSTR(str);
	//	AfxMessageBox(pStr);

	//}
	//for (int i = 0; i < 17; i++)
	//{
	//double f = sin( i * PI / 16);
	//CString str;
	//str.Format(_T("SIN%f"), f);
	//LPCTSTR pStr = LPCTSTR(str);
	//AfxMessageBox(pStr);

	//}*/
	//for (int j = 0; j < 17; ++j)
	//{
		

	
//	CFile DkiR, DkiW;
//	DkiR.Open(vecszPath.at(0), CFile::modeRead);
//	int Length = DkiR.GetLength();
//	
//	
//	//SHORT 两个字节
//	short* sdata = new short[Length/2];
//	
//	DkiR.Read(sdata, Length);
//	DkiR.Close();
//	
//	int c1 = Width * Height / 4 + Width / 2+111 ;
//	int c2 = Width * Height / 4 + Width / 2 + 1 + 111;
//	int c3 = Width * Height / 4 + Width / 2 + 2 + 111;
//	int c4 = Width * Height / 4 + Width / 2 + Width + 111;
//	int c5 = Width * Height / 4 + Width / 2 + Width + 1 + 111;
//	int c6 = Width * Height / 4 + Width / 2 + Width + 2 + 111;
//	int c7 = Width * Height / 4 + Width / 2 + 2 * Width + 111;
//	int c8 = Width * Height / 4 + Width / 2 + 2 * Width + 1 + 111;
//	int c9 = Width * Height / 4 + Width / 2 + 2 * Width + 2 + 111;
//	/*{
//		int f = Width;
//		CString str;
//		str.Format(_T("w%d"), f);
//		LPCTSTR pStr = LPCTSTR(str);
//		AfxMessageBox(pStr);
//
//	}
//	{
//		int f = Height;
//		CString str;
//		str.Format(_T("h%d"), f);
//		LPCTSTR pStr = LPCTSTR(str);
//		AfxMessageBox(pStr);
//
//	}*/
//
//
//	int starti = Length / 2-Width * Height;
//	for (int i = 0; i < Width * Height; ++i){
//		if (c1 == i || i == c2 || i == c3 || i == c4 || c5 == i || i == c6 || i == c7 || i == c8 || i == c9)
//		/*if (Width * Height / 2 < i && (i < Width * Height / 2 + Width))*/
//			sdata[starti + i] = (test1[j] + int(rand() % 10));
//		else
//		sdata[starti + i]=0;
//	}
//	CFileDialog DkiWrite(FALSE, _T("*.dcm"), NULL, OFN_OVERWRITEPROMPT, _T("医学影像格式(*.dcm)|*.dcm|所有文件|*.*|"), NULL);
//	if (IDCANCEL == DkiWrite.DoModal())
//		return;
//
//	DkiW.Open(DkiWrite.GetPathName(), CFile::modeCreate | CFile::modeWrite);
//	DkiW.Write(sdata, Length);//
//	DkiW.Close();
//	delete[]sdata;
//
//}
	// TODO:  在此添加控件通知处理程序代码
}


void CDKI1Dlg::OnBnClickedSelect2()
{
	double gdata_t[17];
	double temp_t[17];
	double temp_f[17];
	for (int i = 0; i < 17; ++i)
	{
		temp_t[i] = log(dki_data[i]);
		temp_f[i] = log(dki_data[i]);
		gdata_t[i] = log(dki_data[i]);
		/*temp_t[i] = test[i] * 10;
		temp_f[i] = test[i] * 10;
		gdata_t[i] = test[i] * 10;*/
	}

	temp_t[4] = temp_t[3];
	temp_f[4] = temp_t[3];
	gdata_t[4]= temp_t[3];
	temp_t[12] = temp_t[11];
	temp_f[12] = temp_t[11];
	gdata_t[12] = temp_t[11];




	//  余弦转换计算
	mycosft1(temp_f);


	//剔除2倍频	
	double f2 = temp_f[2];

	for (int i = 0; i < 17; ++i)
	{
		temp_t[i] = temp_t[i] - f2*cos(2 * PI*i / 16);
	}




	//弹出窗口
	CDKIAG  *DKIAG = new  CDKIAG;
	DKIAG->Create(IDD_AGGH);
	DKIAG->ShowWindow(SW_SHOW);

	double dkical[6] = { 1, 1, 2, 2, 3, 3 };
	for (int i = 0; i < 6; i++)
	{
		dkical[i] = temp_f[2 * i];
	}


	for (int i = 0; i < 6; i++)
	{

		CString str;
		str.Format(_T("%f"), (dkical[i]));
		LPCTSTR pStr = LPCTSTR(str);

		if (0 == i)
			DKIAG->mylist.InsertItem(0, pStr);
		DKIAG->mylist.SetItemText(0, i, pStr);

	}

	


	//信号调窗
	double centurepoint_h = 0;
	double dki_range_h = 0;
	{
		double tempmax = temp_t[0], tempmin = temp_t[0];
		for (int i = 1; i<17; i++)
		{

			if (temp_t[i]>tempmax)
				tempmax = temp_t[i];
		}

		for (int i = 1; i<17; i++)
		{

			if (temp_t[i]<tempmin)
				tempmin = temp_t[i];
		}
		dki_range_h = (tempmax - tempmin) / 2;
		centurepoint_h = tempmax - dki_range_h;
	}
//横坐标选取
	int singnal_t_h[17]; singnal_t_h[0] = 25;
	int start = 25;
	for (int i = 1; i < 17; ++i)
	{
		start += 36;
		singnal_t_h[i] = start;

	}
	//归一化hou放大
	int mypoint[17];
	for (int i = 0; i <17; ++i)
	{
		mypoint[i] = int(((temp_t[i] - centurepoint_h) / dki_range_h) * 100 + 110.5);

	}

	int singnal_t_cos[49] = { 25 }; singnal_t_cos[0] = 25;
	int start1 = 25;
	int cospoint[49];
	cospoint[0] = 210;
	for (int i = 1; i <49; ++i)
	{
		cospoint[i] = cos(4 * i *  PI / 48) * 100 + 110;
		start1 += 12;
		singnal_t_cos[i] = start1;

	}

	//DC绘图
	CClientDC myag(DKIAG);
	for (int i = 0; i < 17; ++i)
	{
		
		myag.Ellipse(singnal_t_h[i] - 6, mypoint[i] - 6, singnal_t_h[i] + 6, mypoint[i] + 6);

	}

	for (int i = 0; i < 48; ++i)
	{

		myag.MoveTo(singnal_t_cos[i], cospoint[i]);
		myag.LineTo(singnal_t_cos[i + 1], cospoint[i + 1]);

	}
	
	
	
	
	
	
	
	// TODO:  在此添加控件通知处理程序代码
}
