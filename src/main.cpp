#include <windows.h>
#include "D3DImgui.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    D3DImgui* d3dImgui = new D3DImgui();

    d3dImgui->Initialize(hInstance);
    {
        d3dImgui->Run();
    }
    d3dImgui->Release();
    return 0;
}