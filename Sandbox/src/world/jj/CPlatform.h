#pragma once

#include <vector>

#include "world/component/Component.h"

class Hole;
class Enemy;

class CPlatform : public Component
{
	void createHole( float speedX, int platformLevel );
	void createEnemy( float speedX, int platformLevel );

public:
	void update( float dt ) override;

private:
	float m_time = 0.f;
	float m_timeEnemies = 0.f;

	std::vector<std::weak_ptr<Hole>> m_holes;
	std::vector<std::weak_ptr<Enemy>> m_enemies;

	ADD_PROPERTY( float, probFirstHole )
	ADD_PROPERTY( float, probSecondHole )
	ADD_PROPERTY( float, evaluationTime )
	ADD_PROPERTY( int, level )

	ADD_PROPERTY( float, evaluationTimeEnemy )
	ADD_PROPERTY( float, probEnemy )
};
