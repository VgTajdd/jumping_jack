#pragma once

#include <memory>

class Actor;

// Use macro at the end of the class.
#define ADD_PROPERTY( type, var )     \
public:                               \
	const type& var() const           \
	{                                 \
		return m_##var;               \
	}                                 \
	void set_##var( const type& var ) \
	{                                 \
		m_##var = var;                \
	}                                 \
                                      \
private:                              \
	type m_##var;

#define GET_COMPONENT_INSTANCE( Type ) actor().lock()->getComponent<Type>()

// Generic class for components.
class Component
{
public:
	virtual ~Component(){};
	virtual void update( float dt ){};
	ADD_PROPERTY( std::weak_ptr<Actor>, actor )
};
