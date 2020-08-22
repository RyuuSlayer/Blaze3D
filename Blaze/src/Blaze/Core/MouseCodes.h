#pragma once

namespace Blaze
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define BZ_MOUSE_BUTTON_0      ::Blaze::Mouse::Button0
#define BZ_MOUSE_BUTTON_1      ::Blaze::Mouse::Button1
#define BZ_MOUSE_BUTTON_2      ::Blaze::Mouse::Button2
#define BZ_MOUSE_BUTTON_3      ::Blaze::Mouse::Button3
#define BZ_MOUSE_BUTTON_4      ::Blaze::Mouse::Button4
#define BZ_MOUSE_BUTTON_5      ::Blaze::Mouse::Button5
#define BZ_MOUSE_BUTTON_6      ::Blaze::Mouse::Button6
#define BZ_MOUSE_BUTTON_7      ::Blaze::Mouse::Button7
#define BZ_MOUSE_BUTTON_LAST   ::Blaze::Mouse::ButtonLast
#define BZ_MOUSE_BUTTON_LEFT   ::Blaze::Mouse::ButtonLeft
#define BZ_MOUSE_BUTTON_RIGHT  ::Blaze::Mouse::ButtonRight
#define BZ_MOUSE_BUTTON_MIDDLE ::Blaze::Mouse::ButtonMiddle