// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// ApplicationEvent.h                                                        //
// ========================================================================= //

#pragma once

#include "Event.h"

#include <sstream>

namespace univer
{
class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent( unsigned int width, unsigned int height ) :
		m_width( width ),
		m_height( height ) {}

	inline unsigned int GetWidth() const { return m_width; }
	inline unsigned int GetHeight() const { return m_height; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << ", " << m_height;
		return ss.str();
	}

	EVENT_CLASS_TYPE( WindowResize )
	EVENT_CLASS_CATEGORY( EventCategory::APPLICATION )
private:
	unsigned int m_width, m_height;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() {}

	EVENT_CLASS_TYPE( WindowClose )
	EVENT_CLASS_CATEGORY( EventCategory::APPLICATION )
};

class AppTickEvent : public Event
{
public:
	AppTickEvent() {}

	EVENT_CLASS_TYPE( AppTick )
	EVENT_CLASS_CATEGORY( EventCategory::APPLICATION )
};

class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() {}

	EVENT_CLASS_TYPE( AppUpdate )
	EVENT_CLASS_CATEGORY( EventCategory::APPLICATION )
};

class AppRenderEvent : public Event
{
public:
	AppRenderEvent() {}

	EVENT_CLASS_TYPE( AppRender )
	EVENT_CLASS_CATEGORY( EventCategory::APPLICATION )
};
}