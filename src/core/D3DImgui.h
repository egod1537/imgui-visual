#pragma once

#include <d3d11.h>
#include <windows.h>

struct IDXGISwapChain;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;

class D3DImgui {
public:
    bool Initialize(HINSTANCE hInstance);
    void Release();
    void Run();

    static LRESULT CALLBACK WndProcStatic(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    HWND hWnd = nullptr;
    WNDCLASSEX wc = {};

    IDXGISwapChain*          g_pSwapChain = nullptr;
    ID3D11Device*            g_pd3dDevice = nullptr;
    ID3D11DeviceContext*     g_pd3dDeviceContext = nullptr;
    ID3D11RenderTargetView*  g_mainRenderTargetView = nullptr;

    void CreateConsole();
    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();

    void BeginFrame();
    void EndFrame();

    void OnFrame();

    static D3DImgui* instance;
};