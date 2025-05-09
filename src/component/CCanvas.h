#pragma once

#include <vector>
#include <string>

#include "Component.h"
#include "imgui.h"

namespace imgv {
	struct DrawStyle
	{
	private:
		ImU32 stroke;
		ImU32 fill;
		float thickness;

	public:
		ImU32 GetStroke() const { return stroke; }
		ImU32 GetFill() const { return fill; }
		float GetThickness() const { return thickness; }

		struct Builder
		{
		private:
			ImU32 stroke = IM_COL32_WHITE;
			ImU32 fill = IM_COL32_BLACK;
			float thickness = 1.0f;

		public:
			Builder &Stroke(ImU32 color)
			{
				stroke = color;
				return *this;
			}

			Builder &Fill(ImU32 color)
			{
				fill = color;
				return *this;
			}

			Builder &Thickness(float t)
			{
				thickness = t;
				return *this;
			}

			DrawStyle Build() const
			{
				return DrawStyle(stroke, fill, thickness);
			}
		};

		static Builder Create() { return Builder(); }

	private:
		DrawStyle(ImU32 s, ImU32 f, float t)
			: stroke(s), fill(f), thickness(t) {}

		friend struct Builder;
	};

	class CCanvas : public Component
	{
	protected:
		ImVec2 At(float x, float y) const;
		ImVec2 At(const ImVec2 &p) const;
		void Line(const ImVec2 &p1, const ImVec2 &p2, ImU32 color = 0, float thickness = 0);
		void Rect(const ImVec2 &min, const ImVec2 &max, ImU32 color = 0, float thickness = 0);
		void RectFill(const ImVec2 &min, const ImVec2 &max, ImU32 color = 0);
		void Circle(const ImVec2 &center, float radius, ImU32 color = 0, float thickness = 0);
		void CircleFill(const ImVec2 &center, float radius, ImU32 color = 0);
		void Polygon(const std::vector<ImVec2> &points, ImU32 color = 0, bool closed = true, float thickness = 0);
		void PolygonFill(const std::vector<ImVec2> &points, ImU32 color = 0);
		void Text(const ImVec2 &pos, const char *text, ImU32 color=0);
		void Text(const ImVec2 &pos, const std::string &text, ImU32 color=0);

	public:
		void Update() override;

		virtual void OnDrawCanvas() {}

		void PushStyle(const DrawStyle &style);
		void PopStyle();
		DrawStyle GetCurrentStyle() const;

	private:
		ImVec2 origin;
		ImDrawList *drawList;
		std::vector<DrawStyle> styleStack;
	};
}