#pragma once
#include "afxcmn.h"


// CDKIAG �Ի���

class CDKIAG : public CDialogEx
{
	DECLARE_DYNAMIC(CDKIAG)

public:
	CDKIAG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDKIAG();

// �Ի�������
	enum { IDD = IDD_AGGH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mylist;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
