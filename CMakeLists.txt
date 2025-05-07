cmake_minimum_required(VERSION 3.31)
project(imgui_visual)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_DIR imgui)
set(IMGUI_BACKEND_DIR ${IMGUI_DIR}/backends)
set(SRC_DIR src)

# ImGui 소스
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_BACKEND_DIR}/imgui_impl_win32.cpp
        ${IMGUI_BACKEND_DIR}/imgui_impl_dx11.cpp
)

# core/*.cpp 자동 포함
file(GLOB_RECURSE CORE_SOURCES ${SRC_DIR}/core/*.cpp)

add_executable(imgui_visual WIN32
        ${IMGUI_SOURCES}
        ${SRC_DIR}/main.cpp
        ${CORE_SOURCES}
)

target_include_directories(imgui_visual PRIVATE
        ${IMGUI_DIR}
        ${IMGUI_BACKEND_DIR}
        ${SRC_DIR}
        ${SRC_DIR}/core
)

target_link_libraries(imgui_visual
        d3d11
        dxgi
        d3dcompiler
)

if (WIN32)
    target_compile_definitions(imgui_visual PRIVATE -DUNICODE -D_UNICODE)
endif()
