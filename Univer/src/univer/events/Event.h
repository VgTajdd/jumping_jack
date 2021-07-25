// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Event.h                                                                   //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

#include <string>

namespace univer
{
// Events are currently blocking, meaning when an event occurs it
// immediately gets dispatched and must be dealt with right then an there.
// For the future, a better strategy might be to buffer events in an event
// bus and process them during the "event" part of the update stage.

enum class EventType
{
	None,
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,

	AppTick,
	AppUpdate,
	AppRender,

	KeyPressed,
	KeyReleased,
	KeyTyped,

	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

class EventCategory
{
public:
	const static int NONE			= 0;
	const static int APPLICATION	= BIT( 0 );
	const static int INPUT			= BIT( 1 );
	const static int KEYBOARD		= BIT( 2 );
	const static int MOUSE			= BIT( 3 );
	const static int MOUSE_BUTTON	= BIT( 4 );
};

#define EVENT_CLASS_TYPE(type)			static EventType GetStaticType() { return CONCAT( EventType::, type ); }\
										virtual EventType GetEventType() const override { return GetStaticType(); }\
										virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)	virtual int GetCategoryFlags() const override { return category; }

class UVR_API Event
{
friend class EventDispatcher;
public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int GetCategoryFlags() const = 0;
	virtual std::string ToString() const { return GetName(); }
	virtual const bool handled() const { return m_handled; }
	virtual void setHandled( const bool handled ) { m_handled = handled; };
	bool IsInCategory( int category )
	{
		return GetCategoryFlags() & category;
	}
protected:
	bool m_handled = false;
};

class EventDispatcher
{
public:
	EventDispatcher( Event& event ) :
		m_event( event )
	{ }

	template<typename T, typename F>
	bool Dispatch( const F& func )
	{
		if ( m_event.GetEventType() == T::GetStaticType() )
		{
			m_event.m_handled = func( static_cast<T&>( m_event ) );
			return true;
		}
		return false;
	}
private:
	Event& m_event;
};

#define DISPATCH_TO_CALLBACK(dispatcher,method,T) 		{auto callback = [this]( T& e ) { return this->method( e ); };\
														dispatcher.Dispatch<T>( callback );}

/*
This method is to use this: 'std::cout << e';
*/
/*inline std::ostream& operator<<( std::ostream& os, const Event& e )
{
	return os << e.ToString();
}*/
}