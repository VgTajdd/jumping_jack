#pragma once

#include <univer/core/LayerContext.h>

class GameContext : public univer::LayerContext
{
public:
	explicit GameContext();
	~GameContext();

	void init( univer::Layer* layer ) override;
	void clear( univer::Layer* layer ) override;
	void update( univer::Layer* layer, const univer::Timestep& ts ) override;
};