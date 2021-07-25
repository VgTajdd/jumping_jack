// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// MouseEvent.h                                                              //
// ========================================================================= //

#pragma once

#include "univer/events/Event.h"
#include "univer/constants/MouseCodes.h"

#include <sstream>

namespace univer
{
class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent( float x, float y ) :
		m_mouseX( x ),
		m_mouseY( y ) {}

	inline float GetX() const { return m_mouseX; }
	inline float GetY() const { return m_mouseY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE( MouseMoved )
	EVENT_CLASS_CATEGORY( EventCategory::MOUSE | EventCategory::INPUT )
private:
	float m_mouseX;
	float m_mouseY;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent( float xOffset, float yOffset ) :
		m_xOffset( xOffset ),
		m_yOffset( yOffset ) {}

	inline float GetXOffset() const { return m_xOffset; }
	inline float GetYOffset() const { return m_yOffset; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	EVENT_CLASS_TYPE( MouseScrolled )
	EVENT_CLASS_CATEGORY( EventCategory::MOUSE | EventCategory::INPUT )
private:
	float m_xOffset;
	float m_yOffset;
};

class MouseButtonEvent : public Event
{
public:
	inline MouseCode GetMouseButton() const { return m_button; }

	EVENT_CLASS_CATEGORY( EventCategory::MOUSE | EventCategory::INPUT )
protected:
	MouseButtonEvent( MouseCode button ) : m_button( button ) {}

	MouseCode m_button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent( MouseCode button ) : MouseButtonEvent( button ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_button;
		return ss.str();
	}

	EVENT_CLASS_TYPE( MouseButtonPressed )
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent( MouseCode button ) : MouseButtonEvent( button ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_button;
		return ss.str();
	}

	EVENT_CLASS_TYPE( MouseButtonReleased )
};

}