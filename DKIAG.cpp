// DKIAG.cpp : 实现文件
//

#include "stdafx.h"
#include "DKI(1).h"
#include "DKIAG.h"
#include "afxdialogex.h"


// CDKIAG 对话框

IMPLEMENT_DYNAMIC(CDKIAG, CDialogEx)

CDKIAG::CDKIAG(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDKIAG::IDD, pParent)
{

}

CDKIAG::~CDKIAG()
{
}

void CDKIAG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mylist);
}


BEGIN_MESSAGE_MAP(CDKIAG, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDKIAG::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CDKIAG 消息处理程序


void CDKIAG::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CDKIAG::OnInitDialog()
{  


	CDialogEx::OnInitDialog();
	 mylist.InsertColumn(0, _T("0倍频"),0,100);
	 mylist.InsertColumn(1, _T("2倍频"), 0, 100);
	 mylist.InsertColumn(2, _T("4倍频"), 0, 100);
	 mylist.InsertColumn(3, _T("6倍频"), 0, 100);
	 mylist.InsertColumn(4, _T("8倍频"), 0, 100);
	 mylist.InsertColumn(5, _T("10倍频"), 0, 100);
	

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
