# CMake 최소 요구 버전 설정 (CLion 환경 고려 3.15 이상 권장)
cmake_minimum_required(VERSION 3.15)

# 프로젝트 이름 및 언어 설정
project(imgui_visual CXX) # 프로젝트 이름은 그대로 두어도 됩니다.

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 경로 변수 설정 ---
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_BACKEND_DIR ${IMGUI_DIR}/backends)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# --- 소스 파일 설정 ---

# ImGui 소스
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp # 데모가 필요 없다면 이 줄을 제거하세요.
        ${IMGUI_BACKEND_DIR}/imgui_impl_win32.cpp
        ${IMGUI_BACKEND_DIR}/imgui_impl_dx11.cpp
)

# 프로젝트 소스 (main.cpp 제외)
file(GLOB_RECURSE CORE_SOURCES ${SRC_DIR}/core/*.cpp)
file(GLOB_RECURSE COMPONENT_SOURCES ${SRC_DIR}/component/*.cpp)
file(GLOB_RECURSE IMWINDOW_SOURCES ${SRC_DIR}/imWindow/*.cpp)
file(GLOB_RECURSE UTILS_SOURCES ${SRC_DIR}/utils/*.cpp)

# 헤더 파일
set(HEADER_FILES
        ${INCLUDES_DIR}/imgv.h
)

# --- 라이브러리 생성 (이름을 'imgui_visual'로 변경) ---
add_library(imgui_visual STATIC # <-- 이름을 'imgui_visual'로 변경!
        ${IMGUI_SOURCES}
        # ${SRC_DIR}/main.cpp # <-- main.cpp 제외!
        ${CORE_SOURCES}
        ${COMPONENT_SOURCES}
        ${IMWINDOW_SOURCES}
        ${UTILS_SOURCES}
        ${HEADER_FILES}
)

# --- 라이브러리 인클루드 디렉토리 설정 (타겟 이름을 'imgui_visual'로 변경) ---
target_include_directories(imgui_visual PUBLIC # <-- 이름을 'imgui_visual'로 변경!
        ${IMGUI_DIR}
        ${IMGUI_BACKEND_DIR}
        ${SRC_DIR}
        ${INCLUDES_DIR}
        ${SRC_DIR}/core
        ${SRC_DIR}/component
        ${SRC_DIR}/imWindow
        ${SRC_DIR}/utils
)

# --- 라이브러리 링크 설정 (타겟 이름을 'imgui_visual'로 변경) ---
target_link_libraries(imgui_visual PUBLIC # <-- 이름을 'imgui_visual'로 변경!
        d3d11
        dxgi
        d3dcompiler
        dwmapi
)

# --- 라이브러리 컴파일 정의 (타겟 이름을 'imgui_visual'로 변경) ---
if (WIN32)
    target_compile_definitions(imgui_visual PUBLIC UNICODE _UNICODE) # <-- 이름을 'imgui_visual'로 변경!
endif()

# --- 실행 파일 생성 부분은 제거됨 ---
# 만약 실행 파일도 만들고 싶다면, add_executable(다른_이름 ...) 으로 만드세요.