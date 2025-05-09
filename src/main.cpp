#include <windows.h>
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    imgv::Core::Instance()->Run(hInstance);
    return 0;
}
