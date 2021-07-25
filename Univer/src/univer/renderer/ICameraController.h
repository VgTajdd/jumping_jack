// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// ICameraController.h                                                       //
// ========================================================================= //

#pragma once

namespace univer
{
class MouseMovedEvent;
class MouseScrolledEvent;
class MouseButtonPressedEvent;
class MouseButtonReleasedEvent;
class KeyPressedEvent;
class KeyReleasedEvent;
class KeyTypedEvent;
class WindowResizeEvent;
class Timestep;
class ICamera;

class ICameraController
{
public:
	virtual ~ICameraController() {}

	virtual void update( const Timestep& ts ) = 0;
	virtual void setCameraRef( ICamera* camera ) = 0;

	virtual bool onMouseMovedEvent( MouseMovedEvent& e ) = 0;
	virtual bool onMouseScrolledEvent( MouseScrolledEvent& e ) = 0;
	virtual bool onMouseButtonPressedEvent( MouseButtonPressedEvent& e ) = 0;
	virtual bool onMouseButtonReleasedEvent( MouseButtonReleasedEvent& e ) = 0;
	virtual bool onKeyPressedEvent( KeyPressedEvent& e ) = 0;
	virtual bool onKeyReleasedEvent( KeyReleasedEvent& e ) = 0;
	virtual bool onKeyTypedEvent( KeyTypedEvent& e ) = 0;
	virtual bool onWindowResize( WindowResizeEvent& e ) = 0;
};
}