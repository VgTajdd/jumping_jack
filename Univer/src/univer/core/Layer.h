// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Layer.h                                                                   //
// ========================================================================= //

#ifndef LAYER_H_
#define LAYER_H_

#include "univer/core/UDefines.h"

namespace univer
{
class Event;
class Timestep;
class MouseMovedEvent;
class MouseScrolledEvent;
class MouseButtonPressedEvent;
class MouseButtonReleasedEvent;
class KeyPressedEvent;
class KeyReleasedEvent;
class KeyTypedEvent;
class WindowResizeEvent;
class LayerContext;
class UVec2;
class UVec3;
class Renderable;
class ICamera;
class IRenderer;

enum class UVR_API LayerType
{
	LAYER_2D,
	LAYER_3D
};

class UVR_API Layer
{
public:
	explicit Layer( const char* name );
	virtual ~Layer();

	virtual void onInit();
	virtual void onEnd();
	virtual void onUpdate( const Timestep& ts );
	virtual void onEvent( Event& event );

	virtual void setMouseEventsEnabled( const bool enable ) { m_mouseEventsEnabled = enable; }
	virtual void setKeyboardEventsEnabled( const bool enable ) { m_keyboardEventsEnabled = enable; }

	virtual bool onMouseMovedEvent( MouseMovedEvent& e );
	virtual bool onMouseScrolledEvent( MouseScrolledEvent& e );
	virtual bool onMouseButtonPressedEvent( MouseButtonPressedEvent& e );
	virtual bool onMouseButtonReleasedEvent( MouseButtonReleasedEvent& e );

	virtual bool onKeyPressedEvent( KeyPressedEvent& e );
	virtual bool onKeyReleasedEvent( KeyReleasedEvent& e );
	virtual bool onKeyTypedEvent( KeyTypedEvent& e );

	virtual bool onWindowResize( WindowResizeEvent& e );

	const char* debugName() const { return m_debugName; }

	bool keyboardEventsEnabled() const { return m_keyboardEventsEnabled; }
	bool mouseEventsEnabled() const { return m_mouseEventsEnabled; }

	void setContext( LayerContext* context );

	virtual void fromScreenToWorld( const UVec2& posInScreen, UVec3& posInWorld );

	virtual void add( Renderable* renderable ) = 0;
	virtual void remove( Renderable* renderable ) = 0;

private:
	const char* m_debugName;
	bool m_mouseEventsEnabled;
	bool m_keyboardEventsEnabled;
protected:
	LayerContext* m_context;
	ICamera* m_camera;
	IRenderer* m_renderer;
};
}
#endif // !LAYER_H_