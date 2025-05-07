#pragma once

#include <d3d11.h>
#include <windows.h>

struct IDXGISwapChain;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;

class D3DImgui {
public:
    bool Initialize(HWND hWnd);
    void BeginFrame();
    void EndFrame();
    void Release();

    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();

    void CreateRenderTarget();
    void CleanupRenderTarget();

    void OpenConsole();

    IDXGISwapChain*          g_pSwapChain = nullptr;
    ID3D11Device*            g_pd3dDevice = nullptr;
private:
    ID3D11DeviceContext*     g_pd3dDeviceContext = nullptr;
    ID3D11RenderTargetView*  g_mainRenderTargetView = nullptr;
};