// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// MouseCodes.h                                                              //
// ========================================================================= //

#ifndef MOUSECODES_H_
#define MOUSECODES_H_

#include <ostream>

namespace univer
{
enum class MouseCode : unsigned short
{
	// From glfw3.h
	Button0                = 0,
	Button1                = 1,
	Button2                = 2,
	Button3                = 3,
	Button4                = 4,
	Button5                = 5,
	Button6                = 6,
	Button7                = 7,

	ButtonLast             = Button7,
	ButtonLeft             = Button0,
	ButtonRight            = Button1,
	ButtonMiddle           = Button2
};

inline std::ostream& operator<<( std::ostream& os, MouseCode mouseCode )
{
	os << static_cast<int32_t>( mouseCode );
	return os;
}
}

#define UVR_MOUSE_BUTTON_0      ::univer::MouseCode::Button0
#define UVR_MOUSE_BUTTON_1      ::univer::MouseCode::Button1
#define UVR_MOUSE_BUTTON_2      ::univer::MouseCode::Button2
#define UVR_MOUSE_BUTTON_3      ::univer::MouseCode::Button3
#define UVR_MOUSE_BUTTON_4      ::univer::MouseCode::Button4
#define UVR_MOUSE_BUTTON_5      ::univer::MouseCode::Button5
#define UVR_MOUSE_BUTTON_6      ::univer::MouseCode::Button6
#define UVR_MOUSE_BUTTON_7      ::univer::MouseCode::Button7
#define UVR_MOUSE_BUTTON_LAST   ::univer::MouseCode::ButtonLast
#define UVR_MOUSE_BUTTON_LEFT   ::univer::MouseCode::ButtonLeft
#define UVR_MOUSE_BUTTON_RIGHT  ::univer::MouseCode::ButtonRight
#define UVR_MOUSE_BUTTON_MIDDLE ::univer::MouseCode::ButtonMiddle

#endif // !MOUSECODES_H_