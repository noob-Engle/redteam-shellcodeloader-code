/*

 Red Team Operator course code template - DLL
 author: reenz0h (twitter: @sektor7net)

*/

#include <Windows.h>
#pragma comment (lib, "user32.lib")/*编译动作指令#pragma 执行语言实现所定义的用于，具体的内容需要参考所使用的​​编译器的帮助comment都是用来调用动态库或静态库的*/

/*DllMain函数是DLL模块的默认入口点。
当Windows加载DLL模块时调用这一函数。系统首先调用全局对象的构造函数，然后调用全局函数 DLLMain。
DLLMain函数不仅在将DLL链接加载到进程时被调用，在DLL模块与进程分离时（以及其它时候）也被调用
*/
/*
APIENTRY被定义为__stdcall，它意味着这个函数以标准Pascal的方式进行调用，也就是WINAPI方式
函数参数hModule是进程中的每个DLL模块被全局唯一的32字节的HINSTANCE句柄标识（句柄代表了DLL模块在进程虚拟空间中的起始地址， 只有在特定的进程内部有效 ）
在Win32中，HINSTANCE和HMODULE的值是相同的，这两种类型可以替换使用
参数ul_reason_for_call指明了被调用的原因
共有4种，即PROCESS_ATTACH、PROCESS_DETACH、THREAD_ATTACH和THREAD_DETACH，以switch语句列出.
lpReserved 表示一个保留参数，目前已经很少使用
*/
BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {

    switch (ul_reason_for_call)  {
    case DLL_PROCESS_ATTACH:
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
/*实现类C和C++的混合编程,用于定义编译器将使用 C 函数命名约定而不是 C++,大多数代码都使用该指令，因为 C 函数名称比 C++ 更易于理解*/
extern "C" {
/*__declspec（导出）我制作了一个具有导出函数void WINAPI SampleFunc(void)*/
__declspec(dllexport) BOOL WINAPI RunME(void) {
	
	MessageBox(
		NULL,
		"noob Operator, here I come!",
		"noob",
        MB_OK
	);
	 
		 return TRUE;
	}
}
