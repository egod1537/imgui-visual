#pragma once

#include "imgui.h"
#include <cmath>

namespace imgv {
    inline ImVec2 operator+(const ImVec2 &a, const ImVec2 &b) { return {a.x + b.x, a.y + b.y}; }
    inline ImVec2 operator-(const ImVec2 &a, const ImVec2 &b) { return {a.x - b.x, a.y - b.y}; }
    inline ImVec2 operator*(const ImVec2 &a, float s) { return {a.x * s, a.y * s}; }
    inline ImVec2 operator/(const ImVec2 &a, float s) { return {a.x / s, a.y / s}; }

    inline float Dot(const ImVec2 &a, const ImVec2 &b) { return a.x * b.x + a.y * b.y; }
    inline float Length(const ImVec2 &v) { return std::sqrt(Dot(v, v)); }
    inline float LengthSq(const ImVec2 &v) { return Dot(v, v); }
    inline ImVec2 Normalize(const ImVec2 &v) { return v / Length(v); }
    inline float Cross(const ImVec2 &a, const ImVec2 &b) { return a.x * b.y - a.y * b.x; }
    inline ImVec2 Lerp(const ImVec2 &a, const ImVec2 &b, float t) { return a + (b - a) * t; }
}