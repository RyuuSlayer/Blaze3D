#pragma once

#include <glm/glm.hpp>

#include "Blaze/Core/KeyCodes.h"
#include "Blaze/Core/MouseCodes.h"

namespace Blaze {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}