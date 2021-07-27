#pragma once

class Scene;
enum class SCENE_TYPE;

namespace scene_factory
{
Scene* Create( SCENE_TYPE type );
}
