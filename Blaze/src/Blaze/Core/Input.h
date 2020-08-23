#pragma once

#include "Blaze/Core/Base.h"
#include "Blaze/Core/KeyCodes.h"
#include "Blaze/Core/MouseCodes.h"

namespace Blaze {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}