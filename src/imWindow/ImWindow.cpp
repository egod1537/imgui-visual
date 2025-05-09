#include "ImWindow.h"

#include <iostream>
#include "imgui_utils.h"

namespace imgv {
ImWindow::ImWindow(std::string _name)
	: name(std::move(_name))
{
}

void ImWindow::Update()
{
	ProcessInputEvent();
	for (auto &component : components)
	{
		component->Update();
	}
}

void ImWindow::ProcessInputEvent()
{
	if (!ImGui::IsWindowFocused())
	{
		return;
	}

	ImGuiIO &io = ImGui::GetIO();
	ProcessComponentInputEvent(io);
}

void ImWindow::ProcessComponentInputEvent(const ImGuiIO &io)
{
	ImVec2 mousePos = io.MousePos;
	ImVec2 windowPos = ImGui::GetWindowPos();
	ImVec2 titleBarSize(ImGui::GetStyle().FramePadding.x * 2, ImGui::GetFontSize()*2);

	ImVec2 windowMousePos = mousePos - windowPos - titleBarSize;

	if (!ImGui::IsWindowHovered())
	{
		return;
	}

	if (io.MouseDelta.x != 0 || io.MouseDelta.y != 0)
	{
		Component_OnMouseMove(windowMousePos);
	}

	if (ImGui::IsMouseClicked(0))
	{
		Component_OnMouseLeftDown(windowMousePos);
	}
	if (ImGui::IsMouseDragging(0))
	{
		Component_OnMouseLeftDragging(windowMousePos);
	}
	if (ImGui::IsMouseReleased(0))
	{
		Component_OnMouseLeftUp(windowMousePos);
	}

	if (ImGui::IsMouseClicked(1))
	{
		Component_OnMouseRightDown(windowMousePos);
	}
	if (ImGui::IsMouseDragging(1))
	{
		Component_OnMouseRightDragging(windowMousePos);
	}
	if (ImGui::IsMouseReleased(1))
	{
		Component_OnMouseRightUp(windowMousePos);
	}

	if (ImGui::IsMouseClicked(2))
	{
		Component_OnMouseWheelDown(windowMousePos);
	}
	if (ImGui::IsMouseDragging(2))
	{
		Component_OnMouseWheelDragging(windowMousePos);
	}
	if (ImGui::IsMouseReleased(2))
	{
		Component_OnMouseWheelUp(windowMousePos);
	}
}

void ImWindow::Component_OnMouseMove(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseMove(windowPos);
	}
}

void ImWindow::Component_OnMouseLeftDown(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseLeftDown(windowPos);
	}
}
void ImWindow::Component_OnMouseLeftDragging(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseLeftDragging(windowPos);
	}
}
void ImWindow::Component_OnMouseLeftUp(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseLeftUp(windowPos);
	}
}

void ImWindow::Component_OnMouseRightDown(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseRightDown(windowPos);
	}
}
void ImWindow::Component_OnMouseRightDragging(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseRightDragging(windowPos);
	}
}
void ImWindow::Component_OnMouseRightUp(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseRightUp(windowPos);
	}
}

void ImWindow::Component_OnMouseWheelDown(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseWheelDown(windowPos);
	}
}
void ImWindow::Component_OnMouseWheelDragging(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseWheelDragging(windowPos);
	}
}
void ImWindow::Component_OnMouseWheelUp(ImVec2 windowPos)
{
	for (auto &component : components)
	{
		component->OnMouseWheelUp(windowPos);
	}
}
}