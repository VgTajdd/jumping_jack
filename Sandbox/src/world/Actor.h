#pragma once

#include <algorithm>
#include <vector>

#include "world/component/Component.h"

class World;

// Generic class for actors in the world.
class Actor : public std::enable_shared_from_this<Actor>
{
	// Update components.
	void updateComponents( float dt )
	{
		std::for_each( m_components.begin(), m_components.end(),
					   [dt]( const auto& component ) { component->update( dt ); } );
	}

public:
	// Destructor.
	virtual ~Actor(){};

	// Use this function to create components (override).
	virtual void init(){};

	// Override this function only if it's necessary.
	virtual void update( float dt )
	{
		updateComponents( dt );
	}

	void clearComponents()
	{
		m_components.clear();
	}

	void setWorld( const std::weak_ptr<World>& world )
	{
		m_world = world;
	}

	const std::weak_ptr<World>& world() const
	{
		return m_world;
	}

	bool valid() const
	{
		return m_valid;
	}

	void setValid( bool valid )
	{
		m_valid = valid;
	}

	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> ans;
		auto& it = std::find_if( m_components.begin(), m_components.end(), [&ans]( std::shared_ptr<Component>& comp ) {
			auto sp = std::dynamic_pointer_cast<T>( comp );
			if ( sp.get() != nullptr ) ans = sp;
			return sp.get() != nullptr;
		} );
		return ans;
	}

	template <typename T, class... Args>
	std::shared_ptr<T> addComponent( Args&&... args )
	{
		auto v = m_components.emplace_back( std::move( std::make_shared<T>( args... ) ) );
		v->set_actor( shared_from_this() );
		return std::dynamic_pointer_cast<T>( v );
	}

private:
	std::weak_ptr<World> m_world;
	std::vector<std::shared_ptr<Component>> m_components;
	bool m_valid = true;
};
