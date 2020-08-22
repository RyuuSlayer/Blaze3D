#pragma once

namespace Blaze
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define BZ_KEY_SPACE           ::Blaze::Key::Space
#define BZ_KEY_APOSTROPHE      ::Blaze::Key::Apostrophe    /* ' */
#define BZ_KEY_COMMA           ::Blaze::Key::Comma         /* , */
#define BZ_KEY_MINUS           ::Blaze::Key::Minus         /* - */
#define BZ_KEY_PERIOD          ::Blaze::Key::Period        /* . */
#define BZ_KEY_SLASH           ::Blaze::Key::Slash         /* / */
#define BZ_KEY_0               ::Blaze::Key::D0
#define BZ_KEY_1               ::Blaze::Key::D1
#define BZ_KEY_2               ::Blaze::Key::D2
#define BZ_KEY_3               ::Blaze::Key::D3
#define BZ_KEY_4               ::Blaze::Key::D4
#define BZ_KEY_5               ::Blaze::Key::D5
#define BZ_KEY_6               ::Blaze::Key::D6
#define BZ_KEY_7               ::Blaze::Key::D7
#define BZ_KEY_8               ::Blaze::Key::D8
#define BZ_KEY_9               ::Blaze::Key::D9
#define BZ_KEY_SEMICOLON       ::Blaze::Key::Semicolon     /* ; */
#define BZ_KEY_EQUAL           ::Blaze::Key::Equal         /* = */
#define BZ_KEY_A               ::Blaze::Key::A
#define BZ_KEY_B               ::Blaze::Key::B
#define BZ_KEY_C               ::Blaze::Key::C
#define BZ_KEY_D               ::Blaze::Key::D
#define BZ_KEY_E               ::Blaze::Key::E
#define BZ_KEY_F               ::Blaze::Key::F
#define BZ_KEY_G               ::Blaze::Key::G
#define BZ_KEY_H               ::Blaze::Key::H
#define BZ_KEY_I               ::Blaze::Key::I
#define BZ_KEY_J               ::Blaze::Key::J
#define BZ_KEY_K               ::Blaze::Key::K
#define BZ_KEY_L               ::Blaze::Key::L
#define BZ_KEY_M               ::Blaze::Key::M
#define BZ_KEY_N               ::Blaze::Key::N
#define BZ_KEY_O               ::Blaze::Key::O
#define BZ_KEY_P               ::Blaze::Key::P
#define BZ_KEY_Q               ::Blaze::Key::Q
#define BZ_KEY_R               ::Blaze::Key::R
#define BZ_KEY_S               ::Blaze::Key::S
#define BZ_KEY_T               ::Blaze::Key::T
#define BZ_KEY_U               ::Blaze::Key::U
#define BZ_KEY_V               ::Blaze::Key::V
#define BZ_KEY_W               ::Blaze::Key::W
#define BZ_KEY_X               ::Blaze::Key::X
#define BZ_KEY_Y               ::Blaze::Key::Y
#define BZ_KEY_Z               ::Blaze::Key::Z
#define BZ_KEY_LEFT_BRACKET    ::Blaze::Key::LeftBracket   /* [ */
#define BZ_KEY_BACKSLASH       ::Blaze::Key::Backslash     /* \ */
#define BZ_KEY_RIGHT_BRACKET   ::Blaze::Key::RightBracket  /* ] */
#define BZ_KEY_GRAVE_ACCENT    ::Blaze::Key::GraveAccent   /* ` */
#define BZ_KEY_WORLD_1         ::Blaze::Key::World1        /* non-US #1 */
#define BZ_KEY_WORLD_2         ::Blaze::Key::World2        /* non-US #2 */

