// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// KeyEvent.h                                                                //
// ========================================================================= //

#pragma once

#include "univer/events/Event.h"
#include "univer/constants/KeyCodes.h"

#include <sstream>

namespace univer
{
class KeyEvent : public Event
{
public:
	inline KeyCode GetKeyCode() const { return m_keyCode; }

	EVENT_CLASS_CATEGORY( EventCategory::KEYBOARD | EventCategory::INPUT )
protected:
	KeyEvent( KeyCode keycode ) : m_keyCode( keycode ) {}

	KeyCode m_keyCode;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent( KeyCode keycode, int repeatCount ) :
		KeyEvent( keycode ), m_repeatCount( repeatCount ) {}

	inline int GetRepeatCount() const { return m_repeatCount; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyPressed )
private:
	int m_repeatCount;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent( KeyCode keycode ) : KeyEvent( keycode ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyReleased )
};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent( KeyCode keycode ) : KeyEvent( keycode )
	{
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyTyped )
};
}