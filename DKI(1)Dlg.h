
// DKI(1)Dlg.h : 头文件
//


#pragma once
#include <vector>
using namespace std;


// CDKI1Dlg 对话框
class CDKI1Dlg : public CDialogEx
{
// 构造
public:
	
	CPoint m_ROI_Point = (0, 0);
	BOOL m_Graphbool = FALSE;
	int m_PositionInArray;
	int Width;
	int Height;
	vector<CString>vecszPath;
	int dki_data[17];
	BOOL Graphbool = FALSE;
	
	int displaywidth;
	int displayheigt;

	
	CDKI1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DKI1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenfile();
	bool Throwpicture();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedGraph();
	afx_msg void OnBnClickedRedo();
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
//	void cosdcf();
//	⁯void cosdfa(Vec_IO_DP & y);
//	void cosdf(Vec_IO_DP & y);
	afx_msg void OnBnClickedOpenfile2();
	afx_msg void OnBnClickedSelect2();
};
