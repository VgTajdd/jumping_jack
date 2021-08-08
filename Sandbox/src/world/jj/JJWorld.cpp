#include "JJWorld.h"
#include "Platform.h"

void JJWorld::init()
{
	World::init();

	for ( int i = 1; i <= 8; i++ )
	{
		addActor( std::move( std::make_shared<Platform>( i ) ) );
	}
}
