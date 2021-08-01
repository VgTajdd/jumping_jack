#pragma once

#include <memory>
#include <vector>

#include "world/components/Component.h"

class World;

// Generic class for actors in the world.
class Actor
{
public:
	// Use this method to create components.
	virtual void init(){};

	// Update components.
	virtual void update( float dt ){};

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
		return std::dynamic_pointer_cast<T>( v );
	}

private:
	std::vector<std::shared_ptr<Component>> m_components;
};
