#pragma once
#include "afxcmn.h"


// CDKIAG 对话框

class CDKIAG : public CDialogEx
{
	DECLARE_DYNAMIC(CDKIAG)

public:
	CDKIAG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDKIAG();

// 对话框数据
	enum { IDD = IDD_AGGH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mylist;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
