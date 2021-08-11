// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// SceneFactory.h                                                            //
// ========================================================================= //

#pragma once

class Scene;
enum class SCENE_TYPE;

namespace scene_factory
{
Scene* Create( SCENE_TYPE type );
}
