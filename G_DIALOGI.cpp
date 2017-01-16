// G_DIALOGI.cpp : 实现文件
//

#include "stdafx.h"
#include "DKI(1).h"
#include "G_DIALOGI.h"
#include "afxdialogex.h"


// G_DIALOGI 对话框

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


// G_DIALOGI 消息处理程序


BOOL G_DIALOGI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
