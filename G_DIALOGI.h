#pragma once


// G_DIALOGI �Ի���

class G_DIALOGI : public CDialogEx
{
	DECLARE_DYNAMIC(G_DIALOGI)

public:
	G_DIALOGI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~G_DIALOGI();

// �Ի�������
	enum { IDD = IDD_G_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
