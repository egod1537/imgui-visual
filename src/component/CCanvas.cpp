#include "CCanvas.h"

#include "imvec2_utils.h"
namespace imgv {
 void CCanvas::Update() {
	this->drawList = ImGui::GetWindowDrawList();
	this->origin = ImGui::GetCursorScreenPos();
	OnDrawCanvas();
}

ImVec2 CCanvas::At(float x, float y) const {
    return ImVec2(this->origin.x + x, this->origin.y + y);
}
ImVec2 CCanvas::At(const ImVec2& p) const {
    return ImVec2(this->origin.x + p.x, this->origin.y + p.y);
}

void CCanvas::Line(const ImVec2& p1, const ImVec2& p2, ImU32 color, float thickness) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetStroke();
    if (thickness <= 0.0f) thickness = cs.GetThickness();
    this->drawList->AddLine(At(p1), At(p2), color, thickness);
}

void CCanvas::Rect(const ImVec2& min, const ImVec2& max, ImU32 color, float thickness) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetStroke();
    if (thickness <= 0.0f) thickness = cs.GetThickness();
    this->drawList->AddRect(At(min), At(max), color, 0.0f, 0, thickness);
}

void CCanvas::RectFill(const ImVec2& min, const ImVec2& max, ImU32 color) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetFill();
    this->drawList->AddRectFilled(At(min), At(max), color);
}

void CCanvas::Circle(const ImVec2& center, float radius, ImU32 color, float thickness) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetStroke();
    if (thickness <= 0.0f) thickness = cs.GetThickness();
    this->drawList->AddCircle(At(center), radius, color, 0, thickness);
}

void CCanvas::CircleFill(const ImVec2& center, float radius, ImU32 color) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetFill();
    this->drawList->AddCircleFilled(At(center), radius, color);
}

void CCanvas::Polygon(const std::vector<ImVec2>& points, ImU32 color, bool closed, float thickness) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetStroke();
    if (thickness <= 0.0f) thickness = cs.GetThickness();
    std::vector<ImVec2> transformed;
    transformed.reserve(points.size());
    for (const auto& p : points) {
        transformed.push_back(At(p));
    }
    this->drawList->AddPolyline(transformed.data(), (int)transformed.size(), color, closed, thickness);
}

void CCanvas::PolygonFill(const std::vector<ImVec2>& points, ImU32 color) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetFill();
    std::vector<ImVec2> transformed;
    transformed.reserve(points.size());
    for (const auto& p : points) {
        transformed.push_back(At(p));
    }
    this->drawList->AddConvexPolyFilled(transformed.data(), (int)transformed.size(), color);
}

void CCanvas::Text(const ImVec2& pos, const char* text, ImU32 color) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetFill();

    this->drawList->AddText(At(pos), color, text);
}
void CCanvas::Text(const ImVec2& pos, const std::string& text, ImU32 color) {
    DrawStyle cs = GetCurrentStyle();
    if (color == 0) color = cs.GetFill();

	this->drawList->AddText(At(pos), color, text.c_str());
}

void CCanvas::PushStyle(const DrawStyle& style) {
    styleStack.push_back(style);
}
void CCanvas::PopStyle() {
    assert(!styleStack.empty());
    styleStack.pop_back();
}
DrawStyle CCanvas::GetCurrentStyle() const {
    if (styleStack.empty())
        return DrawStyle::Create().Build();
    return styleStack.back();
}
}