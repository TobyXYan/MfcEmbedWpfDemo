#include "pch.h"
#include "WpfWndWrap.h"
#include <gcroot.h>
using namespace System::Windows;

public ref class MWpfWndControlHolder
{
public:

	System::Windows::Interop::HwndSourceParameters^ m_pHwndSrcParams;
	System::Windows::Interop::HwndSource^ m_HwndSource;
	System::Windows::Interop::HwndSourceHook^ m_pSourceHook; //For allowing Keyboard input to WPF control attached to C++ Control

	WpfWnd::ViewModels::WpfViewModel^ m_pWpfViewModel;// directly from C# WPF control (to Show as Child)


	MWpfWndControlHolder()
	{
		m_pHwndSrcParams = gcnew System::Windows::Interop::HwndSourceParameters();
		m_HwndSource = nullptr;
		m_pSourceHook = gcnew System::Windows::Interop::HwndSourceHook(&ChildHwndSourceHook);
		m_pWpfViewModel =WpfWnd::WpfWndHelper::Instance->GetWpfVm();
	}

	~MWpfWndControlHolder()
	{
		if (m_pHwndSrcParams != nullptr)
		{
			delete m_pHwndSrcParams;
			m_pHwndSrcParams = nullptr;
		}

		if (m_pWpfViewModel != nullptr)
		{
			delete m_pWpfViewModel;
			m_pWpfViewModel = nullptr;
		}

		System::GC::Collect();
	}

	//For Enabling Keyboard
	static System::IntPtr ChildHwndSourceHook(System::IntPtr hwnd, int msg, System::IntPtr wParam, System::IntPtr lParam, bool% handled)
	{
		if (msg == WM_GETDLGCODE)
		{
			handled = true;
			return System::IntPtr(DLGC_WANTCHARS | DLGC_WANTTAB | DLGC_WANTARROWS | DLGC_WANTALLKEYS);
		}

		return System::IntPtr::Zero;
	}

	void OnSetModified() // This is called from WPF Control/C# side (via Delegate)
	{
		HWND hwndParent = (HWND)m_pHwndSrcParams->ParentWindow.ToInt32();
		if (hwndParent)
			SendMessage(hwndParent, WM_SET_MODIFIED_WPF_VIEW, (WPARAM)NULL, (LPARAM)NULL);

	}
};


struct SWpfWndControlMediator
{
	gcroot<MWpfWndControlHolder^>  m_pMWpfWndControlHolder;

	SWpfWndControlMediator()
	{
		m_pMWpfWndControlHolder = gcnew MWpfWndControlHolder();
	}

	~SWpfWndControlMediator()
	{
		if (m_pMWpfWndControlHolder)
			delete m_pMWpfWndControlHolder;

		System::GC::Collect();
	}

	WpfWnd::ViewModels::WpfViewModel^ GetWpfViewModel()
	{
		return m_pMWpfWndControlHolder->m_pWpfViewModel;
	}

};


MWpfWndControl::MWpfWndControl(HWND hwndParent)
{
	m_hwndParent = hwndParent;
	m_pWpfWndControlMediator = new SWpfWndControlMediator();
}

MWpfWndControl:: ~MWpfWndControl()
{
	if (m_pWpfWndControlMediator != NULL)
	{
		delete m_pWpfWndControlMediator;
		m_pWpfWndControlMediator = NULL;
	}
}

void MWpfWndControl::ShowAsChild(HWND parent, int x, int y)
{
	try
	{
		if (m_hwndParent == NULL)
			m_hwndParent = parent;

		FrameworkElement^ myPage = m_pWpfWndControlMediator->GetWpfViewModel()->GetView();
		int height = m_pWpfWndControlMediator->GetWpfViewModel()->WndHeight;
		int width = m_pWpfWndControlMediator->GetWpfViewModel()->WndWidth;

		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->PositionX = x;
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->PositionY = y;
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->Height    = height;
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->Width     = width;
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->ParentWindow = System::IntPtr(parent);
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams->WindowStyle  = WS_VISIBLE | WS_CHILD;

		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_HwndSource = gcnew System::Windows::Interop::HwndSource(*m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pHwndSrcParams);
		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_HwndSource->AddHook(m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_pSourceHook);

		// Get the View from WPF Control to attach it

		m_pWpfWndControlMediator->m_pMWpfWndControlHolder->m_HwndSource->RootVisual = myPage;
		m_pWpfWndControlMediator->GetWpfViewModel()->OnSetModifiedDelegate = gcnew WpfWnd::ViewModels::WpfViewModel::SetModifiedDelegate(m_pWpfWndControlMediator->m_pMWpfWndControlHolder, &MWpfWndControlHolder::OnSetModified);

	}
	catch (System::Exception^ e)
	{
		System::String^ nowString = e->GetType()->Name + "\r\n" + e->Message + "\r\n" + e->StackTrace;
		System::IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(nowString);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);
	}
}


void MWpfWndControl::SetData(std::string text)
{
	System::String^ str = gcnew System::String (text.data());
	m_pWpfWndControlMediator->GetWpfViewModel()->SetData(str);
}

void MWpfWndControl::GetData(std::string& text)
{
	System::String^ wpfText;
	m_pWpfWndControlMediator->GetWpfViewModel()->GetData(wpfText);
	char* tmpText =(char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(wpfText);
	text = tmpText;
	System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)tmpText);
}


void MWpfWndControl::GetWndHeightWidth(int* height, int* width)
{
	*height = m_pWpfWndControlMediator->GetWpfViewModel()->WndHeight;
	*width = m_pWpfWndControlMediator->GetWpfViewModel()->WndWidth;
}