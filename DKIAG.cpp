// DKIAG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DKI(1).h"
#include "DKIAG.h"
#include "afxdialogex.h"


// CDKIAG �Ի���

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


// CDKIAG ��Ϣ�������


void CDKIAG::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


BOOL CDKIAG::OnInitDialog()
{  


	CDialogEx::OnInitDialog();
	 mylist.InsertColumn(0, _T("0��Ƶ"),0,100);
	 mylist.InsertColumn(1, _T("2��Ƶ"), 0, 100);
	 mylist.InsertColumn(2, _T("4��Ƶ"), 0, 100);
	 mylist.InsertColumn(3, _T("6��Ƶ"), 0, 100);
	 mylist.InsertColumn(4, _T("8��Ƶ"), 0, 100);
	 mylist.InsertColumn(5, _T("10��Ƶ"), 0, 100);
	

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
