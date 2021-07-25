// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// KeyCodes.h                                                                //
// ========================================================================= //

#ifndef KEYCODES_H_
#define KEYCODES_H_

#include <ostream>

namespace univer
{
enum class KeyCode : unsigned short
{
	// From glfw3.h
	Space               = 32,
	Apostrophe          = 39, /* ' */
	Comma               = 44, /* , */
	Minus               = 45, /* - */
	Period              = 46, /* . */
	Slash               = 47, /* / */

	D0                  = 48, /* 0 */
	D1                  = 49, /* 1 */
	D2                  = 50, /* 2 */
	D3                  = 51, /* 3 */
	D4                  = 52, /* 4 */
	D5                  = 53, /* 5 */
	D6                  = 54, /* 6 */
	D7                  = 55, /* 7 */
	D8                  = 56, /* 8 */
	D9                  = 57, /* 9 */

	Semicolon           = 59, /* ; */
	Equal               = 61, /* = */

	A                   = 65,
	B                   = 66,
	C                   = 67,
	D                   = 68,
	E                   = 69,
	F                   = 70,
	G                   = 71,
	H                   = 72,
	I                   = 73,
	J                   = 74,
	K                   = 75,
	L                   = 76,
	M                   = 77,
	N                   = 78,
	O                   = 79,
	P                   = 80,
	Q                   = 81,
	R                   = 82,
	S                   = 83,
	T                   = 84,
	U                   = 85,
	V                   = 86,
	W                   = 87,
	X                   = 88,
	Y                   = 89,
	Z                   = 90,

	LeftBracket         = 91,  /* [ */
	Backslash           = 92,  /* \ */
	RightBracket        = 93,  /* ] */
	GraveAccent         = 96,  /* ` */

	World1              = 161, /* non-US #1 */
	World2              = 162, /* non-US #2 */

	/* Function keys */
	Escape              = 256,
	Enter               = 257,
	Tab                 = 258,
	Backspace           = 259,
	Insert              = 260,
	Delete              = 261,
	Right               = 262,
	Left                = 263,
	Down                = 264,
	Up                  = 265,
	PageUp              = 266,
	PageDown            = 267,
	Home                = 268,
	End                 = 269,
	CapsLock            = 280,
	ScrollLock          = 281,
	NumLock             = 282,
	PrintScreen         = 283,
	Pause               = 284,
	F1                  = 290,
	F2                  = 291,
	F3                  = 292,
	F4                  = 293,
	F5                  = 294,
	F6                  = 295,
	F7                  = 296,
	F8                  = 297,
	F9                  = 298,
	F10                 = 299,
	F11                 = 300,
	F12                 = 301,
	F13                 = 302,
	F14                 = 303,
	F15                 = 304,
	F16                 = 305,
	F17                 = 306,
	F18                 = 307,
	F19                 = 308,
	F20                 = 309,
	F21                 = 310,
	F22                 = 311,
	F23                 = 312,
	F24                 = 313,
	F25                 = 314,

	/* Keypad */
	KP0                 = 320,
	KP1                 = 321,
	KP2                 = 322,
	KP3                 = 323,
	KP4                 = 324,
	KP5                 = 325,
	KP6                 = 326,
	KP7                 = 327,
	KP8                 = 328,
	KP9                 = 329,
	KPDecimal           = 330,
	KPDivide            = 331,
	KPMultiply          = 332,
	KPSubtract          = 333,
	KPAdd               = 334,
	KPEnter             = 335,
	KPEqual             = 336,

	LeftShift           = 340,
	LeftControl         = 341,
	LeftAlt             = 342,
	LeftSuper           = 343,
	RightShift          = 344,
	RightControl        = 345,
	RightAlt            = 346,
	RightSuper          = 347,
	Menu                = 348
};

inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
{
	os << static_cast<int32_t>(keyCode);
	return os;
}
}

