#pragma once

namespace univer
{
class Sprite;
}
enum class SCENE_TYPE;

class Scene
{
public:
	virtual ~Scene(){};
	virtual void init() = 0;
	virtual void update( float dt ) = 0;
	void setCanvas( univer::Sprite* canvas );

protected:
	univer::Sprite* m_canvas;
	SCENE_TYPE m_type;
};

inline void Scene::setCanvas( univer::Sprite* canvas )
{
	m_canvas = canvas;
}