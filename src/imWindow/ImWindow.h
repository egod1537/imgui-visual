#pragma once

#include "stdafx.h"
#include "Component.h"
#include "imgui.h"

namespace imgv {
	class ImWindow
	{
	public:
		const std::string name;
		ImWindow(std::string name);

		void Start();
		void Update();
		void End();

		template <typename T>
		T *AddComponent();

		template <typename T>
		T *GetComponent();

	private:
		std::list<std::unique_ptr<Component>> components;

		void ProcessInputEvent();
		void ProcessComponentInputEvent(const ImGuiIO &io);

		void Component_OnMouseMove(ImVec2 windowPos);

		void Component_OnMouseLeftDown(ImVec2 windowPos);
		void Component_OnMouseLeftDragging(ImVec2 windowPos);
		void Component_OnMouseLeftUp(ImVec2 windowPos);

		void Component_OnMouseRightDown(ImVec2 windowPos);
		void Component_OnMouseRightDragging(ImVec2 windowPos);
		void Component_OnMouseRightUp(ImVec2 windowPos);

		void Component_OnMouseWheelDown(ImVec2 windowPos);
		void Component_OnMouseWheelDragging(ImVec2 windowPos);
		void Component_OnMouseWheelUp(ImVec2 windowPos);
	};

#include "ImWindow.inl"
}
