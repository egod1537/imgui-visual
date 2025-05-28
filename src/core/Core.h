#pragma once

#include <windows.h>
#include "stdafx.h"
#include "ImWindow.h"

namespace imgv {
	class D3DImgui;

	class Core {
	public :
		static Core* Instance() {
		if (!instance) {
			instance = new Core();
		}
		return instance;
	}

		void Run(HINSTANCE hinstance);

		void AddWindow(std::unique_ptr<ImWindow> window);

	private:
		void Start();
		void Update();
		void End();

		std::list<std::unique_ptr<ImWindow>> windows;
		D3DImgui* d3dImgui;

		static Core* instance;
	};
}