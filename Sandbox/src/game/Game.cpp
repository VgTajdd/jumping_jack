#include <Univer.h>
#include <univer/core/EntryPoint.h>
#include <univer/core/Application.h>

class Game : public univer::Application
{
public:
	explicit Game() : univer::Application( "Game" )
	{
		SET_CLIENT_LOG_VERBOSITY( ::univer::VERBOSITY_LEVEL::L_INFO );
		SET_CORE_LOG_VERBOSITY( ::univer::VERBOSITY_LEVEL::L_INFO );
	}
};

univer::Application* univer::createApplication()
{
	return new Game();
}