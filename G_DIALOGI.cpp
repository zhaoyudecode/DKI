// G_DIALOGI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DKI(1).h"
#include "G_DIALOGI.h"
#include "afxdialogex.h"


// G_DIALOGI �Ի���

IMPLEMENT_DYNAMIC(G_DIALOGI, CDialogEx)

G_DIALOGI::G_DIALOGI(CWnd* pParent /*=NULL*/)
	: CDialogEx(G_DIALOGI::IDD, pParent)
{

}

G_DIALOGI::~G_DIALOGI()
{
}

void G_DIALOGI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(G_DIALOGI, CDialogEx)
END_MESSAGE_MAP()


// G_DIALOGI ��Ϣ�������


BOOL G_DIALOGI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
