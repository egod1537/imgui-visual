#pragma once

#include "imgui.h"

namespace imgv {
	class Component {
	public:
		virtual void Start() {}
		virtual void Update(){}
		virtual void End() {}

		virtual void OnMouseMove(ImVec2 windowPos) {}

		virtual void OnMouseLeftDown(ImVec2 windowPos) {}
		virtual void OnMouseLeftDragging(ImVec2 windowPos) {}
		virtual void OnMouseLeftUp(ImVec2 windowPos) {}

		virtual void OnMouseRightDown(ImVec2 windowPos) {}
		virtual void OnMouseRightDragging(ImVec2 windowPos) {}
		virtual void OnMouseRightUp(ImVec2 windowPos) {}

		virtual void OnMouseWheelDown(ImVec2 windowPos) {}
		virtual void OnMouseWheelDragging(ImVec2 windowPos) {}
		virtual void OnMouseWheelUp(ImVec2 windowPos) {}
	};
}