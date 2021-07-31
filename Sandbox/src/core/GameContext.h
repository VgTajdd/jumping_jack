#pragma once

#include <univer/core/LayerContext.h>

namespace univer
{
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

class GameContext : public univer::LayerContext
{
public:
	explicit GameContext();
	~GameContext();

	void init( univer::Layer* layer ) override;
	void clear( univer::Layer* layer ) override;
	void update( univer::Layer* layer, const univer::Timestep& ts ) override;
	void onKeyPressedEvent( univer::Layer* layer, univer::KeyPressedEvent& e ) override;
	void onKeyReleasedEvent( univer::Layer* layer, univer::KeyReleasedEvent& e ) override;
};