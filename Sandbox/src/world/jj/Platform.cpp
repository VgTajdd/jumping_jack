#include "Platform.h"
#include "CPlatform.h"
#include "data/Constants.h"
#include "world/component/CCollision.h"
#include "world/component/CDynamicSkin2.h"
#include "world/component/CPosition.h"

#include <univer/utils/Random.h>

void Platform::init()
{
	auto& p{ addComponent<CPlatform>() };
	auto& position{ addComponent<CPosition>() };
	auto& skin{ addComponent<CDynamicSkin2>() };
	auto& collision{ addComponent<CCollision>() };

	float randomValue{ univer::Random::GetInstance().value() };
	p->set_evaluationTime( 1.f + randomValue );
	p->set_probFirstHole( 0.5f );
	p->set_probSecondHole( 0.15f );
	p->set_level( m_level );
	p->set_evaluationTimeEnemy( 3.f + randomValue );
	p->set_probEnemy( .1f );
	position->set_y( (float)constants::getPlatformHeight( m_level ) );
	position->set_x( constants::SCREEN_WIDTH / 2 );
	skin->set_color( { 0.3f, 0.3f, 1.f, 1.f } );
	skin->set_color2( { 1.f, 0.3f, 0.3f, 1.f } );
	skin->set_period( 1.f );
	skin->set_size( { constants::SCREEN_WIDTH, 5 } );
	skin->reset();
	collision->set_bounds( univer::URectangle( { 0, position->y() - 10 }, { constants::SCREEN_WIDTH, 10 } ) );
}
