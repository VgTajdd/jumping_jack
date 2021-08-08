#include "JJWorld.h"
#include "Platform.h"
#include "data/Constants.h"
#include "data/Stats.h"

#include <univer/renderables/2d/Sprite.h>

void JJWorld::init()
{
	World::init();

	for ( int i = 1; i <= 8; i++ )
	{
		addActor( std::move( std::make_shared<Platform>( i ) ) );
	}

	canvas()->setColor( constants::getLevelColor( stats::Stats::LEVEL ) );
}
