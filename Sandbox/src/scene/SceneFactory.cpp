#include "SceneFactory.h"
#include "GameScene.h"
#include "MainMenu.h"
#include "SceneType.h"

#include <univer/core/Log.h>

Scene* scene_factory::Create( SCENE_TYPE type )
{
	Scene* scene = nullptr;
	switch ( type )
	{
		case SCENE_TYPE::MAIN_MENU:
			scene = new MainMenu();
			break;
		case SCENE_TYPE::GAME:
			scene = new GameScene();
			break;
		/* case SCENE_TYPE::WIN_GAME:
			scene = new WinGame();
			break;*/
		default:
			UVR_ERROR( "Scene type not supported." );
			break;
	}
	return scene;
}
