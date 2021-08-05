#pragma once

#include "Component.h"
#include "data/Constants.h"

#include <functional>
#include <map>
#include <vector>

struct StateTransition
{
	int finalState;
	std::function<bool( void )> condition;
	std::function<void( void )> action;
};

// Abstract class that implements a state machine system.
class CStateMachine : public Component
{
	virtual void evaluateConditions()
	{
		if ( !existConditions( m_state ) ) return;
		const auto& conditions{ getConditions( m_state ) };
		for ( const auto& [finalState, condition, action] : conditions )
		{
			if ( condition() )
			{
				set_state( finalState );
				action();
				break;
			}
		}
	}
	bool existConditions( int initialState ) const
	{
		return m_conditions.find( initialState ) != m_conditions.end();
	}
	const std::vector<StateTransition>& getConditions( int initialState ) const
	{
		return m_conditions.at( initialState );
	}

public:
	void update( float dt )
	{
		evaluateConditions();
	}
	void addCondition( int initialState, int finalState, const std::function<bool( void )>& condition,
					   const std::function<void( void )>& coaction )
	{
		m_conditions[initialState].push_back( { finalState, condition, coaction } );
	}

public:
	virtual void init() = 0;

private:
	std::map<int, std::vector<StateTransition>> m_conditions;
	ADD_PROPERTY( int, state )
};
