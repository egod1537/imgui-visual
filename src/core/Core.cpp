#include "Core.h"

#include "imgui.h"
#include "D3DImgui.h"

namespace imgv {
    Core* Core::instance = nullptr;

    void Core::Run(HINSTANCE hInstance) {
        d3dImgui = new D3DImgui();

        d3dImgui->Initialize(hInstance);
        Start();
        {
            d3dImgui->Run(std::bind(&Core::Update, this));
        }
        End();
        d3dImgui->Release();
    }

    void Core::Start() {

    }

    void Core::Update() {
        for (auto& window : windows) {
            ImGui::Begin(window->name.c_str());
            {
                window->Update();
            }
            ImGui::End();
        }

        ImGui::ShowDemoWindow();
    }

    void Core::End() {

    }

    void Core::AddWindow(std::unique_ptr<ImWindow> window) {
        windows.push_back(std::move(window));
    }
}