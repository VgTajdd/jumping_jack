#include "core/GameContext.h"

#include <Univer.h>
#include <univer/core/Application.h>
#include <univer/core/EntryPoint.h>

class Game : public univer::Application
{
public:
	explicit Game()
		: univer::Application( "Game" )
	{
		univer::AssetManager::GetInstance().loadAssetGroup( "sandbox" );

		SET_CLIENT_LOG_VERBOSITY( ::univer::VERBOSITY_LEVEL::L_INFO );
		SET_CORE_LOG_VERBOSITY( ::univer::VERBOSITY_LEVEL::L_INFO );

		auto layer = createLayer( univer::LayerType::LAYER_2D );
		layer->setContext( new GameContext() );
		pushLayer( layer );
	}
};

univer::Application* univer::createApplication()
{
	return new Game();
}
