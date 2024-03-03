
// MFCApplication2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, WORD1);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication2Dlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	/*CString str;
	GetDlgItemText(IDC_EDIT1, str);
	int value = _ttoi(str);
	//WORD1 = value;
	CEdit* ppEdit = (CEdit*)GetDlgItem(IDC_EDIT2);



	int spaceIndex = str.Find(' '); // Находим индекс первого пробела

	CString firstPart;
	if (spaceIndex != -1) // Проверяем, что пробел найден
	{
		firstPart = str.Left(spaceIndex); // Получаем первую часть строки до пробела
	}
	else
	{
		firstPart = str; // Если пробел не найден, используем всю строку
	}
	//ReverseString(firstPart);

	int length = firstPart.GetLength();
	for (int i = 0; i < length / 2; i++)
	{
		TCHAR temp = firstPart.GetAt(i);
		firstPart.SetAt(i, firstPart.GetAt(length - i - 1));
		firstPart.SetAt(length - i - 1, temp);
	}
	TCHAR t = '\0';
	firstPart.SetAt(length, t);
	ppEdit->SetWindowText(firstPart); */
	CString strr;
	GetDlgItemText(IDC_EDIT1, strr);
	//int value = _ttoi(strr);
	//WORD1 = value;
	CEdit* ppEdit = (CEdit*)GetDlgItem(IDC_EDIT2);



	int spaceIndex = strr.Find(' '); // Находим индекс первого пробела

	CString firstPart, str;
	if (spaceIndex != -1) // Проверяем, что пробел найден
	{
		firstPart = strr.Left(spaceIndex); // Получаем первую часть строки до пробела
	}
	else
	{
		firstPart = strr; // Если пробел не найден, используем всю строку
	}
	str = firstPart;
	WORD1 = str;
	//ReverseString(firstPart);

	int length = firstPart.GetLength();
	if (length == 1)
		firstPart.SetAt(0, firstPart.GetAt(0));
	for (int i = 0; i < length / 2; i++)
	{
		TCHAR temp = firstPart.GetAt(i);
		firstPart.SetAt(i, firstPart.GetAt(length - i - 1));
		firstPart.SetAt(length - i - 1, temp);
	}
	if (WORD2 == firstPart)
	{
	
}
	else
	{
		WORD2 = firstPart;
		ppEdit->SetWindowText(WORD2);
	}
}


void CMFCApplication2Dlg::OnEnChangeEdit2()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	int value = _ttoi(str);
	//WORD1 = value;
	CEdit* ppEdit = (CEdit*)GetDlgItem(IDC_EDIT1);



	int spaceIndex = str.Find(' '); // Находим индекс первого пробела

	CString firstPart;
	if (spaceIndex != -1) // Проверяем, что пробел найден
	{
		firstPart = str.Left(spaceIndex); // Получаем первую часть строки до пробела
	}
	else
	{
		firstPart = str; // Если пробел не найден, используем всю строку
	}
	//ReverseString(firstPart);
	
	str = firstPart;
	WORD2 = str;
	int length = firstPart.GetLength();
	for (int i = 0; i < length / 2; i++)
	{
		TCHAR temp = firstPart.GetAt(i);
		firstPart.SetAt(i, firstPart.GetAt(length - i - 1));
		firstPart.SetAt(length - i - 1, temp);
	}
	if (WORD1 == firstPart)
	{

	}
	else
	{
		WORD1 = firstPart;
		ppEdit->SetWindowText(WORD1);
	}
}
