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

#define DEFINE_GET_COMPONENT_INSTANCE( Type )                              \
	static std::shared_ptr<Type> get##Type( const std::shared_ptr<Actor>& actor ) \
	{                                                                      \
		static std::shared_ptr<Type> instance;                             \
		if ( instance.get() == nullptr )                                   \
		{                                                                  \
			instance = actor->getComponent<Type>();                        \
		}                                                                  \
		return instance;                                                   \
	}

#define GET_COMPONENT_INSTANCE( Type ) get##Type( actor() )

class Component
{
public:
	virtual ~Component(){};
	virtual void update( float dt ){};
	ADD_PROPERTY( std::shared_ptr<Actor>, actor )
};