/* Function keys */
#define BZ_KEY_ESCAPE          ::Blaze::Key::Escape
#define BZ_KEY_ENTER           ::Blaze::Key::Enter
#define BZ_KEY_TAB             ::Blaze::Key::Tab
#define BZ_KEY_BACKSPACE       ::Blaze::Key::Backspace
#define BZ_KEY_INSERT          ::Blaze::Key::Insert
#define BZ_KEY_DELETE          ::Blaze::Key::Delete
#define BZ_KEY_RIGHT           ::Blaze::Key::Right
#define BZ_KEY_LEFT            ::Blaze::Key::Left
#define BZ_KEY_DOWN            ::Blaze::Key::Down
#define BZ_KEY_UP              ::Blaze::Key::Up
#define BZ_KEY_PAGE_UP         ::Blaze::Key::PageUp
#define BZ_KEY_PAGE_DOWN       ::Blaze::Key::PageDown
#define BZ_KEY_HOME            ::Blaze::Key::Home
#define BZ_KEY_END             ::Blaze::Key::End
#define BZ_KEY_CAPS_LOCK       ::Blaze::Key::CapsLock
#define BZ_KEY_SCROLL_LOCK     ::Blaze::Key::ScrollLock
#define BZ_KEY_NUM_LOCK        ::Blaze::Key::NumLock
#define BZ_KEY_PRINT_SCREEN    ::Blaze::Key::PrintScreen
#define BZ_KEY_PAUSE           ::Blaze::Key::Pause
#define BZ_KEY_F1              ::Blaze::Key::F1
#define BZ_KEY_F2              ::Blaze::Key::F2
#define BZ_KEY_F3              ::Blaze::Key::F3
#define BZ_KEY_F4              ::Blaze::Key::F4
#define BZ_KEY_F5              ::Blaze::Key::F5
#define BZ_KEY_F6              ::Blaze::Key::F6
#define BZ_KEY_F7              ::Blaze::Key::F7
#define BZ_KEY_F8              ::Blaze::Key::F8
#define BZ_KEY_F9              ::Blaze::Key::F9
#define BZ_KEY_F10             ::Blaze::Key::F10
#define BZ_KEY_F11             ::Blaze::Key::F11
#define BZ_KEY_F12             ::Blaze::Key::F12
#define BZ_KEY_F13             ::Blaze::Key::F13
#define BZ_KEY_F14             ::Blaze::Key::F14
#define BZ_KEY_F15             ::Blaze::Key::F15
#define BZ_KEY_F16             ::Blaze::Key::F16
#define BZ_KEY_F17             ::Blaze::Key::F17
#define BZ_KEY_F18             ::Blaze::Key::F18
#define BZ_KEY_F19             ::Blaze::Key::F19
#define BZ_KEY_F20             ::Blaze::Key::F20
#define BZ_KEY_F21             ::Blaze::Key::F21
#define BZ_KEY_F22             ::Blaze::Key::F22
#define BZ_KEY_F23             ::Blaze::Key::F23
#define BZ_KEY_F24             ::Blaze::Key::F24
#define BZ_KEY_F25             ::Blaze::Key::F25

/* Keypad */
#define BZ_KEY_KP_0            ::Blaze::Key::KP0
#define BZ_KEY_KP_1            ::Blaze::Key::KP1
#define BZ_KEY_KP_2            ::Blaze::Key::KP2
#define BZ_KEY_KP_3            ::Blaze::Key::KP3
#define BZ_KEY_KP_4            ::Blaze::Key::KP4
#define BZ_KEY_KP_5            ::Blaze::Key::KP5
#define BZ_KEY_KP_6            ::Blaze::Key::KP6
#define BZ_KEY_KP_7            ::Blaze::Key::KP7
#define BZ_KEY_KP_8            ::Blaze::Key::KP8
#define BZ_KEY_KP_9            ::Blaze::Key::KP9
#define BZ_KEY_KP_DECIMAL      ::Blaze::Key::KPDecimal
#define BZ_KEY_KP_DIVIDE       ::Blaze::Key::KPDivide
#define BZ_KEY_KP_MULTIPLY     ::Blaze::Key::KPMultiply
#define BZ_KEY_KP_SUBTRACT     ::Blaze::Key::KPSubtract
#define BZ_KEY_KP_ADD          ::Blaze::Key::KPAdd
#define BZ_KEY_KP_ENTER        ::Blaze::Key::KPEnter
#define BZ_KEY_KP_EQUAL        ::Blaze::Key::KPEqual

#define BZ_KEY_LEFT_SHIFT      ::Blaze::Key::LeftShift
#define BZ_KEY_LEFT_CONTROL    ::Blaze::Key::LeftControl
#define BZ_KEY_LEFT_ALT        ::Blaze::Key::LeftAlt
#define BZ_KEY_LEFT_SUPER      ::Blaze::Key::LeftSuper
#define BZ_KEY_RIGHT_SHIFT     ::Blaze::Key::RightShift
#define BZ_KEY_RIGHT_CONTROL   ::Blaze::Key::RightControl
#define BZ_KEY_RIGHT_ALT       ::Blaze::Key::RightAlt
#define BZ_KEY_RIGHT_SUPER     ::Blaze::Key::RightSuper
#define BZ_KEY_MENU            ::Blaze::Key::Menu