#define UVR_KEY_SPACE           ::univer::KeyCode::Space
#define UVR_KEY_APOSTROPHE      ::univer::KeyCode::Apostrophe    /* ' */
#define UVR_KEY_COMMA           ::univer::KeyCode::Comma         /* , */
#define UVR_KEY_MINUS           ::univer::KeyCode::Minus         /* - */
#define UVR_KEY_PERIOD          ::univer::KeyCode::Period        /* . */
#define UVR_KEY_SLASH           ::univer::KeyCode::Slash         /* / */
#define UVR_KEY_0               ::univer::KeyCode::D0
#define UVR_KEY_1               ::univer::KeyCode::D1
#define UVR_KEY_2               ::univer::KeyCode::D2
#define UVR_KEY_3               ::univer::KeyCode::D3
#define UVR_KEY_4               ::univer::KeyCode::D4
#define UVR_KEY_5               ::univer::KeyCode::D5
#define UVR_KEY_6               ::univer::KeyCode::D6
#define UVR_KEY_7               ::univer::KeyCode::D7
#define UVR_KEY_8               ::univer::KeyCode::D8
#define UVR_KEY_9               ::univer::KeyCode::D9
#define UVR_KEY_SEMICOLON       ::univer::KeyCode::Semicolon     /* ; */
#define UVR_KEY_EQUAL           ::univer::KeyCode::Equal         /* = */
#define UVR_KEY_A               ::univer::KeyCode::A
#define UVR_KEY_B               ::univer::KeyCode::B
#define UVR_KEY_C               ::univer::KeyCode::C
#define UVR_KEY_D               ::univer::KeyCode::D
#define UVR_KEY_E               ::univer::KeyCode::E
#define UVR_KEY_F               ::univer::KeyCode::F
#define UVR_KEY_G               ::univer::KeyCode::G
#define UVR_KEY_H               ::univer::KeyCode::H
#define UVR_KEY_I               ::univer::KeyCode::I
#define UVR_KEY_J               ::univer::KeyCode::J
#define UVR_KEY_K               ::univer::KeyCode::K
#define UVR_KEY_L               ::univer::KeyCode::L
#define UVR_KEY_M               ::univer::KeyCode::M
#define UVR_KEY_N               ::univer::KeyCode::N
#define UVR_KEY_O               ::univer::KeyCode::O
#define UVR_KEY_P               ::univer::KeyCode::P
#define UVR_KEY_Q               ::univer::KeyCode::Q
#define UVR_KEY_R               ::univer::KeyCode::R
#define UVR_KEY_S               ::univer::KeyCode::S
#define UVR_KEY_T               ::univer::KeyCode::T
#define UVR_KEY_U               ::univer::KeyCode::U
#define UVR_KEY_V               ::univer::KeyCode::V
#define UVR_KEY_W               ::univer::KeyCode::W
#define UVR_KEY_X               ::univer::KeyCode::X
#define UVR_KEY_Y               ::univer::KeyCode::Y
#define UVR_KEY_Z               ::univer::KeyCode::Z
#define UVR_KEY_LEFT_BRACKET    ::univer::KeyCode::LeftBracket   /* [ */
#define UVR_KEY_BACKSLASH       ::univer::KeyCode::Backslash     /* \ */
#define UVR_KEY_RIGHT_BRACKET   ::univer::KeyCode::RightBracket  /* ] */
#define UVR_KEY_GRAVE_ACCENT    ::univer::KeyCode::GraveAccent   /* ` */
#define UVR_KEY_WORLD_1         ::univer::KeyCode::World1        /* non-US #1 */
#define UVR_KEY_WORLD_2         ::univer::KeyCode::World2        /* non-US #2 */

