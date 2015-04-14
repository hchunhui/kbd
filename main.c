#include <windows.h>
#include <tchar.h>

const TCHAR * const ClassName = _T("KBDClass");

struct btn_info {
	const TCHAR * const name;
	int x, y, w, h;
	WORD vk;
};

#include "config.h"

static void wm_create(HWND hwnd)
{
	int i;

	for(i = 0; buttons[i].name; i++) {
		CreateWindow(_T("button"), buttons[i].name,
			     WS_VISIBLE | WS_CHILD,
			     SCALE * buttons[i].x + OX,
			     SCALE * buttons[i].y + OY,
			     SCALE * buttons[i].w,
			     SCALE * buttons[i].h,
			     hwnd, (HMENU) i, NULL, NULL);
	}
}

static void wm_command(int idx)
{
	INPUT input;
	memset(&input, 0, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = buttons[idx].vk;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg) {
	case WM_CREATE:
		wm_create(hwnd);
		SetTimer(hwnd, 0, 1000, (TIMERPROC) NULL);
		break;
	case WM_COMMAND:
		wm_command(wParam);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		     LPTSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	int i;
	RECT rect, rectD;
	int w = 0, h = 0;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = ClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, _T("Window Registration Failed!"),
			   _T("KBD"), MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	for(i = 0; buttons[i].name; i++) {
		int t;
		t = buttons[i].x + buttons[i].w;
		if(w < t)
			w = t;
		t = buttons[i].y + buttons[i].h;
		if(h < t)
			h = t;
	}
	rect.left = rect.top = 0;
	rect.right = SCALE * w + 2 * OX;
	rect.bottom = SCALE * h + 2 * OY;
	AdjustWindowRectEx(&rect,
			   WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			   FALSE,
			   WS_EX_CLIENTEDGE | WS_EX_NOACTIVATE);
	GetWindowRect(GetDesktopWindow(), &rectD);

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE | WS_EX_NOACTIVATE | WS_EX_APPWINDOW,
		ClassName,
		_T("KBD"),
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
		100, rectD.bottom - (rect.bottom - rect.top) - 100,
		rect.right - rect.left, rect.bottom - rect.top,
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, _T("Window Creation Failed!"),
			   _T("KBD"), MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
