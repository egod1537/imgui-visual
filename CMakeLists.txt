# CMake 최소 요구 버전 설정
cmake_minimum_required(VERSION 3.15)

# 프로젝트 이름 및 언어 설정
project(imgui_visual CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 경로 변수 설정 ---
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_BACKEND_DIR ${IMGUI_DIR}/backends)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# --- 소스 파일 설정 ---
# (이전과 동일하게 설정합니다)
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_BACKEND_DIR}/imgui_impl_win32.cpp
        ${IMGUI_BACKEND_DIR}/imgui_impl_dx11.cpp
)
file(GLOB_RECURSE CORE_SOURCES ${SRC_DIR}/core/*.cpp)
file(GLOB_RECURSE COMPONENT_SOURCES ${SRC_DIR}/component/*.cpp)
file(GLOB_RECURSE IMWINDOW_SOURCES ${SRC_DIR}/imWindow/*.cpp)
file(GLOB_RECURSE UTILS_SOURCES ${SRC_DIR}/utils/*.cpp)
set(HEADER_FILES
        ${INCLUDES_DIR}/imgv.h
)

# --- 라이브러리 생성 (항상 생성) ---
add_library(imgui_visual STATIC
        ${IMGUI_SOURCES}
        ${CORE_SOURCES}
        ${COMPONENT_SOURCES}
        ${IMWINDOW_SOURCES}
        ${UTILS_SOURCES}
        ${HEADER_FILES}
)

# --- 라이브러리 설정 (항상 설정) ---
target_include_directories(imgui_visual PRIVATE
        ${IMGUI_DIR}
        ${IMGUI_BACKEND_DIR}
        ${SRC_DIR}
        ${INCLUDES_DIR}
        ${SRC_DIR}/core
        ${SRC_DIR}/component
        ${SRC_DIR}/imWindow
        ${SRC_DIR}/utils
)

target_include_directories(imgui_visual INTERFACE
        ${HEADER_FILES}
)

target_link_libraries(imgui_visual PUBLIC
        d3d11
        dxgi
        d3dcompiler
        dwmapi
)
if (WIN32)
    target_compile_definitions(imgui_visual PUBLIC UNICODE _UNICODE)
endif()

# --- 실행 파일 생성 (최상위 프로젝트일 때만 생성!) ---
# 현재 디렉토리가 CMake가 시작된 최상위 디렉토리와 같은지 확인합니다.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # 같다면, 즉 이 프로젝트를 단독으로 빌드하는 경우, 실행 파일을 추가합니다.
    add_executable(imgui_visual_exe WIN32 # <-- 이름을 다르게 지정!
            ${SRC_DIR}/main.cpp
    )

    target_include_directories(imgui_visual_exe PRIVATE
            ${IMGUI_DIR}
            ${IMGUI_BACKEND_DIR}
            ${SRC_DIR}
            ${INCLUDES_DIR}
            ${SRC_DIR}/core
            ${SRC_DIR}/component
            ${SRC_DIR}/imWindow
            ${SRC_DIR}/utils
    )

    # 생성된 라이브러리를 실행 파일에 링크합니다.
    target_link_libraries(imgui_visual_exe PRIVATE imgui_visual)
    # 메시지를 출력하여 실행 파일이 생성되었음을 알립니다 (선택 사항)
    message(STATUS "Building standalone executable: imgui_visual_exe")
endif()