#define UVR_KEY_ESCAPE          ::univer::KeyCode::Escape
#define UVR_KEY_ENTER           ::univer::KeyCode::Enter
#define UVR_KEY_TAB             ::univer::KeyCode::Tab
#define UVR_KEY_BACKSPACE       ::univer::KeyCode::Backspace
#define UVR_KEY_INSERT          ::univer::KeyCode::Insert
#define UVR_KEY_DELETE          ::univer::KeyCode::Delete
#define UVR_KEY_RIGHT           ::univer::KeyCode::Right
#define UVR_KEY_LEFT            ::univer::KeyCode::Left
#define UVR_KEY_DOWN            ::univer::KeyCode::Down
#define UVR_KEY_UP              ::univer::KeyCode::Up
#define UVR_KEY_PAGE_UP         ::univer::KeyCode::PageUp
#define UVR_KEY_PAGE_DOWN       ::univer::KeyCode::PageDown
#define UVR_KEY_HOME            ::univer::KeyCode::Home
#define UVR_KEY_END             ::univer::KeyCode::End
#define UVR_KEY_CAPS_LOCK       ::univer::KeyCode::CapsLock
#define UVR_KEY_SCROLL_LOCK     ::univer::KeyCode::ScrollLock
#define UVR_KEY_NUM_LOCK        ::univer::KeyCode::NumLock
#define UVR_KEY_PRINT_SCREEN    ::univer::KeyCode::PrintScreen
#define UVR_KEY_PAUSE           ::univer::KeyCode::Pause
#define UVR_KEY_F1              ::univer::KeyCode::F1
#define UVR_KEY_F2              ::univer::KeyCode::F2
#define UVR_KEY_F3              ::univer::KeyCode::F3
#define UVR_KEY_F4              ::univer::KeyCode::F4
#define UVR_KEY_F5              ::univer::KeyCode::F5
#define UVR_KEY_F6              ::univer::KeyCode::F6
#define UVR_KEY_F7              ::univer::KeyCode::F7
#define UVR_KEY_F8              ::univer::KeyCode::F8
#define UVR_KEY_F9              ::univer::KeyCode::F9
#define UVR_KEY_F10             ::univer::KeyCode::F10
#define UVR_KEY_F11             ::univer::KeyCode::F11
#define UVR_KEY_F12             ::univer::KeyCode::F12
#define UVR_KEY_F13             ::univer::KeyCode::F13
#define UVR_KEY_F14             ::univer::KeyCode::F14
#define UVR_KEY_F15             ::univer::KeyCode::F15
#define UVR_KEY_F16             ::univer::KeyCode::F16
#define UVR_KEY_F17             ::univer::KeyCode::F17
#define UVR_KEY_F18             ::univer::KeyCode::F18
#define UVR_KEY_F19             ::univer::KeyCode::F19
#define UVR_KEY_F20             ::univer::KeyCode::F20
#define UVR_KEY_F21             ::univer::KeyCode::F21
#define UVR_KEY_F22             ::univer::KeyCode::F22
#define UVR_KEY_F23             ::univer::KeyCode::F23
#define UVR_KEY_F24             ::univer::KeyCode::F24
#define UVR_KEY_F25             ::univer::KeyCode::F25

/* Keypad */
#define UVR_KEY_KP_0            ::univer::KeyCode::KP0
#define UVR_KEY_KP_1            ::univer::KeyCode::KP1
#define UVR_KEY_KP_2            ::univer::KeyCode::KP2
#define UVR_KEY_KP_3            ::univer::KeyCode::KP3
#define UVR_KEY_KP_4            ::univer::KeyCode::KP4
#define UVR_KEY_KP_5            ::univer::KeyCode::KP5
#define UVR_KEY_KP_6            ::univer::KeyCode::KP6
#define UVR_KEY_KP_7            ::univer::KeyCode::KP7
#define UVR_KEY_KP_8            ::univer::KeyCode::KP8
#define UVR_KEY_KP_9            ::univer::KeyCode::KP9
#define UVR_KEY_KP_DECIMAL      ::univer::KeyCode::KPDecimal
#define UVR_KEY_KP_DIVIDE       ::univer::KeyCode::KPDivide
#define UVR_KEY_KP_MULTIPLY     ::univer::KeyCode::KPMultiply
#define UVR_KEY_KP_SUBTRACT     ::univer::KeyCode::KPSubtract
#define UVR_KEY_KP_ADD          ::univer::KeyCode::KPAdd
#define UVR_KEY_KP_ENTER        ::univer::KeyCode::KPEnter
#define UVR_KEY_KP_EQUAL        ::univer::KeyCode::KPEqual

#define UVR_KEY_LEFT_SHIFT      ::univer::KeyCode::LeftShift
#define UVR_KEY_LEFT_CONTROL    ::univer::KeyCode::LeftControl
#define UVR_KEY_LEFT_ALT        ::univer::KeyCode::LeftAlt
#define UVR_KEY_LEFT_SUPER      ::univer::KeyCode::LeftSuper
#define UVR_KEY_RIGHT_SHIFT     ::univer::KeyCode::RightShift
#define UVR_KEY_RIGHT_CONTROL   ::univer::KeyCode::RightControl
#define UVR_KEY_RIGHT_ALT       ::univer::KeyCode::RightAlt
#define UVR_KEY_RIGHT_SUPER     ::univer::KeyCode::RightSuper
#define UVR_KEY_MENU            ::univer::KeyCode::Menu

#endif // !KEYCODES_H_