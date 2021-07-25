// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// ICamera.h                                                                 //
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
class UVec2;
class UVec3;

class ICamera
{
public:
	virtual ~ICamera() {}

	virtual void setPosition( const UVec3& position ) = 0;
	virtual const UVec3& position() const = 0;

	virtual void setWindowSize( float width, float height ) = 0;
	virtual void fromScreenToWorld( const UVec2& posInScreen, UVec3& posInWorld ) = 0;

	virtual void update( const Timestep& ts ) = 0;

	virtual bool onMouseMovedEvent( MouseMovedEvent& e ) = 0;
	virtual bool onMouseScrolledEvent( MouseScrolledEvent& e ) = 0;
	virtual bool onMouseButtonPressedEvent( MouseButtonPressedEvent& e ) = 0;
	virtual bool onMouseButtonReleasedEvent( MouseButtonReleasedEvent& e ) = 0;
	virtual bool onKeyPressedEvent( KeyPressedEvent& e ) = 0;
	virtual bool onKeyReleasedEvent( KeyReleasedEvent& e ) = 0;
	virtual bool onKeyTypedEvent( KeyTypedEvent& e ) = 0;
	virtual bool onWindowResize( WindowResizeEvent& e ) = 0;
};

class ICamera2D : public ICamera
{
public:
	virtual ~ICamera2D() {}
	virtual void setProjection( float left, float right, float bottom, float top ) = 0;
	virtual void setRotation( float rotation ) = 0;
	virtual void setZoomLevel( float level ) = 0;
	virtual void setAspectRatio( float aspect ) = 0;
	virtual float rotation() const = 0;
	virtual float zoomLevel() const = 0;
	virtual float aspectRatio() const = 0;
};
}