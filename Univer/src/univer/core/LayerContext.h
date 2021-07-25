// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// LayerContext.h                                                            //
// ========================================================================= //

#ifndef LAYER_CONTEXT_H_
#define LAYER_CONTEXT_H_

#include "univer/core/UDefines.h"

namespace univer { class Timestep; }
namespace univer { class MouseMovedEvent; }
namespace univer { class MouseScrolledEvent; }
namespace univer { class MouseButtonPressedEvent; }
namespace univer { class MouseButtonReleasedEvent; }
namespace univer { class KeyPressedEvent; }
namespace univer { class KeyReleasedEvent; }
namespace univer { class KeyTypedEvent; }
namespace univer { class WindowResizeEvent; }
namespace univer { class Layer; }

namespace univer
{
class UVR_API LayerContext
{
public:
	virtual ~LayerContext() {}
	virtual void update( Layer* layer, const Timestep& ts ) {}
	virtual void init( Layer* layer ) {}
	virtual void clear( Layer* layer ) {}
	virtual void onMouseMovedEvent( Layer* layer, MouseMovedEvent& e ) {};
	virtual void onMouseScrolledEvent( Layer* layer, MouseScrolledEvent& e ) {}
	virtual void onMouseButtonPressedEvent( Layer* layer, MouseButtonPressedEvent& e ) {}
	virtual void onMouseButtonReleasedEvent( Layer* layer, MouseButtonReleasedEvent& e ) {}
	virtual void onKeyPressedEvent( Layer* layer, KeyPressedEvent& e ) {}
	virtual void onKeyReleasedEvent( Layer* layer, KeyReleasedEvent& e ) {}
	virtual void onKeyTypedEvent( Layer* layer, KeyTypedEvent& e ) {}
	virtual void onWindowResize( Layer* layer, WindowResizeEvent& e ) {}
};
}

#endif // !LAYER_CONTEXT_H_