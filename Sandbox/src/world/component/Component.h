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

class Component
{
public:
	virtual ~Component(){};
	ADD_PROPERTY( std::shared_ptr<Actor>, actor )
};
