#pragma once


// G_DIALOGI 对话框

class G_DIALOGI : public CDialogEx
{
	DECLARE_DYNAMIC(G_DIALOGI)

public:
	G_DIALOGI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~G_DIALOGI();

// 对话框数据
	enum { IDD = IDD_G_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
