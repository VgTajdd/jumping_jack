#include "Platform.h"
#include "CPlatform.h"
#include "data/Constants.h"
#include "world/component/CCollision.h"
#include "world/component/CPosition.h"
#include "world/component/CSkin.h"

#include <univer/utils/Random.h>

void Platform::init()
{
	auto& p{ addComponent<CPlatform>() };
	auto& position{ addComponent<CPosition>() };
	auto& skin{ addComponent<CSkin>() };
	auto& collision{ addComponent<CCollision>() };

	float randomValue{ univer::Random::GetInstance().value() };
	p->set_evaluationTime( 1.f + randomValue );
	p->set_probFirstHole( 0.3f );
	p->set_probSecondHole( 0.15f );
	p->set_level( m_level );
	position->set_y( (float)constants::getPlatformHeight( m_level ) );
	position->set_x( constants::SCREEN_WIDTH / 2 );
	skin->set_color( { 0.5, 0.5, 0.5, 1 } );
	skin->set_size( { constants::SCREEN_WIDTH, 5 } );
	skin->reset();
	collision->set_bounds( univer::URectangle( { 0, position->y() - 10 }, { constants::SCREEN_WIDTH, 10 } ) );
}