// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Application.h                                                             //
// ========================================================================= //

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "univer/core/UDefines.h"

namespace univer { class Window; }
namespace univer { class Event; }
namespace univer { class Layer; }
namespace univer { enum class LayerType; }
namespace univer { class ApplicationImpl; }
namespace univer { namespace ui { class UIManager; } }

namespace univer
{
class UVR_API Application
{
public:
	explicit Application( const char* appName );
	virtual ~Application();
	void run();
	void onEvent( Event& e );
	void pushLayer( Layer* layer );
	void popLayer( Layer* layer, bool deleteLayer );
	Layer* createLayer( const LayerType& type );
	const Window* window() const;
#ifdef UVR_UI
	ui::UIManager* const UI();
#endif
	virtual void update( float dt ) {};

private:
	ApplicationImpl* m_pimpl;
};
Application* createApplication();
}

#endif // !APPLICATION_H_