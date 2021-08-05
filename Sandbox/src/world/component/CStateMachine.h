#pragma once

#include "Component.h"
#include "data/Constants.h"

#include <functional>
#include <map>
#include <vector>

// Abstract class that implements a state machine system.
class CStateMachine : public Component
{
public:
	struct Edge
	{
		int initialState;
		int finalState;
		std::function<bool( void )> condition;
		std::function<void( void )> action;
	};

private:
	virtual void evaluateEdges()
	{
		if ( !areThereEdges( m_state ) ) return;
		const auto& conditions{ getEdges( m_state ) };
		for ( const auto& [initialState, finalState, condition, action] : conditions )
		{
			if ( condition() )
			{
				set_state( finalState );
				action();
				break;
			}
		}
	}
	bool areThereEdges( int initialState ) const
	{
		return m_edges.find( initialState ) != m_edges.end();
	}
	const std::vector<Edge>& getEdges( int initialState ) const
	{
		return m_edges.at( initialState );
	}

public:
	void update( float dt )
	{
		evaluateEdges();
	}
	void addEdge( int initialState, int finalState, const std::function<bool( void )>& condition,
				  const std::function<void( void )>& coaction )
	{
		m_edges[initialState].push_back( { initialState, finalState, condition, coaction } );
	}

public:
	virtual void init() = 0;

private:
	std::map<int, std::vector<Edge>> m_edges;
	ADD_PROPERTY( int, state )
};
